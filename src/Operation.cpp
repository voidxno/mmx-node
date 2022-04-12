/*
 * Operation.cpp
 *
 *  Created on: Nov 27, 2021
 *      Author: mad
 */

#include <mmx/Operation.hxx>
#include <mmx/write_bytes.h>


namespace mmx {

vnx::bool_t Operation::is_valid() const {
	return version == 0;
}

hash_t Operation::calc_hash() const
{
	std::vector<uint8_t> buffer;
	vnx::VectorOutputStream stream(&buffer);
	vnx::OutputBuffer out(&stream);

	write_bytes(out, get_type_hash());
	write_field(out, "version", version);
	write_field(out, "address", address);
	out.flush();

	return hash_t(hash_t(buffer).bytes);
}

uint64_t Operation::calc_cost(std::shared_ptr<const ChainParams> params) const {
	return (8 + 4 + 32) * params->min_txfee_byte;
}

} // mmx
