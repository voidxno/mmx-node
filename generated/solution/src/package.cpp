
// AUTO GENERATED by vnxcppcodegen

#include <mmx/solution/MultiSig.hxx>
#include <mmx/solution/MultiSig_calc_cost.hxx>
#include <mmx/solution/MultiSig_calc_cost_return.hxx>
#include <mmx/solution/MultiSig_calc_hash.hxx>
#include <mmx/solution/MultiSig_calc_hash_return.hxx>
#include <mmx/solution/MultiSig_is_valid.hxx>
#include <mmx/solution/MultiSig_is_valid_return.hxx>
#include <mmx/solution/PubKey.hxx>
#include <mmx/solution/PubKey_calc_cost.hxx>
#include <mmx/solution/PubKey_calc_cost_return.hxx>
#include <mmx/solution/PubKey_calc_hash.hxx>
#include <mmx/solution/PubKey_calc_hash_return.hxx>

#include <mmx/solution/package.hxx>
#include <vnx/vnx.h>



namespace vnx {

const TypeCode* type<::mmx::solution::MultiSig>::get_type_code() {
	return mmx::solution::vnx_native_type_code_MultiSig;
}

void type<::mmx::solution::MultiSig>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::MultiSig());
}

void type<::mmx::solution::MultiSig>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::MultiSig_calc_cost>::get_type_code() {
	return mmx::solution::vnx_native_type_code_MultiSig_calc_cost;
}

void type<::mmx::solution::MultiSig_calc_cost>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::MultiSig_calc_cost());
}

void type<::mmx::solution::MultiSig_calc_cost>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_cost& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::MultiSig_calc_cost_return>::get_type_code() {
	return mmx::solution::vnx_native_type_code_MultiSig_calc_cost_return;
}

void type<::mmx::solution::MultiSig_calc_cost_return>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::MultiSig_calc_cost_return());
}

void type<::mmx::solution::MultiSig_calc_cost_return>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_cost_return& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::MultiSig_calc_hash>::get_type_code() {
	return mmx::solution::vnx_native_type_code_MultiSig_calc_hash;
}

void type<::mmx::solution::MultiSig_calc_hash>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::MultiSig_calc_hash());
}

void type<::mmx::solution::MultiSig_calc_hash>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_hash& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::MultiSig_calc_hash_return>::get_type_code() {
	return mmx::solution::vnx_native_type_code_MultiSig_calc_hash_return;
}

void type<::mmx::solution::MultiSig_calc_hash_return>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::MultiSig_calc_hash_return());
}

void type<::mmx::solution::MultiSig_calc_hash_return>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_hash_return& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::MultiSig_is_valid>::get_type_code() {
	return mmx::solution::vnx_native_type_code_MultiSig_is_valid;
}

void type<::mmx::solution::MultiSig_is_valid>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::MultiSig_is_valid());
}

void type<::mmx::solution::MultiSig_is_valid>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_is_valid& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::MultiSig_is_valid_return>::get_type_code() {
	return mmx::solution::vnx_native_type_code_MultiSig_is_valid_return;
}

void type<::mmx::solution::MultiSig_is_valid_return>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::MultiSig_is_valid_return());
}

void type<::mmx::solution::MultiSig_is_valid_return>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_is_valid_return& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::PubKey>::get_type_code() {
	return mmx::solution::vnx_native_type_code_PubKey;
}

void type<::mmx::solution::PubKey>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::PubKey());
}

void type<::mmx::solution::PubKey>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::PubKey_calc_cost>::get_type_code() {
	return mmx::solution::vnx_native_type_code_PubKey_calc_cost;
}

void type<::mmx::solution::PubKey_calc_cost>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::PubKey_calc_cost());
}

void type<::mmx::solution::PubKey_calc_cost>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_cost& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::PubKey_calc_cost_return>::get_type_code() {
	return mmx::solution::vnx_native_type_code_PubKey_calc_cost_return;
}

