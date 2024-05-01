
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_contract_MultiSig_HXX_
#define INCLUDE_mmx_contract_MultiSig_HXX_

#include <mmx/contract/package.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Contract.hxx>
#include <mmx/Solution.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <vnx/Variant.hpp>


namespace mmx {
namespace contract {

class MMX_CONTRACT_EXPORT MultiSig : public ::mmx::Contract {
public:
	
	uint32_t num_required = 0;
	std::set<::mmx::addr_t> owners;
	
	typedef ::mmx::Contract Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x7d674c5f7297dedull;
	
	MultiSig() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual vnx::bool_t is_valid() const override;
	virtual ::mmx::hash_t calc_hash(const vnx::bool_t& full_hash = 0) const override;
	virtual uint64_t num_bytes(const vnx::bool_t& total = true) const override;
	virtual uint64_t calc_cost(std::shared_ptr<const ::mmx::ChainParams> params = nullptr) const override;
	virtual void validate(std::shared_ptr<const ::mmx::Solution> solution = nullptr, const ::mmx::hash_t& txid = ::mmx::hash_t()) const override;
	virtual ::vnx::Variant read_field(const std::string& name = "") const override;
	
	static std::shared_ptr<MultiSig> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const MultiSig& _value);
	friend std::istream& operator>>(std::istream& _in, MultiSig& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void MultiSig::accept_generic(T& _visitor) const {
	_visitor.template type_begin<MultiSig>(3);
	_visitor.type_field("version", 0); _visitor.accept(version);
	_visitor.type_field("num_required", 1); _visitor.accept(num_required);
	_visitor.type_field("owners", 2); _visitor.accept(owners);
	_visitor.template type_end<MultiSig>(3);
}


} // namespace mmx
} // namespace contract


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_contract_MultiSig_HXX_
