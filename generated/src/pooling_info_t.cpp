
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/pooling_info_t.hxx>
#include <mmx/addr_t.hpp>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 pooling_info_t::VNX_TYPE_HASH(0xbddcc977498f516full);
const vnx::Hash64 pooling_info_t::VNX_CODE_HASH(0xa9f0b8c45df33ab0ull);

vnx::Hash64 pooling_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string pooling_info_t::get_type_name() const {
	return "mmx.pooling_info_t";
}

const vnx::TypeCode* pooling_info_t::get_type_code() const {
	return mmx::vnx_native_type_code_pooling_info_t;
}

std::shared_ptr<pooling_info_t> pooling_info_t::create() {
	return std::make_shared<pooling_info_t>();
}

std::shared_ptr<pooling_info_t> pooling_info_t::clone() const {
	return std::make_shared<pooling_info_t>(*this);
}

void pooling_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void pooling_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void pooling_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_pooling_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, contract);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, server_url);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, pool_target);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, plot_count);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, partial_diff);
	_visitor.type_end(*_type_code);
}

void pooling_info_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"contract\": "; vnx::write(_out, contract);
	_out << ", \"server_url\": "; vnx::write(_out, server_url);
	_out << ", \"pool_target\": "; vnx::write(_out, pool_target);
	_out << ", \"plot_count\": "; vnx::write(_out, plot_count);
	_out << ", \"partial_diff\": "; vnx::write(_out, partial_diff);
	_out << "}";
}

void pooling_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object pooling_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.pooling_info_t";
	_object["contract"] = contract;
	_object["server_url"] = server_url;
	_object["pool_target"] = pool_target;
	_object["plot_count"] = plot_count;
	_object["partial_diff"] = partial_diff;
	return _object;
}

void pooling_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "contract") {
			_entry.second.to(contract);
		} else if(_entry.first == "partial_diff") {
			_entry.second.to(partial_diff);
		} else if(_entry.first == "plot_count") {
			_entry.second.to(plot_count);
		} else if(_entry.first == "pool_target") {
			_entry.second.to(pool_target);
		} else if(_entry.first == "server_url") {
			_entry.second.to(server_url);
		}
	}
}

vnx::Variant pooling_info_t::get_field(const std::string& _name) const {
	if(_name == "contract") {
		return vnx::Variant(contract);
	}
	if(_name == "server_url") {
		return vnx::Variant(server_url);
	}
	if(_name == "pool_target") {
		return vnx::Variant(pool_target);
	}
	if(_name == "plot_count") {
		return vnx::Variant(plot_count);
	}
	if(_name == "partial_diff") {
		return vnx::Variant(partial_diff);
	}
	return vnx::Variant();
}

void pooling_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "contract") {
		_value.to(contract);
	} else if(_name == "server_url") {
		_value.to(server_url);
	} else if(_name == "pool_target") {
		_value.to(pool_target);
	} else if(_name == "plot_count") {
		_value.to(plot_count);
	} else if(_name == "partial_diff") {
		_value.to(partial_diff);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const pooling_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, pooling_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* pooling_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> pooling_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.pooling_info_t";
	type_code->type_hash = vnx::Hash64(0xbddcc977498f516full);
	type_code->code_hash = vnx::Hash64(0xa9f0b8c45df33ab0ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::pooling_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<pooling_info_t>>(); };
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "contract";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "server_url";
		field.code = {33, 32};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "pool_target";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "plot_count";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 8;
		field.name = "partial_diff";
		field.code = {4};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::pooling_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	const auto* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.plot_count, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.partial_diff, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.contract, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.server_url, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.pool_target, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::pooling_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_pooling_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::pooling_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(12);
	vnx::write_value(_buf + 0, value.plot_count);
	vnx::write_value(_buf + 4, value.partial_diff);
	vnx::write(out, value.contract, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.server_url, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.pool_target, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::pooling_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::pooling_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::pooling_info_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::pooling_info_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::pooling_info_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