void type<::mmx::solution::PubKey_calc_cost_return>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::PubKey_calc_cost_return());
}

void type<::mmx::solution::PubKey_calc_cost_return>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_cost_return& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::PubKey_calc_hash>::get_type_code() {
	return mmx::solution::vnx_native_type_code_PubKey_calc_hash;
}

void type<::mmx::solution::PubKey_calc_hash>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::PubKey_calc_hash());
}

void type<::mmx::solution::PubKey_calc_hash>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_hash& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::mmx::solution::PubKey_calc_hash_return>::get_type_code() {
	return mmx::solution::vnx_native_type_code_PubKey_calc_hash_return;
}

void type<::mmx::solution::PubKey_calc_hash_return>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::mmx::solution::PubKey_calc_hash_return());
}

void type<::mmx::solution::PubKey_calc_hash_return>::create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_hash_return& value, bool special) {
	code.push_back(CODE_OBJECT);
}


} // namespace vnx


namespace mmx {
namespace solution {


void register_all_types() {
	vnx::register_type_code(::mmx::solution::MultiSig::static_create_type_code());
	vnx::register_type_code(::mmx::solution::MultiSig_calc_cost::static_create_type_code());
	vnx::register_type_code(::mmx::solution::MultiSig_calc_cost_return::static_create_type_code());
	vnx::register_type_code(::mmx::solution::MultiSig_calc_hash::static_create_type_code());
	vnx::register_type_code(::mmx::solution::MultiSig_calc_hash_return::static_create_type_code());
	vnx::register_type_code(::mmx::solution::MultiSig_is_valid::static_create_type_code());
	vnx::register_type_code(::mmx::solution::MultiSig_is_valid_return::static_create_type_code());
	vnx::register_type_code(::mmx::solution::PubKey::static_create_type_code());
	vnx::register_type_code(::mmx::solution::PubKey_calc_cost::static_create_type_code());
	vnx::register_type_code(::mmx::solution::PubKey_calc_cost_return::static_create_type_code());
	vnx::register_type_code(::mmx::solution::PubKey_calc_hash::static_create_type_code());
	vnx::register_type_code(::mmx::solution::PubKey_calc_hash_return::static_create_type_code());
}

static struct vnx_static_init {
	vnx_static_init() {
		register_all_types();
	}
} vnx_static_init_;

const vnx::TypeCode* const vnx_native_type_code_MultiSig = vnx::get_type_code(vnx::Hash64(0x64ffa2f8fc8dffd1ull));
const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_cost = vnx::get_type_code(vnx::Hash64(0xfb2b838b50eecb72ull));
const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_cost_return = vnx::get_type_code(vnx::Hash64(0x79657a74d9b800aaull));
const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_hash = vnx::get_type_code(vnx::Hash64(0x2b3948ed357cbf8dull));
const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_hash_return = vnx::get_type_code(vnx::Hash64(0x23327785f676dd6ull));
const vnx::TypeCode* const vnx_native_type_code_MultiSig_is_valid = vnx::get_type_code(vnx::Hash64(0x7efc69b79102b1b3ull));
const vnx::TypeCode* const vnx_native_type_code_MultiSig_is_valid_return = vnx::get_type_code(vnx::Hash64(0x1a2973981d777bdfull));
const vnx::TypeCode* const vnx_native_type_code_PubKey = vnx::get_type_code(vnx::Hash64(0xe47af6fcacfcefa5ull));
const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_cost = vnx::get_type_code(vnx::Hash64(0xf065d06ca573eff7ull));
const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_cost_return = vnx::get_type_code(vnx::Hash64(0x856844fb6a20021aull));
const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_hash = vnx::get_type_code(vnx::Hash64(0x20771b0ac0e19b08ull));
const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_hash_return = vnx::get_type_code(vnx::Hash64(0xfe3e19f7ecff6f66ull));

} // namespace mmx
} // namespace solution
