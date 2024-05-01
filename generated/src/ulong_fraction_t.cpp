
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/ulong_fraction_t.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 ulong_fraction_t::VNX_TYPE_HASH(0xe9c2388a9c35ce06ull);
const vnx::Hash64 ulong_fraction_t::VNX_CODE_HASH(0xaac983b163951134ull);

vnx::Hash64 ulong_fraction_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string ulong_fraction_t::get_type_name() const {
	return "mmx.ulong_fraction_t";
}

const vnx::TypeCode* ulong_fraction_t::get_type_code() const {
	return mmx::vnx_native_type_code_ulong_fraction_t;
}

std::shared_ptr<ulong_fraction_t> ulong_fraction_t::create() {
	return std::make_shared<ulong_fraction_t>();
}

std::shared_ptr<ulong_fraction_t> ulong_fraction_t::clone() const {
	return std::make_shared<ulong_fraction_t>(*this);
}

void ulong_fraction_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void ulong_fraction_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void ulong_fraction_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_ulong_fraction_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, value);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, inverse);
	_visitor.type_end(*_type_code);
}

void ulong_fraction_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"value\": "; vnx::write(_out, value);
	_out << ", \"inverse\": "; vnx::write(_out, inverse);
	_out << "}";
}

void ulong_fraction_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object ulong_fraction_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.ulong_fraction_t";
	_object["value"] = value;
	_object["inverse"] = inverse;
	return _object;
}

void ulong_fraction_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "inverse") {
			_entry.second.to(inverse);
		} else if(_entry.first == "value") {
			_entry.second.to(value);
		}
	}
}

vnx::Variant ulong_fraction_t::get_field(const std::string& _name) const {
	if(_name == "value") {
		return vnx::Variant(value);
	}
	if(_name == "inverse") {
		return vnx::Variant(inverse);
	}
	return vnx::Variant();
}

void ulong_fraction_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "value") {
		_value.to(value);
	} else if(_name == "inverse") {
		_value.to(inverse);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const ulong_fraction_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, ulong_fraction_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* ulong_fraction_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> ulong_fraction_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.ulong_fraction_t";
	type_code->type_hash = vnx::Hash64(0xe9c2388a9c35ce06ull);
	type_code->code_hash = vnx::Hash64(0xaac983b163951134ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::ulong_fraction_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<ulong_fraction_t>>(); };
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.data_size = 8;
		field.name = "value";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 8;
		field.name = "inverse";
		field.value = vnx::to_string(1);
		field.code = {4};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::ulong_fraction_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.value, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.inverse, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::ulong_fraction_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_ulong_fraction_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::ulong_fraction_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(16);
	vnx::write_value(_buf + 0, value.value);
	vnx::write_value(_buf + 8, value.inverse);
}

void read(std::istream& in, ::mmx::ulong_fraction_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::ulong_fraction_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::ulong_fraction_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::ulong_fraction_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::ulong_fraction_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
