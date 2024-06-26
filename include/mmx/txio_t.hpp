/*
 * txio_t.hpp
 *
 *  Created on: Sep 16, 2023
 *      Author: mad
 */

#include <mmx/txio_t.hxx>


namespace mmx {

uint64_t txio_t::calc_cost(std::shared_ptr<const ChainParams> params) const
{
	return params->min_txfee_io
			+ (memo ? std::max<size_t>((memo->size() + 31) / 32, 1) * params->min_txfee_memo : 0);
}


} // mmx
