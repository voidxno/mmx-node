
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Node_get_swaps.hxx>
#include <mmx/Node_get_swaps_return.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Node_get_swaps::VNX_TYPE_HASH(0x219bbb3e5dcd19eaull);
const vnx::Hash64 Node_get_swaps::VNX_CODE_HASH(0xa5c05dc8f762e46aull);

vnx::Hash64 Node_get_swaps::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Node_get_swaps::get_type_name() const {
	return "mmx.Node.get_swaps";
}

const vnx::TypeCode* Node_get_swaps::get_type_code() const {
	return mmx::vnx_native_type_code_Node_get_swaps;
}

std::shared_ptr<Node_get_swaps> Node_get_swaps::create() {
	return std::make_shared<Node_get_swaps>();
}

std::shared_ptr<vnx::Value> Node_get_swaps::clone() const {
	return std::make_shared<Node_get_swaps>(*this);
}

void Node_get_swaps::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Node_get_swaps::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Node_get_swaps::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Node_get_swaps;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, since);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, token);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, currency);
	_visitor.type_end(*_type_code);
}

void Node_get_swaps::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Node.get_swaps\"";
	_out << ", \"since\": "; vnx::write(_out, since);
	_out << ", \"token\": "; vnx::write(_out, token);
	_out << ", \"currency\": "; vnx::write(_out, currency);
	_out << "}";
}

void Node_get_swaps::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Node_get_swaps::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Node.get_swaps";
	_object["since"] = since;
	_object["token"] = token;
	_object["currency"] = currency;
	return _object;
}

void Node_get_swaps::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "currency") {
			_entry.second.to(currency);
		} else if(_entry.first == "since") {
			_entry.second.to(since);
		} else if(_entry.first == "token") {
			_entry.second.to(token);
		}
	}
}

vnx::Variant Node_get_swaps::get_field(const std::string& _name) const {
	if(_name == "since") {
		return vnx::Variant(since);
	}
	if(_name == "token") {
		return vnx::Variant(token);
	}
	if(_name == "currency") {
		return vnx::Variant(currency);
	}
	return vnx::Variant();
}

void Node_get_swaps::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "since") {
		_value.to(since);
	} else if(_name == "token") {
		_value.to(token);
	} else if(_name == "currency") {
		_value.to(currency);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Node_get_swaps& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Node_get_swaps& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Node_get_swaps::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Node_get_swaps::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Node.get_swaps";
	type_code->type_hash = vnx::Hash64(0x219bbb3e5dcd19eaull);
	type_code->code_hash = vnx::Hash64(0xa5c05dc8f762e46aull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Node_get_swaps);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Node_get_swaps>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Node_get_swaps_return::static_get_type_code();
	type_code->fields.resize(3);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "since";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "token";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "currency";
		field.code = {33, 11, 32, 1};
	}
	type_code->permission = "mmx.permission_e.PUBLIC";
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Node_get_swaps& value, const TypeCode* type_code, const uint16_t* code) {
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
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.since, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.token, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.currency, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Node_get_swaps& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Node_get_swaps;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Node_get_swaps>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.since);
	vnx::write(out, value.token, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.currency, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::Node_get_swaps& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Node_get_swaps& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Node_get_swaps& value) {
	value.accept(visitor);
}

} // vnx
