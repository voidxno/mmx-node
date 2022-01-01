
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/PeerInfo.hxx>
#include <mmx/peer_info_t.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 PeerInfo::VNX_TYPE_HASH(0xf7a37f624c94a121ull);
const vnx::Hash64 PeerInfo::VNX_CODE_HASH(0xb3f7c69dd667175eull);

vnx::Hash64 PeerInfo::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string PeerInfo::get_type_name() const {
	return "mmx.PeerInfo";
}

const vnx::TypeCode* PeerInfo::get_type_code() const {
	return mmx::vnx_native_type_code_PeerInfo;
}

std::shared_ptr<PeerInfo> PeerInfo::create() {
	return std::make_shared<PeerInfo>();
}

std::shared_ptr<vnx::Value> PeerInfo::clone() const {
	return std::make_shared<PeerInfo>(*this);
}

void PeerInfo::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void PeerInfo::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void PeerInfo::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_PeerInfo;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, peers);
	_visitor.type_end(*_type_code);
}

void PeerInfo::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.PeerInfo\"";
	_out << ", \"peers\": "; vnx::write(_out, peers);
	_out << "}";
}

void PeerInfo::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object PeerInfo::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.PeerInfo";
	_object["peers"] = peers;
	return _object;
}

void PeerInfo::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "peers") {
			_entry.second.to(peers);
		}
	}
}

vnx::Variant PeerInfo::get_field(const std::string& _name) const {
	if(_name == "peers") {
		return vnx::Variant(peers);
	}
	return vnx::Variant();
}

void PeerInfo::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "peers") {
		_value.to(peers);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const PeerInfo& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, PeerInfo& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* PeerInfo::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> PeerInfo::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.PeerInfo";
	type_code->type_hash = vnx::Hash64(0xf7a37f624c94a121ull);
	type_code->code_hash = vnx::Hash64(0xb3f7c69dd667175eull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::PeerInfo);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<PeerInfo>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::peer_info_t::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "peers";
		field.code = {12, 19, 0};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::PeerInfo& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.peers, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::PeerInfo& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_PeerInfo;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::PeerInfo>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.peers, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::PeerInfo& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::PeerInfo& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::PeerInfo& value) {
	value.accept(visitor);
}

} // vnx
