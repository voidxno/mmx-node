
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/spend_options_t.hxx>
#include <mmx/Contract.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/tx_note_e.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 spend_options_t::VNX_TYPE_HASH(0x37f7c6d377362e95ull);
const vnx::Hash64 spend_options_t::VNX_CODE_HASH(0x963a75717405eaebull);

vnx::Hash64 spend_options_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string spend_options_t::get_type_name() const {
	return "mmx.spend_options_t";
}

const vnx::TypeCode* spend_options_t::get_type_code() const {
	return mmx::vnx_native_type_code_spend_options_t;
}

std::shared_ptr<spend_options_t> spend_options_t::create() {
	return std::make_shared<spend_options_t>();
}

std::shared_ptr<spend_options_t> spend_options_t::clone() const {
	return std::make_shared<spend_options_t>(*this);
}

void spend_options_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void spend_options_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void spend_options_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_spend_options_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, auto_send);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, fee_ratio);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, max_extra_cost);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, expire_at);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, expire_delta);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, user);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, sender);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, passphrase);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, note);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, memo);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, owner_map);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, contract_map);
	_visitor.type_end(*_type_code);
}

void spend_options_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"auto_send\": "; vnx::write(_out, auto_send);
	_out << ", \"fee_ratio\": "; vnx::write(_out, fee_ratio);
	_out << ", \"max_extra_cost\": "; vnx::write(_out, max_extra_cost);
	_out << ", \"expire_at\": "; vnx::write(_out, expire_at);
	_out << ", \"expire_delta\": "; vnx::write(_out, expire_delta);
	_out << ", \"user\": "; vnx::write(_out, user);
	_out << ", \"sender\": "; vnx::write(_out, sender);
	_out << ", \"passphrase\": "; vnx::write(_out, passphrase);
	_out << ", \"note\": "; vnx::write(_out, note);
	_out << ", \"memo\": "; vnx::write(_out, memo);
	_out << ", \"owner_map\": "; vnx::write(_out, owner_map);
	_out << ", \"contract_map\": "; vnx::write(_out, contract_map);
	_out << "}";
}

void spend_options_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object spend_options_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.spend_options_t";
	_object["auto_send"] = auto_send;
	_object["fee_ratio"] = fee_ratio;
	_object["max_extra_cost"] = max_extra_cost;
	_object["expire_at"] = expire_at;
	_object["expire_delta"] = expire_delta;
	_object["user"] = user;
	_object["sender"] = sender;
	_object["passphrase"] = passphrase;
	_object["note"] = note;
	_object["memo"] = memo;
	_object["owner_map"] = owner_map;
	_object["contract_map"] = contract_map;
	return _object;
}

void spend_options_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "auto_send") {
			_entry.second.to(auto_send);
		} else if(_entry.first == "contract_map") {
			_entry.second.to(contract_map);
		} else if(_entry.first == "expire_at") {
			_entry.second.to(expire_at);
		} else if(_entry.first == "expire_delta") {
			_entry.second.to(expire_delta);
		} else if(_entry.first == "fee_ratio") {
			_entry.second.to(fee_ratio);
		} else if(_entry.first == "max_extra_cost") {
			_entry.second.to(max_extra_cost);
		} else if(_entry.first == "memo") {
			_entry.second.to(memo);
		} else if(_entry.first == "note") {
			_entry.second.to(note);
		} else if(_entry.first == "owner_map") {
			_entry.second.to(owner_map);
		} else if(_entry.first == "passphrase") {
			_entry.second.to(passphrase);
		} else if(_entry.first == "sender") {
			_entry.second.to(sender);
		} else if(_entry.first == "user") {
			_entry.second.to(user);
		}
	}
}

vnx::Variant spend_options_t::get_field(const std::string& _name) const {
	if(_name == "auto_send") {
		return vnx::Variant(auto_send);
	}
	if(_name == "fee_ratio") {
		return vnx::Variant(fee_ratio);
	}
	if(_name == "max_extra_cost") {
		return vnx::Variant(max_extra_cost);
	}
	if(_name == "expire_at") {
		return vnx::Variant(expire_at);
	}
	if(_name == "expire_delta") {
		return vnx::Variant(expire_delta);
	}
	if(_name == "user") {
		return vnx::Variant(user);
	}
	if(_name == "sender") {
		return vnx::Variant(sender);
	}
	if(_name == "passphrase") {
		return vnx::Variant(passphrase);
	}
	if(_name == "note") {
		return vnx::Variant(note);
	}
	if(_name == "memo") {
		return vnx::Variant(memo);
	}
	if(_name == "owner_map") {
		return vnx::Variant(owner_map);
	}
	if(_name == "contract_map") {
		return vnx::Variant(contract_map);
	}
	return vnx::Variant();
}

