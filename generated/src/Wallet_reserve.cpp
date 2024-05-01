
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Wallet_reserve.hxx>
#include <mmx/Wallet_reserve_return.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/uint128.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Wallet_reserve::VNX_TYPE_HASH(0xd14c466e8e7ebd76ull);
const vnx::Hash64 Wallet_reserve::VNX_CODE_HASH(0xe78e0ba524664c8dull);

vnx::Hash64 Wallet_reserve::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Wallet_reserve::get_type_name() const {
	return "mmx.Wallet.reserve";
}

const vnx::TypeCode* Wallet_reserve::get_type_code() const {
	return mmx::vnx_native_type_code_Wallet_reserve;
}

std::shared_ptr<Wallet_reserve> Wallet_reserve::create() {
	return std::make_shared<Wallet_reserve>();
}

std::shared_ptr<vnx::Value> Wallet_reserve::clone() const {
	return std::make_shared<Wallet_reserve>(*this);
}

void Wallet_reserve::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Wallet_reserve::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Wallet_reserve::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Wallet_reserve;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, index);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, amounts);
	_visitor.type_end(*_type_code);
}

void Wallet_reserve::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Wallet.reserve\"";
	_out << ", \"index\": "; vnx::write(_out, index);
	_out << ", \"amounts\": "; vnx::write(_out, amounts);
	_out << "}";
}

void Wallet_reserve::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Wallet_reserve::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Wallet.reserve";
	_object["index"] = index;
	_object["amounts"] = amounts;
	return _object;
}

void Wallet_reserve::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "amounts") {
			_entry.second.to(amounts);
		} else if(_entry.first == "index") {
			_entry.second.to(index);
		}
	}
}

vnx::Variant Wallet_reserve::get_field(const std::string& _name) const {
	if(_name == "index") {
		return vnx::Variant(index);
	}
	if(_name == "amounts") {
		return vnx::Variant(amounts);
	}
	return vnx::Variant();
}

void Wallet_reserve::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "index") {
		_value.to(index);
	} else if(_name == "amounts") {
		_value.to(amounts);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Wallet_reserve& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Wallet_reserve& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Wallet_reserve::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Wallet_reserve::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Wallet.reserve";
	type_code->type_hash = vnx::Hash64(0xd14c466e8e7ebd76ull);
	type_code->code_hash = vnx::Hash64(0xe78e0ba524664c8dull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Wallet_reserve);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Wallet_reserve>(); };
	type_code->return_type = ::mmx::Wallet_reserve_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "index";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "amounts";
		field.code = {13, 12, 23, 2, 4, 7, 11, 32, 1, 11, 32, 1, 11, 16, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Wallet_reserve& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.index, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.amounts, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Wallet_reserve& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Wallet_reserve;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Wallet_reserve>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.index);
	vnx::write(out, value.amounts, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::Wallet_reserve& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Wallet_reserve& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Wallet_reserve& value) {
	value.accept(visitor);
}

} // vnx
