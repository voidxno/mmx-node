
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_pooling_stats_t_HXX_
#define INCLUDE_mmx_pooling_stats_t_HXX_

#include <vnx/Type.h>
#include <mmx/package.hxx>
#include <mmx/pooling_error_e.hxx>


namespace mmx {

struct MMX_EXPORT pooling_stats_t : vnx::struct_t {
	
	
	std::string server_url;
	uint64_t partial_diff = 0;
	uint64_t valid_points = 0;
	uint64_t failed_points = 0;
	uint32_t total_partials = 0;
	int64_t total_response_time = 0;
	int64_t last_partial = 0;
	std::map<::mmx::pooling_error_e, uint32_t> error_count;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xb2441a254359df11ull;
	
	pooling_stats_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	static std::shared_ptr<pooling_stats_t> create();
	std::shared_ptr<pooling_stats_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const pooling_stats_t& _value);
	friend std::istream& operator>>(std::istream& _in, pooling_stats_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void pooling_stats_t::accept_generic(T& _visitor) const {
	_visitor.template type_begin<pooling_stats_t>(8);
	_visitor.type_field("server_url", 0); _visitor.accept(server_url);
	_visitor.type_field("partial_diff", 1); _visitor.accept(partial_diff);
	_visitor.type_field("valid_points", 2); _visitor.accept(valid_points);
	_visitor.type_field("failed_points", 3); _visitor.accept(failed_points);
	_visitor.type_field("total_partials", 4); _visitor.accept(total_partials);
	_visitor.type_field("total_response_time", 5); _visitor.accept(total_response_time);
	_visitor.type_field("last_partial", 6); _visitor.accept(last_partial);
	_visitor.type_field("error_count", 7); _visitor.accept(error_count);
	_visitor.template type_end<pooling_stats_t>(8);
}


} // namespace mmx


namespace vnx {

template<>
struct is_equivalent<::mmx::pooling_stats_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_pooling_stats_t_HXX_