void spend_options_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "auto_send") {
		_value.to(auto_send);
	} else if(_name == "fee_ratio") {
		_value.to(fee_ratio);
	} else if(_name == "max_extra_cost") {
		_value.to(max_extra_cost);
	} else if(_name == "expire_at") {
		_value.to(expire_at);
	} else if(_name == "expire_delta") {
		_value.to(expire_delta);
	} else if(_name == "user") {
		_value.to(user);
	} else if(_name == "sender") {
		_value.to(sender);
	} else if(_name == "passphrase") {
		_value.to(passphrase);
	} else if(_name == "note") {
		_value.to(note);
	} else if(_name == "memo") {
		_value.to(memo);
	} else if(_name == "owner_map") {
		_value.to(owner_map);
	} else if(_name == "contract_map") {
		_value.to(contract_map);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const spend_options_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, spend_options_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* spend_options_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> spend_options_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.spend_options_t";
	type_code->type_hash = vnx::Hash64(0x37f7c6d377362e95ull);
	type_code->code_hash = vnx::Hash64(0x963a75717405eaebull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::spend_options_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<spend_options_t>>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::tx_note_e::static_get_type_code();
	type_code->fields.resize(12);
	{
		auto& field = type_code->fields[0];
		field.data_size = 1;
		field.name = "auto_send";
		field.value = vnx::to_string(true);
		field.code = {31};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "fee_ratio";
		field.value = vnx::to_string(1024);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "max_extra_cost";
		field.value = vnx::to_string(5000000);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "expire_at";
		field.code = {33, 3};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "expire_delta";
		field.code = {33, 3};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "user";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "sender";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[7];
		field.is_extended = true;
		field.name = "passphrase";
		field.code = {33, 32};
	}
	{
		auto& field = type_code->fields[8];
		field.is_extended = true;
		field.name = "note";
		field.code = {33, 19, 0};
	}
	{
		auto& field = type_code->fields[9];
		field.is_extended = true;
		field.name = "memo";
		field.code = {33, 32};
	}
	{
		auto& field = type_code->fields[10];
		field.is_extended = true;
		field.name = "owner_map";
		field.code = {13, 5, 11, 32, 1, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[11];
		field.is_extended = true;
		field.name = "contract_map";
		field.code = {13, 5, 11, 32, 1, 16};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::spend_options_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.auto_send, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.fee_ratio, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.max_extra_cost, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 3: vnx::read(in, value.expire_at, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.expire_delta, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.user, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.sender, type_code, _field->code.data()); break;
			case 7: vnx::read(in, value.passphrase, type_code, _field->code.data()); break;
			case 8: vnx::read(in, value.note, type_code, _field->code.data()); break;
			case 9: vnx::read(in, value.memo, type_code, _field->code.data()); break;
			case 10: vnx::read(in, value.owner_map, type_code, _field->code.data()); break;
			case 11: vnx::read(in, value.contract_map, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::spend_options_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_spend_options_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::spend_options_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(9);
	vnx::write_value(_buf + 0, value.auto_send);
	vnx::write_value(_buf + 1, value.fee_ratio);
	vnx::write_value(_buf + 5, value.max_extra_cost);
	vnx::write(out, value.expire_at, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.expire_delta, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.user, type_code, type_code->fields[5].code.data());
	vnx::write(out, value.sender, type_code, type_code->fields[6].code.data());
	vnx::write(out, value.passphrase, type_code, type_code->fields[7].code.data());
	vnx::write(out, value.note, type_code, type_code->fields[8].code.data());
	vnx::write(out, value.memo, type_code, type_code->fields[9].code.data());
	vnx::write(out, value.owner_map, type_code, type_code->fields[10].code.data());
	vnx::write(out, value.contract_map, type_code, type_code->fields[11].code.data());
}

void read(std::istream& in, ::mmx::spend_options_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::spend_options_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::spend_options_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::spend_options_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::spend_options_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
