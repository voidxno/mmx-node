
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/MutableRelay_unlock.hxx>
#include <mmx/contract/MutableRelay_unlock_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 MutableRelay_unlock::VNX_TYPE_HASH(0x7253750bf00d6f4eull);
const vnx::Hash64 MutableRelay_unlock::VNX_CODE_HASH(0xecb69c624dbdb557ull);

vnx::Hash64 MutableRelay_unlock::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string MutableRelay_unlock::get_type_name() const {
	return "mmx.contract.MutableRelay.unlock";
}

const vnx::TypeCode* MutableRelay_unlock::get_type_code() const {
	return mmx::contract::vnx_native_type_code_MutableRelay_unlock;
}

std::shared_ptr<MutableRelay_unlock> MutableRelay_unlock::create() {
	return std::make_shared<MutableRelay_unlock>();
}

std::shared_ptr<vnx::Value> MutableRelay_unlock::clone() const {
	return std::make_shared<MutableRelay_unlock>(*this);
}

void MutableRelay_unlock::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void MutableRelay_unlock::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void MutableRelay_unlock::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_MutableRelay_unlock;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, height);
	_visitor.type_end(*_type_code);
}

void MutableRelay_unlock::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.MutableRelay.unlock\"";
	_out << ", \"height\": "; vnx::write(_out, height);
	_out << "}";
}

void MutableRelay_unlock::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object MutableRelay_unlock::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.MutableRelay.unlock";
	_object["height"] = height;
	return _object;
}

void MutableRelay_unlock::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "height") {
			_entry.second.to(height);
		}
	}
}

vnx::Variant MutableRelay_unlock::get_field(const std::string& _name) const {
	if(_name == "height") {
		return vnx::Variant(height);
	}
	return vnx::Variant();
}

void MutableRelay_unlock::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "height") {
		_value.to(height);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const MutableRelay_unlock& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, MutableRelay_unlock& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* MutableRelay_unlock::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> MutableRelay_unlock::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.MutableRelay.unlock";
	type_code->type_hash = vnx::Hash64(0x7253750bf00d6f4eull);
	type_code->code_hash = vnx::Hash64(0xecb69c624dbdb557ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::contract::MutableRelay_unlock);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<MutableRelay_unlock>(); };
	type_code->return_type = ::mmx::contract::MutableRelay_unlock_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "height";
		field.code = {3};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::MutableRelay_unlock& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.height, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::MutableRelay_unlock& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_MutableRelay_unlock;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::MutableRelay_unlock>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.height);
}

void read(std::istream& in, ::mmx::contract::MutableRelay_unlock& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::MutableRelay_unlock& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::MutableRelay_unlock& value) {
	value.accept(visitor);
}

} // vnx