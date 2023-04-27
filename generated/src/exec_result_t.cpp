
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/exec_result_t.hxx>
#include <mmx/exec_error_t.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/txin_t.hxx>
#include <mmx/txout_t.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 exec_result_t::VNX_TYPE_HASH(0x18fe02e2374b039eull);
const vnx::Hash64 exec_result_t::VNX_CODE_HASH(0x3455c61680bc1587ull);

vnx::Hash64 exec_result_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string exec_result_t::get_type_name() const {
	return "mmx.exec_result_t";
}

const vnx::TypeCode* exec_result_t::get_type_code() const {
	return mmx::vnx_native_type_code_exec_result_t;
}

std::shared_ptr<exec_result_t> exec_result_t::create() {
	return std::make_shared<exec_result_t>();
}

std::shared_ptr<exec_result_t> exec_result_t::clone() const {
	return std::make_shared<exec_result_t>(*this);
}

void exec_result_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void exec_result_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void exec_result_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_exec_result_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, did_fail);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, total_cost);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, total_fee);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, inputs);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, outputs);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, error);
	_visitor.type_end(*_type_code);
}

void exec_result_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"did_fail\": "; vnx::write(_out, did_fail);
	_out << ", \"total_cost\": "; vnx::write(_out, total_cost);
	_out << ", \"total_fee\": "; vnx::write(_out, total_fee);
	_out << ", \"inputs\": "; vnx::write(_out, inputs);
	_out << ", \"outputs\": "; vnx::write(_out, outputs);
	_out << ", \"error\": "; vnx::write(_out, error);
	_out << "}";
}

void exec_result_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object exec_result_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.exec_result_t";
	_object["did_fail"] = did_fail;
	_object["total_cost"] = total_cost;
	_object["total_fee"] = total_fee;
	_object["inputs"] = inputs;
	_object["outputs"] = outputs;
	_object["error"] = error;
	return _object;
}

void exec_result_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "did_fail") {
			_entry.second.to(did_fail);
		} else if(_entry.first == "error") {
			_entry.second.to(error);
		} else if(_entry.first == "inputs") {
			_entry.second.to(inputs);
		} else if(_entry.first == "outputs") {
			_entry.second.to(outputs);
		} else if(_entry.first == "total_cost") {
			_entry.second.to(total_cost);
		} else if(_entry.first == "total_fee") {
			_entry.second.to(total_fee);
		}
	}
}

vnx::Variant exec_result_t::get_field(const std::string& _name) const {
	if(_name == "did_fail") {
		return vnx::Variant(did_fail);
	}
	if(_name == "total_cost") {
		return vnx::Variant(total_cost);
	}
	if(_name == "total_fee") {
		return vnx::Variant(total_fee);
	}
	if(_name == "inputs") {
		return vnx::Variant(inputs);
	}
	if(_name == "outputs") {
		return vnx::Variant(outputs);
	}
	if(_name == "error") {
		return vnx::Variant(error);
	}
	return vnx::Variant();
}

void exec_result_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "did_fail") {
		_value.to(did_fail);
	} else if(_name == "total_cost") {
		_value.to(total_cost);
	} else if(_name == "total_fee") {
		_value.to(total_fee);
	} else if(_name == "inputs") {
		_value.to(inputs);
	} else if(_name == "outputs") {
		_value.to(outputs);
	} else if(_name == "error") {
		_value.to(error);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const exec_result_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, exec_result_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* exec_result_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> exec_result_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.exec_result_t";
	type_code->type_hash = vnx::Hash64(0x18fe02e2374b039eull);
	type_code->code_hash = vnx::Hash64(0x3455c61680bc1587ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::exec_result_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<exec_result_t>>(); };
	type_code->depends.resize(3);
	type_code->depends[0] = ::mmx::txin_t::static_get_type_code();
	type_code->depends[1] = ::mmx::txout_t::static_get_type_code();
	type_code->depends[2] = ::mmx::exec_error_t::static_get_type_code();
	type_code->fields.resize(6);
	{
		auto& field = type_code->fields[0];
		field.data_size = 1;
		field.name = "did_fail";
		field.code = {31};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "total_cost";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "total_fee";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "inputs";
		field.code = {12, 19, 0};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "outputs";
		field.code = {12, 19, 1};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "error";
		field.code = {33, 19, 2};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::exec_result_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.did_fail, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.total_cost, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.total_fee, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 3: vnx::read(in, value.inputs, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.outputs, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.error, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::exec_result_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_exec_result_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::exec_result_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(9);
	vnx::write_value(_buf + 0, value.did_fail);
	vnx::write_value(_buf + 1, value.total_cost);
	vnx::write_value(_buf + 5, value.total_fee);
	vnx::write(out, value.inputs, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.outputs, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.error, type_code, type_code->fields[5].code.data());
}

void read(std::istream& in, ::mmx::exec_result_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::exec_result_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::exec_result_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::exec_result_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::exec_result_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
