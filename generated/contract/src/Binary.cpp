
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/Binary.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Contract.hxx>
#include <mmx/Contract_calc_cost.hxx>
#include <mmx/Contract_calc_cost_return.hxx>
#include <mmx/Contract_calc_hash.hxx>
#include <mmx/Contract_calc_hash_return.hxx>
#include <mmx/Contract_get_owner.hxx>
#include <mmx/Contract_get_owner_return.hxx>
#include <mmx/Contract_is_locked.hxx>
#include <mmx/Contract_is_locked_return.hxx>
#include <mmx/Contract_is_valid.hxx>
#include <mmx/Contract_is_valid_return.hxx>
#include <mmx/Contract_validate.hxx>
#include <mmx/Contract_validate_return.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/contract/Binary_calc_cost.hxx>
#include <mmx/contract/Binary_calc_cost_return.hxx>
#include <mmx/contract/Binary_calc_hash.hxx>
#include <mmx/contract/Binary_calc_hash_return.hxx>
#include <mmx/contract/Binary_find_field.hxx>
#include <mmx/contract/Binary_find_field_return.hxx>
#include <mmx/contract/Binary_find_method.hxx>
#include <mmx/contract/Binary_find_method_return.hxx>
#include <mmx/contract/Binary_is_valid.hxx>
#include <mmx/contract/Binary_is_valid_return.hxx>
#include <mmx/contract/method_t.hxx>
#include <mmx/hash_t.hpp>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 Binary::VNX_TYPE_HASH(0xbbeba47fc8b740e5ull);
const vnx::Hash64 Binary::VNX_CODE_HASH(0xefa96876ddce400full);

vnx::Hash64 Binary::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Binary::get_type_name() const {
	return "mmx.contract.Binary";
}

const vnx::TypeCode* Binary::get_type_code() const {
	return mmx::contract::vnx_native_type_code_Binary;
}

std::shared_ptr<Binary> Binary::create() {
	return std::make_shared<Binary>();
}

std::shared_ptr<vnx::Value> Binary::clone() const {
	return std::make_shared<Binary>(*this);
}

void Binary::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Binary::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Binary::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_Binary;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, name);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, fields);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, methods);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, constant);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, binary);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, line_info);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, source_info);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, source);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, compiler);
	_visitor.type_end(*_type_code);
}

void Binary::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.Binary\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"name\": "; vnx::write(_out, name);
	_out << ", \"fields\": "; vnx::write(_out, fields);
	_out << ", \"methods\": "; vnx::write(_out, methods);
	_out << ", \"constant\": "; vnx::write(_out, constant);
	_out << ", \"binary\": "; vnx::write(_out, binary);
	_out << ", \"line_info\": "; vnx::write(_out, line_info);
	_out << ", \"source_info\": "; vnx::write(_out, source_info);
	_out << ", \"source\": "; vnx::write(_out, source);
	_out << ", \"compiler\": "; vnx::write(_out, compiler);
	_out << "}";
}

void Binary::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Binary::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.Binary";
	_object["version"] = version;
	_object["name"] = name;
	_object["fields"] = fields;
	_object["methods"] = methods;
	_object["constant"] = constant;
	_object["binary"] = binary;
	_object["line_info"] = line_info;
	_object["source_info"] = source_info;
	_object["source"] = source;
	_object["compiler"] = compiler;
	return _object;
}

void Binary::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "binary") {
			_entry.second.to(binary);
		} else if(_entry.first == "compiler") {
			_entry.second.to(compiler);
		} else if(_entry.first == "constant") {
			_entry.second.to(constant);
		} else if(_entry.first == "fields") {
			_entry.second.to(fields);
		} else if(_entry.first == "line_info") {
			_entry.second.to(line_info);
		} else if(_entry.first == "methods") {
			_entry.second.to(methods);
		} else if(_entry.first == "name") {
			_entry.second.to(name);
		} else if(_entry.first == "source") {
			_entry.second.to(source);
		} else if(_entry.first == "source_info") {
			_entry.second.to(source_info);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		}
	}
}

vnx::Variant Binary::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "name") {
		return vnx::Variant(name);
	}
	if(_name == "fields") {
		return vnx::Variant(fields);
	}
	if(_name == "methods") {
		return vnx::Variant(methods);
	}
	if(_name == "constant") {
		return vnx::Variant(constant);
	}
	if(_name == "binary") {
		return vnx::Variant(binary);
	}
	if(_name == "line_info") {
		return vnx::Variant(line_info);
	}
	if(_name == "source_info") {
		return vnx::Variant(source_info);
	}
	if(_name == "source") {
		return vnx::Variant(source);
	}
	if(_name == "compiler") {
		return vnx::Variant(compiler);
	}
	return vnx::Variant();
}

