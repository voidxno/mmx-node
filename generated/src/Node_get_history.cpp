
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Node_get_history.hxx>
#include <mmx/Node_get_history_return.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Node_get_history::VNX_TYPE_HASH(0x8b3db05c6e91011dull);
const vnx::Hash64 Node_get_history::VNX_CODE_HASH(0x21fbdfa18ac8226ull);

vnx::Hash64 Node_get_history::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Node_get_history::get_type_name() const {
	return "mmx.Node.get_history";
}

const vnx::TypeCode* Node_get_history::get_type_code() const {
	return mmx::vnx_native_type_code_Node_get_history;
}

std::shared_ptr<Node_get_history> Node_get_history::create() {
	return std::make_shared<Node_get_history>();
}

std::shared_ptr<vnx::Value> Node_get_history::clone() const {
	return std::make_shared<Node_get_history>(*this);
}

void Node_get_history::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Node_get_history::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Node_get_history::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Node_get_history;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, addresses);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, since);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, until);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, limit);
	_visitor.type_end(*_type_code);
}

void Node_get_history::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Node.get_history\"";
	_out << ", \"addresses\": "; vnx::write(_out, addresses);
	_out << ", \"since\": "; vnx::write(_out, since);
	_out << ", \"until\": "; vnx::write(_out, until);
	_out << ", \"limit\": "; vnx::write(_out, limit);
	_out << "}";
}

void Node_get_history::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Node_get_history::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Node.get_history";
	_object["addresses"] = addresses;
	_object["since"] = since;
	_object["until"] = until;
	_object["limit"] = limit;
	return _object;
}

void Node_get_history::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "addresses") {
			_entry.second.to(addresses);
		} else if(_entry.first == "limit") {
			_entry.second.to(limit);
		} else if(_entry.first == "since") {
			_entry.second.to(since);
		} else if(_entry.first == "until") {
			_entry.second.to(until);
		}
	}
}

vnx::Variant Node_get_history::get_field(const std::string& _name) const {
	if(_name == "addresses") {
		return vnx::Variant(addresses);
	}
	if(_name == "since") {
		return vnx::Variant(since);
	}
	if(_name == "until") {
		return vnx::Variant(until);
	}
	if(_name == "limit") {
		return vnx::Variant(limit);
	}
	return vnx::Variant();
}

void Node_get_history::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "addresses") {
		_value.to(addresses);
	} else if(_name == "since") {
		_value.to(since);
	} else if(_name == "until") {
		_value.to(until);
	} else if(_name == "limit") {
		_value.to(limit);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Node_get_history& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Node_get_history& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Node_get_history::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Node_get_history::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Node.get_history";
	type_code->type_hash = vnx::Hash64(0x8b3db05c6e91011dull);
	type_code->code_hash = vnx::Hash64(0x21fbdfa18ac8226ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Node_get_history);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Node_get_history>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Node_get_history_return::static_get_type_code();
	type_code->fields.resize(4);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "addresses";
		field.code = {12, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "since";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "until";
		field.value = vnx::to_string(-1);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "limit";
		field.value = vnx::to_string(-1);
		field.code = {7};
	}
	type_code->permission = "mmx.permission_e.PUBLIC";
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Node_get_history& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.since, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.until, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.limit, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.addresses, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Node_get_history& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Node_get_history;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Node_get_history>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(12);
	vnx::write_value(_buf + 0, value.since);
	vnx::write_value(_buf + 4, value.until);
	vnx::write_value(_buf + 8, value.limit);
	vnx::write(out, value.addresses, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::Node_get_history& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Node_get_history& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Node_get_history& value) {
	value.accept(visitor);
}

} // vnx
