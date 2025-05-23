/*
 * hash_t.hpp
 *
 *  Created on: Nov 25, 2021
 *      Author: mad
 */

#ifndef INCLUDE_MMX_HASH_T_HPP_
#define INCLUDE_MMX_HASH_T_HPP_

#include <mmx/package.hxx>
#include <mmx/bytes_t.hpp>
#include <uint256_t.h>


namespace mmx {

class hash_t : public bytes_t<32> {
public:
	typedef bytes_t<32> super_t;

	hash_t() = default;

	explicit hash_t(const std::string& data);

	explicit hash_t(const std::vector<uint8_t>& data);

	template<size_t N>
	explicit hash_t(const std::array<uint8_t, N>& data);

	template<size_t N>
	explicit hash_t(const bytes_t<N>& data);

	explicit hash_t(const void* data, const size_t num_bytes);

	uint256_t to_uint256() const {
		return to_uint<uint256_t>();
	}

	static hash_t ones();

	static hash_t empty();

	static hash_t random();

	static hash_t secure_random();

	static hash_t from_bytes(const std::vector<uint8_t>& bytes);

	static hash_t from_bytes(const std::array<uint8_t, 32>& bytes);

	static hash_t from_bytes(const void* data);

};

inline
hash_t::hash_t(const std::string& data)
	:	hash_t(data.data(), data.size())
{
}

inline
hash_t::hash_t(const std::vector<uint8_t>& data)
	:	hash_t(data.data(), data.size())
{
}

template<size_t N>
hash_t::hash_t(const std::array<uint8_t, N>& data)
	:	hash_t(data.data(), data.size())
{
}

template<size_t N>
hash_t::hash_t(const bytes_t<N>& data)
	:	hash_t(data.data(), data.size())
{
}

inline
hash_t hash_t::ones() {
	hash_t res;
	::memset(res.data(), -1, res.size());
	return res;
}

inline
hash_t hash_t::empty() {
	return hash_t(nullptr, 0);
}

inline
hash_t hash_t::from_bytes(const std::vector<uint8_t>& bytes)
{
	if(bytes.size() != 32) {
		throw std::logic_error("hash size mismatch");
	}
	return from_bytes(bytes.data());
}

inline
hash_t hash_t::from_bytes(const std::array<uint8_t, 32>& bytes)
{
	return from_bytes(bytes.data());
}

inline
hash_t hash_t::from_bytes(const void* data)
{
	hash_t res;
	::memcpy(res.data(), data, 32);
	return res;
}

} // mmx


namespace vnx {

inline
void read(vnx::TypeInput& in, mmx::hash_t& value, const vnx::TypeCode* type_code, const uint16_t* code) {
	vnx::read(in, (mmx::hash_t::super_t&)value, type_code, code);
}

inline
void write(vnx::TypeOutput& out, const mmx::hash_t& value, const vnx::TypeCode* type_code = nullptr, const uint16_t* code = nullptr) {
	vnx::write(out, (const mmx::hash_t::super_t&)value, type_code, code);
}

inline
void read(std::istream& in, mmx::hash_t& value) {
	vnx::read(in, (mmx::hash_t::super_t&)value);
}

inline
void write(std::ostream& out, const mmx::hash_t& value) {
	vnx::write(out, value.to_string());
}

inline
void accept(vnx::Visitor& visitor, const mmx::hash_t& value) {
	vnx::accept(visitor, (const mmx::hash_t::super_t&)value);
}

} // vnx


namespace std {
	template<>
	struct hash<typename mmx::hash_t> {
		size_t operator()(const mmx::hash_t& x) const {
			size_t res = 0;
			::memcpy(&res, x.data(), std::min(x.size(), sizeof(res)));
			return res;
		}
	};
} // std

#endif /* INCLUDE_MMX_HASH_T_HPP_ */