void Binary::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "name") {
		_value.to(name);
	} else if(_name == "fields") {
		_value.to(fields);
	} else if(_name == "methods") {
		_value.to(methods);
	} else if(_name == "constant") {
		_value.to(constant);
	} else if(_name == "binary") {
		_value.to(binary);
	} else if(_name == "line_info") {
		_value.to(line_info);
	} else if(_name == "source_info") {
		_value.to(source_info);
	} else if(_name == "source") {
		_value.to(source);
	} else if(_name == "compiler") {
		_value.to(compiler);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Binary& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Binary& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Binary::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Binary::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.Binary";
	type_code->type_hash = vnx::Hash64(0xbbeba47fc8b740e5ull);
	type_code->code_hash = vnx::Hash64(0xefa96876ddce400full);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::contract::Binary);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::Contract::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Binary>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::contract::method_t::static_get_type_code();
	type_code->methods.resize(11);
	type_code->methods[0] = ::mmx::Contract_calc_cost::static_get_type_code();
	type_code->methods[1] = ::mmx::Contract_calc_hash::static_get_type_code();
	type_code->methods[2] = ::mmx::Contract_get_owner::static_get_type_code();
	type_code->methods[3] = ::mmx::Contract_is_locked::static_get_type_code();
	type_code->methods[4] = ::mmx::Contract_is_valid::static_get_type_code();
	type_code->methods[5] = ::mmx::Contract_validate::static_get_type_code();
	type_code->methods[6] = ::mmx::contract::Binary_calc_cost::static_get_type_code();
	type_code->methods[7] = ::mmx::contract::Binary_calc_hash::static_get_type_code();
	type_code->methods[8] = ::mmx::contract::Binary_find_field::static_get_type_code();
	type_code->methods[9] = ::mmx::contract::Binary_find_method::static_get_type_code();
	type_code->methods[10] = ::mmx::contract::Binary_is_valid::static_get_type_code();
	type_code->fields.resize(10);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "name";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "fields";
		field.code = {13, 3, 32, 3};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "methods";
		field.code = {13, 3, 32, 19, 0};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "constant";
		field.code = {12, 1};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "binary";
		field.code = {12, 1};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "line_info";
		field.code = {13, 3, 3, 3};
	}
	{
		auto& field = type_code->fields[7];
		field.is_extended = true;
		field.name = "source_info";
		field.code = {13, 3, 3, 23, 2, 4, 5, 32, 3};
	}
	{
		auto& field = type_code->fields[8];
		field.is_extended = true;
		field.name = "source";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[9];
		field.is_extended = true;
		field.name = "compiler";
		field.code = {32};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> Binary::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
		case 0xb23d047adf8b2612ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_calc_cost>(_method);
			auto _return_value = ::mmx::Contract_calc_cost_return::create();
			_return_value->_ret_0 = calc_cost(_args->params);
			return _return_value;
		}
		case 0x622fcf1cba1952edull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_calc_hash>(_method);
			auto _return_value = ::mmx::Contract_calc_hash_return::create();
			_return_value->_ret_0 = calc_hash(_args->full_hash);
			return _return_value;
		}
		case 0x8fe2c64fdc8f0680ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_get_owner>(_method);
			auto _return_value = ::mmx::Contract_get_owner_return::create();
			_return_value->_ret_0 = get_owner();
			return _return_value;
		}
		case 0x9b7981d03b3aeab6ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_is_locked>(_method);
			auto _return_value = ::mmx::Contract_is_locked_return::create();
			_return_value->_ret_0 = is_locked(_args->height);
			return _return_value;
		}
		case 0xe3adf9b29a723217ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_is_valid>(_method);
			auto _return_value = ::mmx::Contract_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
		case 0xc2126a44901c8d52ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_validate>(_method);
			auto _return_value = ::mmx::Contract_validate_return::create();
			validate(_args->operation, _args->txid);
			return _return_value;
		}
		case 0x4c3fe58fddf47afull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Binary_calc_cost>(_method);
			auto _return_value = ::mmx::contract::Binary_calc_cost_return::create();
			_return_value->_ret_0 = calc_cost(_args->params);
			return _return_value;
		}
		case 0xd4d1353e984d3350ull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Binary_calc_hash>(_method);
			auto _return_value = ::mmx::contract::Binary_calc_hash_return::create();
			_return_value->_ret_0 = calc_hash(_args->full_hash);
			return _return_value;
		}
		case 0xd452e90b79266ffdull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Binary_find_field>(_method);
			auto _return_value = ::mmx::contract::Binary_find_field_return::create();
			_return_value->_ret_0 = find_field(_args->name);
			return _return_value;
		}
		case 0x909ccffe5a222b83ull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Binary_find_method>(_method);
			auto _return_value = ::mmx::contract::Binary_find_method_return::create();
			_return_value->_ret_0 = find_method(_args->name);
			return _return_value;
		}
		case 0x5dc8876a8b68a708ull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Binary_is_valid>(_method);
			auto _return_value = ::mmx::contract::Binary_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
	}
	return nullptr;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::Binary& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.name, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.fields, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.methods, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.constant, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.binary, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.line_info, type_code, _field->code.data()); break;
			case 7: vnx::read(in, value.source_info, type_code, _field->code.data()); break;
			case 8: vnx::read(in, value.source, type_code, _field->code.data()); break;
			case 9: vnx::read(in, value.compiler, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::Binary& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_Binary;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::Binary>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.version);
	vnx::write(out, value.name, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.fields, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.methods, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.constant, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.binary, type_code, type_code->fields[5].code.data());
	vnx::write(out, value.line_info, type_code, type_code->fields[6].code.data());
	vnx::write(out, value.source_info, type_code, type_code->fields[7].code.data());
	vnx::write(out, value.source, type_code, type_code->fields[8].code.data());
	vnx::write(out, value.compiler, type_code, type_code->fields[9].code.data());
}

void read(std::istream& in, ::mmx::contract::Binary& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::Binary& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::Binary& value) {
	value.accept(visitor);
}

} // vnx
