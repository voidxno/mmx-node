/*
 * WebData.cpp
 *
 *  Created on: Jan 19, 2022
 *      Author: mad
 */

#include <mmx/contract/WebData.hxx>
#include <mmx/write_bytes.h>


namespace mmx {
namespace contract {

vnx::bool_t WebData::is_valid() const {
	return Contract::is_valid() && !mime_type.empty();
}

hash_t WebData::calc_hash() const
{
	std::vector<uint8_t> buffer;
	vnx::VectorOutputStream stream(&buffer);
	vnx::OutputBuffer out(&stream);

	write_bytes(out, get_type_hash());
	write_field(out, "version", 	version);
	write_field(out, "owner", 		owner);
	write_field(out, "mime_type", 	mime_type);
	write_field(out, "payload", 	payload);
	out.flush();

	return hash_t(hash_t(buffer).bytes);
}

uint64_t WebData::calc_cost(std::shared_ptr<const ChainParams> params) const {
	return (8 + 4 + mime_type.size() + payload.size()) * params->min_txfee_byte;
}

std::vector<addr_t> WebData::get_dependency() const {
	if(owner) {
		return {*owner};
	}
	return {};
}

std::vector<addr_t> WebData::get_parties() const {
	return get_dependency();
}

vnx::optional<addr_t> WebData::get_owner() const {
	return owner;
}

std::vector<tx_out_t> WebData::validate(std::shared_ptr<const Operation> operation, std::shared_ptr<const Context> context) const
{
	if(!owner) {
		throw std::logic_error("!owner");
	}
	{
		auto contract = context->get_contract(*owner);
		if(!contract) {
			throw std::logic_error("missing dependency");
		}
		contract->validate(operation, context);
	}
	return {};
}

void WebData::transfer(const vnx::optional<addr_t>& new_owner)
{
	owner = new_owner;
}

void WebData::update(const vnx::Buffer& new_payload)
{
	payload = new_payload;
}


} // contract
} // mmx
