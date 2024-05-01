
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/block_index_t.hxx>
#include <mmx/hash_t.hpp>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 block_index_t::VNX_TYPE_HASH(0xd00c722670bca900ull);
const vnx::Hash64 block_index_t::VNX_CODE_HASH(0x457ce85ac9b66218ull);

vnx::Hash64 block_index_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string block_index_t::get_type_name() const {
	return "mmx.block_index_t";
}

const vnx::TypeCode* block_index_t::get_type_code() const {
	return mmx::vnx_native_type_code_block_index_t;
}

std::shared_ptr<block_index_t> block_index_t::create() {
	return std::make_shared<block_index_t>();
}

std::shared_ptr<block_index_t> block_index_t::clone() const {
	return std::make_shared<block_index_t>(*this);
}

void block_index_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void block_index_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void block_index_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_block_index_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, hash);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, content_hash);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, static_cost);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, total_cost);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, file_offset);
	_visitor.type_end(*_type_code);
}

void block_index_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"hash\": "; vnx::write(_out, hash);
	_out << ", \"content_hash\": "; vnx::write(_out, content_hash);
	_out << ", \"static_cost\": "; vnx::write(_out, static_cost);
	_out << ", \"total_cost\": "; vnx::write(_out, total_cost);
	_out << ", \"file_offset\": "; vnx::write(_out, file_offset);
	_out << "}";
}

void block_index_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object block_index_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.block_index_t";
	_object["hash"] = hash;
	_object["content_hash"] = content_hash;
	_object["static_cost"] = static_cost;
	_object["total_cost"] = total_cost;
	_object["file_offset"] = file_offset;
	return _object;
}

void block_index_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "content_hash") {
			_entry.second.to(content_hash);
		} else if(_entry.first == "file_offset") {
			_entry.second.to(file_offset);
		} else if(_entry.first == "hash") {
			_entry.second.to(hash);
		} else if(_entry.first == "static_cost") {
			_entry.second.to(static_cost);
		} else if(_entry.first == "total_cost") {
			_entry.second.to(total_cost);
		}
	}
}

vnx::Variant block_index_t::get_field(const std::string& _name) const {
	if(_name == "hash") {
		return vnx::Variant(hash);
	}
	if(_name == "content_hash") {
		return vnx::Variant(content_hash);
	}
	if(_name == "static_cost") {
		return vnx::Variant(static_cost);
	}
	if(_name == "total_cost") {
		return vnx::Variant(total_cost);
	}
	if(_name == "file_offset") {
		return vnx::Variant(file_offset);
	}
	return vnx::Variant();
}

void block_index_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "hash") {
		_value.to(hash);
	} else if(_name == "content_hash") {
		_value.to(content_hash);
	} else if(_name == "static_cost") {
		_value.to(static_cost);
	} else if(_name == "total_cost") {
		_value.to(total_cost);
	} else if(_name == "file_offset") {
		_value.to(file_offset);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const block_index_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, block_index_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* block_index_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> block_index_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.block_index_t";
	type_code->type_hash = vnx::Hash64(0xd00c722670bca900ull);
	type_code->code_hash = vnx::Hash64(0x457ce85ac9b66218ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::block_index_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<block_index_t>>(); };
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "hash";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "content_hash";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "static_cost";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "total_cost";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 8;
		field.name = "file_offset";
		field.code = {8};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::block_index_t& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.static_cost, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.total_cost, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.file_offset, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.hash, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.content_hash, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::block_index_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_block_index_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::block_index_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(16);
	vnx::write_value(_buf + 0, value.static_cost);
	vnx::write_value(_buf + 4, value.total_cost);
	vnx::write_value(_buf + 8, value.file_offset);
	vnx::write(out, value.hash, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.content_hash, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::block_index_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::block_index_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::block_index_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::block_index_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::block_index_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
