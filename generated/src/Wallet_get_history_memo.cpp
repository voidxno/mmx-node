
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Wallet_get_history_memo.hxx>
#include <mmx/Wallet_get_history_memo_return.hxx>
#include <mmx/query_filter_t.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Wallet_get_history_memo::VNX_TYPE_HASH(0xcbe6c5855e8776baull);
const vnx::Hash64 Wallet_get_history_memo::VNX_CODE_HASH(0x46084f0cec13f816ull);

vnx::Hash64 Wallet_get_history_memo::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Wallet_get_history_memo::get_type_name() const {
	return "mmx.Wallet.get_history_memo";
}

const vnx::TypeCode* Wallet_get_history_memo::get_type_code() const {
	return mmx::vnx_native_type_code_Wallet_get_history_memo;
}

std::shared_ptr<Wallet_get_history_memo> Wallet_get_history_memo::create() {
	return std::make_shared<Wallet_get_history_memo>();
}

std::shared_ptr<vnx::Value> Wallet_get_history_memo::clone() const {
	return std::make_shared<Wallet_get_history_memo>(*this);
}

void Wallet_get_history_memo::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Wallet_get_history_memo::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Wallet_get_history_memo::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Wallet_get_history_memo;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, index);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, memo);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, filter);
	_visitor.type_end(*_type_code);
}

void Wallet_get_history_memo::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Wallet.get_history_memo\"";
	_out << ", \"index\": "; vnx::write(_out, index);
	_out << ", \"memo\": "; vnx::write(_out, memo);
	_out << ", \"filter\": "; vnx::write(_out, filter);
	_out << "}";
}

void Wallet_get_history_memo::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Wallet_get_history_memo::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Wallet.get_history_memo";
	_object["index"] = index;
	_object["memo"] = memo;
	_object["filter"] = filter;
	return _object;
}

void Wallet_get_history_memo::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "filter") {
			_entry.second.to(filter);
		} else if(_entry.first == "index") {
			_entry.second.to(index);
		} else if(_entry.first == "memo") {
			_entry.second.to(memo);
		}
	}
}

vnx::Variant Wallet_get_history_memo::get_field(const std::string& _name) const {
	if(_name == "index") {
		return vnx::Variant(index);
	}
	if(_name == "memo") {
		return vnx::Variant(memo);
	}
	if(_name == "filter") {
		return vnx::Variant(filter);
	}
	return vnx::Variant();
}

void Wallet_get_history_memo::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "index") {
		_value.to(index);
	} else if(_name == "memo") {
		_value.to(memo);
	} else if(_name == "filter") {
		_value.to(filter);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Wallet_get_history_memo& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Wallet_get_history_memo& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Wallet_get_history_memo::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Wallet_get_history_memo::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Wallet.get_history_memo";
	type_code->type_hash = vnx::Hash64(0xcbe6c5855e8776baull);
	type_code->code_hash = vnx::Hash64(0x46084f0cec13f816ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Wallet_get_history_memo);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Wallet_get_history_memo>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::query_filter_t::static_get_type_code();
	type_code->is_const = true;
	type_code->return_type = ::mmx::Wallet_get_history_memo_return::static_get_type_code();
	type_code->fields.resize(3);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "index";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "memo";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "filter";
		field.code = {19, 0};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Wallet_get_history_memo& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 1: vnx::read(in, value.memo, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.filter, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Wallet_get_history_memo& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Wallet_get_history_memo;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Wallet_get_history_memo>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.index);
	vnx::write(out, value.memo, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.filter, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::Wallet_get_history_memo& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Wallet_get_history_memo& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Wallet_get_history_memo& value) {
	value.accept(visitor);
}

} // vnx
