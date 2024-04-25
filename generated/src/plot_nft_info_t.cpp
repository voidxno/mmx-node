
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/plot_nft_info_t.hxx>
#include <mmx/addr_t.hpp>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 plot_nft_info_t::VNX_TYPE_HASH(0xf8e0b44f3c0a54aeull);
const vnx::Hash64 plot_nft_info_t::VNX_CODE_HASH(0x355b43a932bc2c3aull);

vnx::Hash64 plot_nft_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string plot_nft_info_t::get_type_name() const {
	return "mmx.plot_nft_info_t";
}

const vnx::TypeCode* plot_nft_info_t::get_type_code() const {
	return mmx::vnx_native_type_code_plot_nft_info_t;
}

std::shared_ptr<plot_nft_info_t> plot_nft_info_t::create() {
	return std::make_shared<plot_nft_info_t>();
}

std::shared_ptr<plot_nft_info_t> plot_nft_info_t::clone() const {
	return std::make_shared<plot_nft_info_t>(*this);
}

void plot_nft_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void plot_nft_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void plot_nft_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_plot_nft_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, owner);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, target);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, address);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, is_locked);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, unlock_height);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, unlock_delay);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, server_url);
	_visitor.type_end(*_type_code);
}

void plot_nft_info_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"owner\": "; vnx::write(_out, owner);
	_out << ", \"target\": "; vnx::write(_out, target);
	_out << ", \"address\": "; vnx::write(_out, address);
	_out << ", \"is_locked\": "; vnx::write(_out, is_locked);
	_out << ", \"unlock_height\": "; vnx::write(_out, unlock_height);
	_out << ", \"unlock_delay\": "; vnx::write(_out, unlock_delay);
	_out << ", \"server_url\": "; vnx::write(_out, server_url);
	_out << "}";
}

void plot_nft_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object plot_nft_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.plot_nft_info_t";
	_object["owner"] = owner;
	_object["target"] = target;
	_object["address"] = address;
	_object["is_locked"] = is_locked;
	_object["unlock_height"] = unlock_height;
	_object["unlock_delay"] = unlock_delay;
	_object["server_url"] = server_url;
	return _object;
}

void plot_nft_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		} else if(_entry.first == "is_locked") {
			_entry.second.to(is_locked);
		} else if(_entry.first == "owner") {
			_entry.second.to(owner);
		} else if(_entry.first == "server_url") {
			_entry.second.to(server_url);
		} else if(_entry.first == "target") {
			_entry.second.to(target);
		} else if(_entry.first == "unlock_delay") {
			_entry.second.to(unlock_delay);
		} else if(_entry.first == "unlock_height") {
			_entry.second.to(unlock_height);
		}
	}
}

vnx::Variant plot_nft_info_t::get_field(const std::string& _name) const {
	if(_name == "owner") {
		return vnx::Variant(owner);
	}
	if(_name == "target") {
		return vnx::Variant(target);
	}
	if(_name == "address") {
		return vnx::Variant(address);
	}
	if(_name == "is_locked") {
		return vnx::Variant(is_locked);
	}
	if(_name == "unlock_height") {
		return vnx::Variant(unlock_height);
	}
	if(_name == "unlock_delay") {
		return vnx::Variant(unlock_delay);
	}
	if(_name == "server_url") {
		return vnx::Variant(server_url);
	}
	return vnx::Variant();
}

void plot_nft_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "owner") {
		_value.to(owner);
	} else if(_name == "target") {
		_value.to(target);
	} else if(_name == "address") {
		_value.to(address);
	} else if(_name == "is_locked") {
		_value.to(is_locked);
	} else if(_name == "unlock_height") {
		_value.to(unlock_height);
	} else if(_name == "unlock_delay") {
		_value.to(unlock_delay);
	} else if(_name == "server_url") {
		_value.to(server_url);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const plot_nft_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, plot_nft_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* plot_nft_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> plot_nft_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.plot_nft_info_t";
	type_code->type_hash = vnx::Hash64(0xf8e0b44f3c0a54aeull);
	type_code->code_hash = vnx::Hash64(0x355b43a932bc2c3aull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::plot_nft_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<plot_nft_info_t>>(); };
	type_code->fields.resize(7);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "owner";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "target";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 1;
		field.name = "is_locked";
		field.code = {31};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 4;
		field.name = "unlock_height";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[5];
		field.data_size = 4;
		field.name = "unlock_delay";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "server_url";
		field.code = {32};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::plot_nft_info_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.is_locked, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.unlock_height, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[5]) {
			vnx::read_value(_buf + _field->offset, value.unlock_delay, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.owner, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.target, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.address, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.server_url, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::plot_nft_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_plot_nft_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::plot_nft_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(9);
	vnx::write_value(_buf + 0, value.is_locked);
	vnx::write_value(_buf + 1, value.unlock_height);
	vnx::write_value(_buf + 5, value.unlock_delay);
	vnx::write(out, value.owner, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.target, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.address, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.server_url, type_code, type_code->fields[6].code.data());
}

void read(std::istream& in, ::mmx::plot_nft_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::plot_nft_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::plot_nft_info_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::plot_nft_info_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::plot_nft_info_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
