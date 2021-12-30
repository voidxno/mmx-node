/*
 * Wallet.cpp
 *
 *  Created on: Dec 11, 2021
 *      Author: mad
 */

#include <mmx/Wallet.h>
#include <mmx/utxo_t.hpp>
#include <mmx/utxo_entry_t.hpp>
#include <mmx/stxo_entry_t.hpp>
#include <mmx/solution/PubKey.hxx>
#include <mmx/utils.h>

#include <vnx/vnx.h>
#include <algorithm>


namespace mmx {

Wallet::Wallet(const std::string& _vnx_name)
	:	WalletBase(_vnx_name)
{
}

void Wallet::init()
{
	vnx::open_pipe(vnx_name, this, 1000);
}

void Wallet::main()
{
	params = get_params();

	http = std::make_shared<vnx::addons::HttpInterface<Wallet>>(this, vnx_name);
	add_async_client(http);

	for(const auto& file_path : key_files)
	{
		if(auto key_file = vnx::read_from_file<KeyFile>(file_path))
		{
			bls_wallets.push_back(std::make_shared<BLS_Wallet>(key_file, 11337));
		}
		else {
			bls_wallets.push_back(nullptr);
			log(ERROR) << "Failed to read wallet '" << file_path << "'";
		}
	}

	open_wallet(default_wallet, "");

	node = std::make_shared<NodeClient>(node_server);

	Super::main();
}

void Wallet::open_wallet(const uint32_t& index, const std::string& passwd)
{
	if(wallet_index == index) {
		return;
	}
	open_wallet_ex(index, num_addresses, passwd);
}

void Wallet::open_wallet_ex(const uint32_t& index, const uint32_t& num_addresses, const std::string& passwd)
{
	if(index >= key_files.size()) {
		throw std::logic_error("invalid wallet index");
	}
	close_wallet();

	if(auto key_file = vnx::read_from_file<KeyFile>(key_files[index]))
	{
		wallet = std::make_shared<ECDSA_Wallet>(key_file, num_addresses);
		wallet_index = index;
		log(INFO) << "Loaded wallet '" << key_files[index] << "' with " << num_addresses << " addresses";
	}
	else {
		throw std::runtime_error("failed to open wallet file");
	}
}

void Wallet::close_wallet()
{
	wallet = nullptr;
	wallet_index = -1;
	utxo_cache.clear();
	utxo_change_cache.clear();
	last_utxo_update = 0;
}

static
uint64_t gather_inputs(	std::shared_ptr<Transaction> tx,
						std::unordered_set<txio_key_t>& spent_txo,
						const std::vector<utxo_entry_t>& utxo_list,
						uint64_t amount, const addr_t& contract)
{
	uint64_t change = 0;
	for(const auto& entry : utxo_list)
	{
		if(amount == 0) {
			break;
		}
		const auto& out = entry.output;
		if(out.contract != contract) {
			continue;
		}
		const auto& key = entry.key;
		if(spent_txo.count(key)) {
			continue;
		}
		if(out.amount > amount) {
			change += out.amount - amount;
			amount = 0;
		} else {
			amount -= out.amount;
		}
		tx_in_t in;
		in.prev = key;
		tx->inputs.push_back(in);
		spent_txo.insert(key);
	}
	if(amount != 0) {
		throw std::logic_error("not enough funds");
	}
	return change;
}

hash_t Wallet::send(const uint64_t& amount, const addr_t& dst_addr, const addr_t& contract) const
{
	if(!wallet) {
		throw std::logic_error("no wallet open");
	}
	if(amount == 0) {
		throw std::logic_error("amount cannot be zero");
	}

	// get a list of all utxo we could use
	auto utxo_list = get_utxo_list();

	// create lookup map
	std::unordered_map<txio_key_t, addr_t> addr_map;
	for(const auto& entry : utxo_list) {
		addr_map[entry.key] = entry.output.address;
	}

	// sort by height, such as to use oldest coins first (which are more likely to be spend-able right now)
	std::sort(utxo_list.begin(), utxo_list.end(),
		[](const utxo_entry_t& lhs, const utxo_entry_t& rhs) -> bool {
			return lhs.output.height < rhs.output.height;
		});

	auto spent_txo = spent_txo_set;

	auto tx = Transaction::create();
	{
		// add primary output
		tx_out_t out;
		out.address = dst_addr;
		out.contract = contract;
		out.amount = amount;
		tx->outputs.push_back(out);
	}
	uint64_t change = gather_inputs(tx, spent_txo, utxo_list, amount, contract);

	if(contract != addr_t() && change > 0) {
		// token change cannot be used as tx fee
		tx_out_t out;
		out.address = wallet->get_address(0);
		out.contract = contract;
		out.amount = change;
		tx->outputs.push_back(out);
		change = 0;
	}

	// gather inputs for tx fee
	uint64_t tx_fees = 0;
	while(true) {
		// count number of solutions needed
		std::unordered_set<addr_t> used_addr;
		for(const auto& in : tx->inputs) {
			auto iter = addr_map.find(in.prev);
			if(iter == addr_map.end()) {
				throw std::logic_error("cannot sign input");
			}
			used_addr.insert(iter->second);
		}
		tx_fees = tx->calc_min_fee(params)
				+ params->min_txfee_io	// for change output
				+ used_addr.size() * params->min_txfee_sign;

		if(change > tx_fees) {
			// we got more than enough, add change output
			tx_out_t out;
			out.address = wallet->get_address(0);
			out.amount = change - tx_fees;
			tx->outputs.push_back(out);
			change = 0;
			break;
		}
		if(change == tx_fees) {
			// perfect match
			change = 0;
			break;
		}
		// gather more
		const auto left = tx_fees - change;
		change += gather_inputs(tx, spent_txo, utxo_list, left, addr_t());
		change += left;
	}
	tx->finalize();

	std::unordered_map<addr_t, uint32_t> solution_map;

	for(auto& in : tx->inputs)
	{
		// sign all inputs
		auto iter = addr_map.find(in.prev);
		if(iter == addr_map.end()) {
			throw std::logic_error("cannot sign input");
		}
		auto iter2 = solution_map.find(iter->second);
		if(iter2 != solution_map.end()) {
			// re-use solution
			in.solution = iter2->second;
			continue;
		}
		const auto& keys = wallet->get_keypair(iter->second);

		auto sol = solution::PubKey::create();
		sol->pubkey = keys.second;
		sol->signature = signature_t::sign(keys.first, tx->id);

		in.solution = tx->solutions.size();
		solution_map[iter->second] = in.solution;
		tx->solutions.push_back(sol);
	}
	node->add_transaction(tx);

	log(INFO) << "Sent " << amount << " with fee " << tx_fees << " / " << tx->calc_min_fee(params)
			<< " to " << dst_addr << " (" << tx->id << ")";

	// store used utxos
	spent_txo_set = spent_txo;

	// store change outputs
	for(size_t i = 0; i < tx->outputs.size(); ++i) {
		const auto& out = tx->outputs[i];
		if(wallet->find_address(out.address) >= 0) {
			const auto key = txio_key_t::create_ex(tx->id, i);
			utxo_change_cache[key] = out;
			utxo_cache.push_back(utxo_entry_t::create_ex(key, utxo_t::create_ex(out)));
		}
	}
	return tx->id;
}

std::vector<utxo_entry_t> Wallet::get_utxo_list() const
{
	if(!wallet) {
		throw std::logic_error("no wallet open");
	}
	const auto now = vnx::get_wall_time_millis();

	if(!last_utxo_update || now - last_utxo_update > utxo_timeout_ms)
	{
		const auto all_utxo = node->get_utxo_list(wallet->get_all_addresses());

		utxo_cache.clear();
		size_t num_spend_pending = 0;
		for(const auto& entry : all_utxo) {
			// remove any utxo we have already consumed
			if(!spent_txo_set.count(entry.key)) {
				utxo_cache.push_back(entry);
			} else {
				num_spend_pending++;
			}
			// remove confirmed change
			utxo_change_cache.erase(entry.key);
		}
		// add pending change outputs
		for(const auto& entry : utxo_change_cache) {
			utxo_cache.push_back(utxo_entry_t::create_ex(entry.first, utxo_t::create_ex(entry.second)));
		}
		last_utxo_update = now;

		log(INFO) << "Updated UTXO cache: " << utxo_cache.size() << " entries, "
				<< num_spend_pending << " pending spend, " << utxo_change_cache.size() << " pending change";
	}
	return utxo_cache;
}

std::vector<utxo_entry_t> Wallet::get_utxo_list_for(const addr_t& contract) const
{
	std::vector<utxo_entry_t> res;
	for(const auto& entry : get_utxo_list()) {
		if(entry.output.contract == contract) {
			res.push_back(entry);
		}
	}
	return res;
}

std::vector<stxo_entry_t> Wallet::get_stxo_list() const
{
	if(!wallet) {
		throw std::logic_error("no wallet open");
	}
	return node->get_stxo_list(wallet->get_all_addresses());
}

std::vector<stxo_entry_t> Wallet::get_stxo_list_for(const addr_t& contract) const
{
	std::vector<stxo_entry_t> res;
	for(const auto& entry : get_stxo_list()) {
		if(entry.output.contract == contract) {
			res.push_back(entry);
		}
	}
	return res;
}

std::vector<tx_entry_t> Wallet::get_history(const uint32_t& min_height) const
{
	if(!wallet) {
		throw std::logic_error("no wallet open");
	}
	return node->get_history_for(wallet->get_all_addresses(), min_height);
}

uint64_t Wallet::get_balance(const addr_t& contract) const
{
	uint64_t total = 0;
	for(const auto& entry : get_utxo_list()) {
		if(entry.output.contract == contract) {
			total += entry.output.amount;
		}
	}
	return total;
}

addr_t Wallet::get_address(const uint32_t& index) const
{
	if(!wallet) {
		throw std::logic_error("no wallet open");
	}
	return wallet->get_address(index);
}

void Wallet::show_farmer_keys(const uint32_t& index) const
{
	if(auto wallet = bls_wallets.at(index)) {
		if(auto keys = wallet->get_farmer_keys()) {
			std::stringstream ss;
			vnx::PrettyPrinter printer(ss);
			keys->accept(printer);
			log(INFO) << ss.str();
		}
	} else {
		log(ERROR) << "No such wallet";
	}
}

std::shared_ptr<const FarmerKeys> Wallet::get_farmer_keys(const uint32_t& index) const
{
	if(auto wallet = bls_wallets.at(index)) {
		return wallet->get_farmer_keys();
	}
	return nullptr;
}

std::vector<std::shared_ptr<const FarmerKeys>> Wallet::get_all_farmer_keys() const
{
	std::vector<std::shared_ptr<const FarmerKeys>> res;
	for(auto wallet : bls_wallets) {
		if(wallet) {
			res.push_back(wallet->get_farmer_keys());
		}
	}
	return res;
}

hash_t Wallet::get_master_seed(const uint32_t& index) const
{
	if(index >= key_files.size()) {
		throw std::logic_error("invalid wallet index");
	}
	if(auto key_file = vnx::read_from_file<KeyFile>(key_files[index])) {
		return key_file->seed_value;
	}
	throw std::logic_error("failed to read key file");
}

void Wallet::http_request_async(std::shared_ptr<const vnx::addons::HttpRequest> request, const std::string& sub_path,
								const vnx::request_id_t& request_id) const
{
	http->http_request(request, sub_path, request_id);
}

void Wallet::http_request_chunk_async(	std::shared_ptr<const vnx::addons::HttpRequest> request, const std::string& sub_path,
										const int64_t& offset, const int64_t& max_bytes, const vnx::request_id_t& request_id) const
{
	throw std::logic_error("not implemented");
}


} // mmx
