
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Farmer_get_partial_diffs.hxx>
#include <mmx/Farmer_get_partial_diffs_return.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Farmer_get_partial_diffs::VNX_TYPE_HASH(0x8806f6763215c58bull);
const vnx::Hash64 Farmer_get_partial_diffs::VNX_CODE_HASH(0xeff9197ef3d645f9ull);

vnx::Hash64 Farmer_get_partial_diffs::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Farmer_get_partial_diffs::get_type_name() const {
	return "mmx.Farmer.get_partial_diffs";
}

const vnx::TypeCode* Farmer_get_partial_diffs::get_type_code() const {
	return mmx::vnx_native_type_code_Farmer_get_partial_diffs;
}

std::shared_ptr<Farmer_get_partial_diffs> Farmer_get_partial_diffs::create() {
	return std::make_shared<Farmer_get_partial_diffs>();
}

std::shared_ptr<vnx::Value> Farmer_get_partial_diffs::clone() const {
	return std::make_shared<Farmer_get_partial_diffs>(*this);
}

void Farmer_get_partial_diffs::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Farmer_get_partial_diffs::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Farmer_get_partial_diffs::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Farmer_get_partial_diffs;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, plot_nfts);
	_visitor.type_end(*_type_code);
}

void Farmer_get_partial_diffs::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Farmer.get_partial_diffs\"";
	_out << ", \"plot_nfts\": "; vnx::write(_out, plot_nfts);
	_out << "}";
}

void Farmer_get_partial_diffs::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Farmer_get_partial_diffs::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Farmer.get_partial_diffs";
	_object["plot_nfts"] = plot_nfts;
	return _object;
}

void Farmer_get_partial_diffs::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "plot_nfts") {
			_entry.second.to(plot_nfts);
		}
	}
}

vnx::Variant Farmer_get_partial_diffs::get_field(const std::string& _name) const {
	if(_name == "plot_nfts") {
		return vnx::Variant(plot_nfts);
	}
	return vnx::Variant();
}

void Farmer_get_partial_diffs::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "plot_nfts") {
		_value.to(plot_nfts);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Farmer_get_partial_diffs& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Farmer_get_partial_diffs& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Farmer_get_partial_diffs::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Farmer_get_partial_diffs::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Farmer.get_partial_diffs";
	type_code->type_hash = vnx::Hash64(0x8806f6763215c58bull);
	type_code->code_hash = vnx::Hash64(0xeff9197ef3d645f9ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Farmer_get_partial_diffs);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Farmer_get_partial_diffs>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Farmer_get_partial_diffs_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "plot_nfts";
		field.code = {12, 11, 32, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Farmer_get_partial_diffs& value, const TypeCode* type_code, const uint16_t* code) {
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
	in.read(type_code->total_field_size);
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.plot_nfts, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Farmer_get_partial_diffs& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Farmer_get_partial_diffs;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Farmer_get_partial_diffs>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.plot_nfts, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::Farmer_get_partial_diffs& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Farmer_get_partial_diffs& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Farmer_get_partial_diffs& value) {
	value.accept(visitor);
}

} // vnx
