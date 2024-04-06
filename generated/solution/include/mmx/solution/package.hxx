
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_solution_PACKAGE_HXX_
#define INCLUDE_mmx_solution_PACKAGE_HXX_

#include <vnx/Type.h>

#include <mmx/package.hxx>
#include <vnx/package.hxx>

#ifdef MMX_SOLUTION_EXPORT_ENABLE
#include <mmx_solution_export.h>
#else
#ifndef MMX_SOLUTION_EXPORT
#define MMX_SOLUTION_EXPORT
#endif
#endif


namespace mmx {
namespace solution {

void register_all_types();


class MultiSig;
class MultiSig_calc_cost;
class MultiSig_calc_cost_return;
class MultiSig_calc_hash;
class MultiSig_calc_hash_return;
class MultiSig_is_valid;
class MultiSig_is_valid_return;
class PubKey;
class PubKey_calc_cost;
class PubKey_calc_cost_return;
class PubKey_calc_hash;
class PubKey_calc_hash_return;

MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_cost; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_cost_return; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_hash; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig_calc_hash_return; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig_is_valid; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig_is_valid_return; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_PubKey; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_cost; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_cost_return; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_hash; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_PubKey_calc_hash_return; ///< \private

} // namespace mmx
} // namespace solution


namespace vnx {

void read(TypeInput& in, ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::MultiSig_calc_cost& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::MultiSig_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::MultiSig_calc_hash& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::MultiSig_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::MultiSig_is_valid& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::MultiSig_is_valid_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::PubKey_calc_cost& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::PubKey_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::PubKey_calc_hash& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::PubKey_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void write(TypeOutput& out, const ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_cost& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_hash& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::MultiSig_is_valid& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::MultiSig_is_valid_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_cost& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_hash& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void read(std::istream& in, ::mmx::solution::MultiSig& value); ///< \private
void read(std::istream& in, ::mmx::solution::MultiSig_calc_cost& value); ///< \private
void read(std::istream& in, ::mmx::solution::MultiSig_calc_cost_return& value); ///< \private
void read(std::istream& in, ::mmx::solution::MultiSig_calc_hash& value); ///< \private
void read(std::istream& in, ::mmx::solution::MultiSig_calc_hash_return& value); ///< \private
void read(std::istream& in, ::mmx::solution::MultiSig_is_valid& value); ///< \private
void read(std::istream& in, ::mmx::solution::MultiSig_is_valid_return& value); ///< \private
void read(std::istream& in, ::mmx::solution::PubKey& value); ///< \private
void read(std::istream& in, ::mmx::solution::PubKey_calc_cost& value); ///< \private
void read(std::istream& in, ::mmx::solution::PubKey_calc_cost_return& value); ///< \private
void read(std::istream& in, ::mmx::solution::PubKey_calc_hash& value); ///< \private
void read(std::istream& in, ::mmx::solution::PubKey_calc_hash_return& value); ///< \private

void write(std::ostream& out, const ::mmx::solution::MultiSig& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_cost& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_cost_return& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_hash& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_hash_return& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::MultiSig_is_valid& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::MultiSig_is_valid_return& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::PubKey& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::PubKey_calc_cost& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::PubKey_calc_cost_return& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::PubKey_calc_hash& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::PubKey_calc_hash_return& value); ///< \private

void accept(Visitor& visitor, const ::mmx::solution::MultiSig& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_cost& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_cost_return& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_hash& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_hash_return& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::MultiSig_is_valid& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::MultiSig_is_valid_return& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::PubKey& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_cost& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_cost_return& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_hash& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_hash_return& value); ///< \private

/// \private
template<>
struct type<::mmx::solution::MultiSig> {
	void read(TypeInput& in, ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::MultiSig_calc_cost> {
	void read(TypeInput& in, ::mmx::solution::MultiSig_calc_cost& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_cost& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig_calc_cost& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_cost& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_cost& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_cost& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::MultiSig_calc_cost_return> {
	void read(TypeInput& in, ::mmx::solution::MultiSig_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig_calc_cost_return& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_cost_return& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_cost_return& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_cost_return& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::MultiSig_calc_hash> {
	void read(TypeInput& in, ::mmx::solution::MultiSig_calc_hash& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_hash& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig_calc_hash& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_hash& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_hash& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_hash& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::MultiSig_calc_hash_return> {
	void read(TypeInput& in, ::mmx::solution::MultiSig_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig_calc_hash_return& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig_calc_hash_return& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig_calc_hash_return& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_calc_hash_return& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::MultiSig_is_valid> {
	void read(TypeInput& in, ::mmx::solution::MultiSig_is_valid& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig_is_valid& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig_is_valid& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig_is_valid& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig_is_valid& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_is_valid& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::MultiSig_is_valid_return> {
	void read(TypeInput& in, ::mmx::solution::MultiSig_is_valid_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig_is_valid_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig_is_valid_return& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig_is_valid_return& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig_is_valid_return& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig_is_valid_return& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::PubKey> {
	void read(TypeInput& in, ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::PubKey& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::PubKey& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::PubKey& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::PubKey_calc_cost> {
	void read(TypeInput& in, ::mmx::solution::PubKey_calc_cost& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_cost& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::PubKey_calc_cost& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::PubKey_calc_cost& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_cost& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_cost& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::PubKey_calc_cost_return> {
	void read(TypeInput& in, ::mmx::solution::PubKey_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_cost_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::PubKey_calc_cost_return& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::PubKey_calc_cost_return& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_cost_return& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_cost_return& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::PubKey_calc_hash> {
	void read(TypeInput& in, ::mmx::solution::PubKey_calc_hash& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_hash& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::PubKey_calc_hash& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::PubKey_calc_hash& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_hash& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_hash& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::PubKey_calc_hash_return> {
	void read(TypeInput& in, ::mmx::solution::PubKey_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::PubKey_calc_hash_return& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::PubKey_calc_hash_return& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::PubKey_calc_hash_return& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::PubKey_calc_hash_return& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey_calc_hash_return& value, bool special = false);
};


} // namespace vnx

#endif // INCLUDE_mmx_solution_PACKAGE_HXX_
