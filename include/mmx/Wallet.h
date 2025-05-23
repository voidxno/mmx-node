/*
 * Wallet.h
 *
 *  Created on: Dec 11, 2021
 *      Author: mad
 */

#ifndef INCLUDE_MMX_WALLET_H_
#define INCLUDE_MMX_WALLET_H_

#include <mmx/WalletBase.hxx>
#include <mmx/NodeClient.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/ECDSA_Wallet.h>
#include <mmx/multi_table.h>

#include <vnx/addons/HttpInterface.h>


namespace mmx {

class Wallet : public WalletBase {
public:
	Wallet(const std::string& _vnx_name);

protected:
	void init() override;

	void main() override;

	std::shared_ptr<const Transaction> send(
			const uint32_t& index, const uint128& amount, const addr_t& dst_addr,
			const addr_t& currency, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> send_many(
			const uint32_t& index, const std::vector<std::pair<addr_t, uint128>>& amounts,
			const addr_t& currency, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> send_from(
			const uint32_t& index, const uint128& amount, const addr_t& dst_addr, const addr_t& src_addr,
			const addr_t& currency, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> deploy(
			const uint32_t& index, std::shared_ptr<const Contract> contract, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> execute(
			const uint32_t& index, const addr_t& address, const std::string& method,
			const std::vector<vnx::Variant>& args, const vnx::optional<uint32_t>& user, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> deposit(
			const uint32_t& index, const addr_t& address, const std::string& method, const std::vector<vnx::Variant>& args,
			const uint128& amount, const addr_t& currency, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> make_offer(
			const uint32_t& index, const uint32_t& owner, const uint128& bid_amount, const addr_t& bid_currency,
			const uint128& ask_amount, const addr_t& ask_currency, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> offer_trade(
			const uint32_t& index, const addr_t& address, const uint128& amount, const uint32_t& dst_addr, const uint128& price, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> accept_offer(
			const uint32_t& index, const addr_t& address, const uint32_t& dst_addr, const uint128& price, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> offer_withdraw(
			const uint32_t& index, const addr_t& address, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> cancel_offer(
			const uint32_t& index, const addr_t& address, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> swap_trade(
			const uint32_t& index, const addr_t& address, const uint128& amount, const addr_t& currency,
			const vnx::optional<uint128>& min_trade, const int32_t& num_iter, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> swap_add_liquid(
			const uint32_t& index, const addr_t& address, const std::array<uint128, 2>& amount, const uint32_t& pool_idx, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> swap_rem_liquid(
			const uint32_t& index, const addr_t& address, const std::array<uint128, 2>& amount, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> plotnft_exec(
			const addr_t& address, const std::string& method, const std::vector<vnx::Variant>& args, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> plotnft_create(
			const uint32_t& index, const std::string& name, const vnx::optional<uint32_t>& owner, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> complete(
			const uint32_t& index, std::shared_ptr<const Transaction> tx, const spend_options_t& options) const override;

	std::shared_ptr<const Transaction> sign_off(
			const uint32_t& index, std::shared_ptr<const Transaction> tx, const spend_options_t& options) const override;

	std::shared_ptr<const Solution> sign_msg(const uint32_t& index, const addr_t& address, const hash_t& msg) const override;

	void send_off(const uint32_t& index, std::shared_ptr<const Transaction> tx) const override;

	void mark_spent(const uint32_t& index, const std::map<std::pair<addr_t, addr_t>, uint128>& amounts) override;

	void reserve(const uint32_t& index, const std::map<std::pair<addr_t, addr_t>, uint128>& amounts) override;

	void release(const uint32_t& index, const std::map<std::pair<addr_t, addr_t>, uint128>& amounts) override;

	void release_all() override;

	void reset_cache(const uint32_t& index) override;

	void update_cache(const uint32_t& index) const override;

	std::vector<txin_t> gather_inputs_for(	const uint32_t& index, const uint128& amount,
											const addr_t& currency, const spend_options_t& options) const override;

	std::vector<tx_entry_t> get_history(const uint32_t& index, const query_filter_t& filter) const override;

	std::vector<tx_log_entry_t> get_tx_log(const uint32_t& index, const int32_t& limit) const override;

	balance_t get_balance(const uint32_t& index, const addr_t& currency) const override;

	std::map<addr_t, balance_t> get_balances(
			const uint32_t& index, const vnx::bool_t& with_zero = false) const override;

	std::map<addr_t, balance_t> get_total_balances(const std::vector<addr_t>& addresses) const override;

	std::map<addr_t, balance_t> get_contract_balances(const addr_t& address) const override;

	std::map<addr_t, std::shared_ptr<const Contract>> get_contracts(
			const uint32_t& index, const vnx::optional<std::string>& type_name, const vnx::optional<hash_t>& type_hash) const override;

	std::map<addr_t, std::shared_ptr<const Contract>> get_contracts_owned(
			const uint32_t& index, const vnx::optional<std::string>& type_name, const vnx::optional<hash_t>& type_hash) const override;

	std::vector<offer_data_t> get_offers(const uint32_t& index, const vnx::bool_t& state) const override;

	std::map<addr_t, std::array<std::pair<addr_t, uint128>, 2>> get_swap_liquidity(const uint32_t& index) const override;

	addr_t get_address(const uint32_t& index, const uint32_t& offset) const override;

	std::vector<addr_t> get_all_addresses(const int32_t& index) const override;

	int32_t find_wallet_by_addr(const addr_t& address) const override;

	std::pair<skey_t, pubkey_t> get_farmer_keys(const uint32_t& index) const override;

	std::vector<std::pair<skey_t, pubkey_t>> get_all_farmer_keys() const override;

	account_info_t get_account(const uint32_t& index) const override;

	std::vector<account_info_t> get_all_accounts() const override;

	bool is_locked(const uint32_t& index) const override;

	void lock(const uint32_t& index) override;

	void unlock(const uint32_t& index, const std::string& passphrase) override;

	void add_account(const uint32_t& index, const account_t& config, const vnx::optional<std::string>& passphrase) override;

	void create_account(const account_t& config, const vnx::optional<std::string>& passphrase) override;

	void create_wallet(const account_t& config, const vnx::optional<std::string>& words, const vnx::optional<std::string>& passphrase) override;

	void import_wallet(const account_t& config, std::shared_ptr<const KeyFile> key_file, const vnx::optional<std::string>& passphrase) override;

	std::shared_ptr<const KeyFile> export_wallet(const uint32_t& index) const override;

	void remove_account(const uint32_t& index, const uint32_t& account) override;

	void set_address_count(const uint32_t& index, const uint32_t& count) override;

	std::set<addr_t> get_token_list() const override;

	void add_token(const addr_t& address) override;

	void rem_token(const addr_t& address) override;

	hash_t get_master_seed(const uint32_t& index) const override;

	std::vector<std::string> get_mnemonic_seed(const uint32_t& index) const override;

	std::vector<std::string> get_mnemonic_wordlist(const std::string& lang) const override;

	void http_request_async(std::shared_ptr<const vnx::addons::HttpRequest> request, const std::string& sub_path,
							const vnx::request_id_t& request_id) const override;

	void http_request_chunk_async(	std::shared_ptr<const vnx::addons::HttpRequest> request, const std::string& sub_path,
									const int64_t& offset, const int64_t& max_bytes, const vnx::request_id_t& request_id) const override;

private:
	std::shared_ptr<ECDSA_Wallet> get_wallet(const uint32_t& index) const;

	addr_t get_plotnft_owner(const addr_t& address) const;

private:
	std::shared_ptr<NodeClient> node;

	std::vector<std::shared_ptr<ECDSA_Wallet>> wallets;

	std::map<uint32_t, std::weak_ptr<vnx::Timer>> lock_timers;

	mutable mmx::hash_multi_table<addr_t, tx_log_entry_t> tx_log;

	std::shared_ptr<const ChainParams> params;
	std::shared_ptr<vnx::addons::HttpInterface<Wallet>> http;

	friend class vnx::addons::HttpInterface<Wallet>;

};


} // mmx

#endif /* INCLUDE_MMX_WALLET_H_ */
