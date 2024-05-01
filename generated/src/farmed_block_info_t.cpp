
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/farmed_block_info_t.hxx>
#include <mmx/addr_t.hpp>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 farmed_block_info_t::VNX_TYPE_HASH(0x2e10154a52617b19ull);
const vnx::Hash64 farmed_block_info_t::VNX_CODE_HASH(0xf131225aa531d24dull);

vnx::Hash64 farmed_block_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string farmed_block_info_t::get_type_name() const {
	return "mmx.farmed_block_info_t";
}

const vnx::TypeCode* farmed_block_info_t::get_type_code() const {
	return mmx::vnx_native_type_code_farmed_block_info_t;
}

std::shared_ptr<farmed_block_info_t> farmed_block_info_t::create() {
	return std::make_shared<farmed_block_info_t>();
}

std::shared_ptr<farmed_block_info_t> farmed_block_info_t::clone() const {
	return std::make_shared<farmed_block_info_t>(*this);
}

void farmed_block_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void farmed_block_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void farmed_block_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_farmed_block_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, height);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, reward);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, reward_addr);
	_visitor.type_end(*_type_code);
}

void farmed_block_info_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"height\": "; vnx::write(_out, height);
	_out << ", \"reward\": "; vnx::write(_out, reward);
	_out << ", \"reward_addr\": "; vnx::write(_out, reward_addr);
	_out << "}";
}

void farmed_block_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object farmed_block_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.farmed_block_info_t";
	_object["height"] = height;
	_object["reward"] = reward;
	_object["reward_addr"] = reward_addr;
	return _object;
}

void farmed_block_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "height") {
			_entry.second.to(height);
		} else if(_entry.first == "reward") {
			_entry.second.to(reward);
		} else if(_entry.first == "reward_addr") {
			_entry.second.to(reward_addr);
		}
	}
}

vnx::Variant farmed_block_info_t::get_field(const std::string& _name) const {
	if(_name == "height") {
		return vnx::Variant(height);
	}
	if(_name == "reward") {
		return vnx::Variant(reward);
	}
	if(_name == "reward_addr") {
		return vnx::Variant(reward_addr);
	}
	return vnx::Variant();
}

void farmed_block_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "height") {
		_value.to(height);
	} else if(_name == "reward") {
		_value.to(reward);
	} else if(_name == "reward_addr") {
		_value.to(reward_addr);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const farmed_block_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, farmed_block_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* farmed_block_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> farmed_block_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.farmed_block_info_t";
	type_code->type_hash = vnx::Hash64(0x2e10154a52617b19ull);
	type_code->code_hash = vnx::Hash64(0xf131225aa531d24dull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::farmed_block_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<farmed_block_info_t>>(); };
	type_code->fields.resize(3);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "height";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "reward";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "reward_addr";
		field.code = {11, 32, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::farmed_block_info_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.height, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.reward, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 2: vnx::read(in, value.reward_addr, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::farmed_block_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_farmed_block_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::farmed_block_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.height);
	vnx::write_value(_buf + 4, value.reward);
	vnx::write(out, value.reward_addr, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::farmed_block_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::farmed_block_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::farmed_block_info_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::farmed_block_info_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::farmed_block_info_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
