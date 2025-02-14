/*
 * Transaction.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: mad
 */

#include <mmx/Transaction.hxx>
#include <mmx/operation/Deposit.hxx>
#include <mmx/solution/PubKey.hxx>
#include <mmx/write_bytes.h>
#include <mmx/txio_t.hpp>


namespace mmx {

hash_t TransactionBase::calc_hash(const vnx::bool_t& full_hash) const {
	return id;
}

uint64_t TransactionBase::calc_cost(std::shared_ptr<const ChainParams> params) const {
	return 0;
}

std::shared_ptr<const TransactionBase> TransactionBase::create_ex(const hash_t& id)
{
	auto tx = TransactionBase::create();
	tx->id = id;
	return tx;
}

void Transaction::reset(std::shared_ptr<const ChainParams> params)
{
	exec_result = nullptr;
	static_cost = calc_cost(params);
	content_hash = calc_hash(true);
}

void Transaction::update(const exec_result_t& result, std::shared_ptr<const ChainParams> params)
{
	exec_result = result;
	static_cost = calc_cost(params);
	content_hash = calc_hash(true);
}

void Transaction::finalize()
{
	while(!nonce) {
		nonce = vnx::rand64();
	}
	id = calc_hash();
}

vnx::bool_t Transaction::is_valid(std::shared_ptr<const ChainParams> params) const
{
	if(!params) {
		throw std::logic_error("!params");
	}
	for(const auto& in : inputs) {
		if(in.memo && in.memo->size() > txio_t::MAX_MEMO_SIZE) {
			return false;
		}
	}
	for(const auto& out : outputs) {
		if(out.memo && out.memo->size() > txio_t::MAX_MEMO_SIZE) {
			return false;
		}
	}
	for(const auto& op : execute) {
		if(!op || !op->is_valid()) {
			return false;
		}
	}
	for(const auto& sol : solutions) {
		if(!sol || !sol->is_valid()) {
			return false;
		}
	}
	return version == 0 && nonce
			&& fee_ratio >= 1024
			&& network == params->network
			&& solutions.size() <= MAX_SOLUTIONS
			&& (!exec_result || exec_result->is_valid())
			&& static_cost == calc_cost(params)
			&& id == calc_hash()
			&& content_hash == calc_hash(true);
}

vnx::bool_t Transaction::did_fail() const
{
	if(!exec_result) {
		throw std::logic_error("tx not executed yet");
	}
	return exec_result->did_fail;
}

std::vector<uint8_t> Transaction::hash_serialize(const vnx::bool_t& full_hash) const
{
	std::vector<uint8_t> buffer;
	vnx::VectorOutputStream stream(&buffer);
	vnx::OutputBuffer out(&stream);

	buffer.reserve(4 * 1024);

	write_bytes(out, get_type_hash());
	write_field(out, "version", version);
	write_field(out, "expires", expires);
	write_field(out, "fee_ratio", fee_ratio);
	write_field(out, "max_fee_amount", max_fee_amount);
	write_field(out, "note", 	note);
	write_field(out, "nonce", 	nonce);
	write_field(out, "network", network);
	write_field(out, "sender",	sender);
	write_field(out, "inputs",	inputs, full_hash);
	write_field(out, "outputs", outputs);
	write_field(out, "execute");
	write_bytes(out, uint32_t(execute.size()));
	for(const auto& op : execute) {
		write_bytes(out, op ? op->calc_hash(full_hash) : hash_t());
	}
	write_field(out, "deploy", deploy ? deploy->calc_hash(full_hash) : hash_t());

	if(full_hash) {
		write_field(out, "static_cost", static_cost);
		write_field(out, "solutions");
		write_bytes(out, uint32_t(solutions.size()));
		for(const auto& sol : solutions) {
			write_bytes(out, sol ? sol->calc_hash() : hash_t());
		}
		write_field(out, "exec_result", exec_result ? exec_result->calc_hash() : hash_t());
	}
	out.flush();

	return buffer;
}

hash_t Transaction::calc_hash(const vnx::bool_t& full_hash) const
{
	return hash_t(hash_serialize(full_hash));
}

void Transaction::add_input(const addr_t& currency, const addr_t& address, const uint128& amount)
{
	txin_t in;
	in.address = address;
	in.contract = currency;
	in.amount = amount;
	inputs.push_back(in);
}

void Transaction::add_output(const addr_t& currency, const addr_t& address, const uint128& amount, const vnx::optional<std::string>& memo)
{
	if(memo && memo->size() > txio_t::MAX_MEMO_SIZE) {
		throw std::logic_error("memo too long");
	}
	txout_t out;
	out.address = address;
	out.contract = currency;
	out.amount = amount;
	out.memo = memo;
	outputs.push_back(out);
}

std::shared_ptr<const Solution> Transaction::get_solution(const uint32_t& index) const
{
	if(index < solutions.size()) {
		return solutions[index];
	}
	return nullptr;
}

std::vector<txin_t> Transaction::get_inputs() const
{
	auto res = inputs;
	if(exec_result) {
		res.insert(res.end(), exec_result->inputs.begin(), exec_result->inputs.end());
	}
	return res;
}

std::vector<txout_t> Transaction::get_outputs() const
{
	auto res = outputs;
	if(exec_result) {
		res.insert(res.end(), exec_result->outputs.begin(), exec_result->outputs.end());
	}
	return res;
}

std::vector<std::shared_ptr<const Operation>> Transaction::get_operations() const
{
	return execute;
}

uint64_t Transaction::calc_cost(std::shared_ptr<const ChainParams> params) const
{
	if(!params) {
		throw std::logic_error("!params");
	}
	uint128_t cost = params->min_txfee;
	cost += execute.size() * params->min_txfee_exec;

	if(exec_result) {
		cost += exec_result->calc_cost(params);
	}
	for(const auto& in : inputs) {
		cost += in.calc_cost(params);
	}
	for(const auto& out : outputs) {
		cost += out.calc_cost(params);
	}
	for(const auto& op : execute) {
		if(op) {
			cost += op->calc_cost(params);
		}
	}
	for(const auto& sol : solutions) {
		if(sol) {
			cost += sol->calc_cost(params);
		}
	}
	if(deploy) {
		cost += params->min_txfee_deploy + deploy->calc_cost(params);
	}
	if(cost >> 64) {
		throw std::logic_error("tx cost amount overflow");
	}
	return cost;
}

void Transaction::merge_sign(std::shared_ptr<const Transaction> tx)
{
	std::unordered_map<uint32_t, uint32_t> import_map;
	for(size_t i = 0; i < inputs.size() && i < tx->inputs.size(); ++i)
	{
		auto& our = inputs[i];
		const auto& other = tx->inputs[i];

		if(other.solution < tx->solutions.size() && our.solution >= solutions.size())
		{
			auto iter = import_map.find(other.solution);
			if(iter != import_map.end()) {
				our.solution = iter->second;
			} else {
				our.solution = solutions.size();
				import_map[other.solution] = our.solution;
				solutions.push_back(tx->solutions[other.solution]);
			}
		}
	}
}

vnx::bool_t Transaction::is_signed() const
{
	for(const auto& in : inputs) {
		if(in.solution >= solutions.size()) {
			return false;
		}
		// TODO: handle multi-sig
	}
	return true;
}

std::map<addr_t, std::pair<uint128, uint128>> Transaction::get_balance() const
{
	std::map<addr_t, std::pair<uint128, uint128>> balance;
	for(const auto& in : get_inputs()) {
		balance[in.contract].first += in.amount;
	}
	for(const auto& out : get_outputs()) {
		balance[out.contract].second += out.amount;
	}
	return balance;
}

tx_index_t Transaction::get_tx_index(std::shared_ptr<const ChainParams> params, std::shared_ptr<const BlockHeader> block, const int64_t& file_offset) const
{
	tx_index_t index;
	index.height = block->height;
	index.time_stamp = block->time_stamp;
	index.file_offset = file_offset;
	index.static_cost = static_cost;
	if(deploy) {
		index.contract_read_cost = (deploy->num_bytes() * params->min_txfee_read_kbyte) / 1000;
	}
	return index;
}


} // mmx
