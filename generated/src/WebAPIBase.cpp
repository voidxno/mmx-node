
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/WebAPIBase.hxx>
#include <vnx/NoSuchMethod.hxx>
#include <mmx/Block.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/WebAPI_shutdown.hxx>
#include <mmx/WebAPI_shutdown_return.hxx>
#include <vnx/LogMsg.hxx>
#include <vnx/Module.h>
#include <vnx/ModuleInterface_vnx_get_config.hxx>
#include <vnx/ModuleInterface_vnx_get_config_return.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info_return.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code_return.hxx>
#include <vnx/ModuleInterface_vnx_restart.hxx>
#include <vnx/ModuleInterface_vnx_restart_return.hxx>
#include <vnx/ModuleInterface_vnx_self_test.hxx>
#include <vnx/ModuleInterface_vnx_self_test_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config.hxx>
#include <vnx/ModuleInterface_vnx_set_config_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_stop.hxx>
#include <vnx/ModuleInterface_vnx_stop_return.hxx>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/HttpComponent_http_request.hxx>
#include <vnx/addons/HttpComponent_http_request_return.hxx>
#include <vnx/addons/HttpComponent_http_request_chunk.hxx>
#include <vnx/addons/HttpComponent_http_request_chunk_return.hxx>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 WebAPIBase::VNX_TYPE_HASH(0xfe90ce601fcc0cc6ull);
const vnx::Hash64 WebAPIBase::VNX_CODE_HASH(0x96d23f9de4719838ull);

WebAPIBase::WebAPIBase(const std::string& _vnx_name)
	:	Module::Module(_vnx_name)
{
	vnx::read_config(vnx_name + ".input_blocks", input_blocks);
	vnx::read_config(vnx_name + ".input_proofs", input_proofs);
	vnx::read_config(vnx_name + ".node_server", node_server);
	vnx::read_config(vnx_name + ".wallet_server", wallet_server);
	vnx::read_config(vnx_name + ".farmer_server", farmer_server);
	vnx::read_config(vnx_name + ".exchange_server", exchange_server);
	vnx::read_config(vnx_name + ".config_path", config_path);
	vnx::read_config(vnx_name + ".max_log_history", max_log_history);
}

vnx::Hash64 WebAPIBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string WebAPIBase::get_type_name() const {
	return "mmx.WebAPI";
}

const vnx::TypeCode* WebAPIBase::get_type_code() const {
	return mmx::vnx_native_type_code_WebAPIBase;
}

void WebAPIBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_WebAPIBase;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, input_blocks);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, input_proofs);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, node_server);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, wallet_server);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, farmer_server);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, exchange_server);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, config_path);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, max_log_history);
	_visitor.type_end(*_type_code);
}

void WebAPIBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"input_blocks\": "; vnx::write(_out, input_blocks);
	_out << ", \"input_proofs\": "; vnx::write(_out, input_proofs);
	_out << ", \"node_server\": "; vnx::write(_out, node_server);
	_out << ", \"wallet_server\": "; vnx::write(_out, wallet_server);
	_out << ", \"farmer_server\": "; vnx::write(_out, farmer_server);
	_out << ", \"exchange_server\": "; vnx::write(_out, exchange_server);
	_out << ", \"config_path\": "; vnx::write(_out, config_path);
	_out << ", \"max_log_history\": "; vnx::write(_out, max_log_history);
	_out << "}";
}

void WebAPIBase::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object WebAPIBase::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.WebAPI";
	_object["input_blocks"] = input_blocks;
	_object["input_proofs"] = input_proofs;
	_object["node_server"] = node_server;
	_object["wallet_server"] = wallet_server;
	_object["farmer_server"] = farmer_server;
	_object["exchange_server"] = exchange_server;
	_object["config_path"] = config_path;
	_object["max_log_history"] = max_log_history;
	return _object;
}

void WebAPIBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "config_path") {
			_entry.second.to(config_path);
		} else if(_entry.first == "exchange_server") {
			_entry.second.to(exchange_server);
		} else if(_entry.first == "farmer_server") {
			_entry.second.to(farmer_server);
		} else if(_entry.first == "input_blocks") {
			_entry.second.to(input_blocks);
		} else if(_entry.first == "input_proofs") {
			_entry.second.to(input_proofs);
		} else if(_entry.first == "max_log_history") {
			_entry.second.to(max_log_history);
		} else if(_entry.first == "node_server") {
			_entry.second.to(node_server);
		} else if(_entry.first == "wallet_server") {
			_entry.second.to(wallet_server);
		}
	}
}

vnx::Variant WebAPIBase::get_field(const std::string& _name) const {
	if(_name == "input_blocks") {
		return vnx::Variant(input_blocks);
	}
	if(_name == "input_proofs") {
		return vnx::Variant(input_proofs);
	}
	if(_name == "node_server") {
		return vnx::Variant(node_server);
	}
	if(_name == "wallet_server") {
		return vnx::Variant(wallet_server);
	}
	if(_name == "farmer_server") {
		return vnx::Variant(farmer_server);
	}
	if(_name == "exchange_server") {
		return vnx::Variant(exchange_server);
	}
	if(_name == "config_path") {
		return vnx::Variant(config_path);
	}
	if(_name == "max_log_history") {
		return vnx::Variant(max_log_history);
	}
	return vnx::Variant();
}

void WebAPIBase::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "input_blocks") {
		_value.to(input_blocks);
	} else if(_name == "input_proofs") {
		_value.to(input_proofs);
	} else if(_name == "node_server") {
		_value.to(node_server);
	} else if(_name == "wallet_server") {
		_value.to(wallet_server);
	} else if(_name == "farmer_server") {
		_value.to(farmer_server);
	} else if(_name == "exchange_server") {
		_value.to(exchange_server);
	} else if(_name == "config_path") {
		_value.to(config_path);
	} else if(_name == "max_log_history") {
		_value.to(max_log_history);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const WebAPIBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, WebAPIBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* WebAPIBase::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> WebAPIBase::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.WebAPI";
	type_code->type_hash = vnx::Hash64(0xfe90ce601fcc0cc6ull);
	type_code->code_hash = vnx::Hash64(0x96d23f9de4719838ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::WebAPIBase);
	type_code->methods.resize(12);
	type_code->methods[0] = ::mmx::WebAPI_shutdown::static_get_type_code();
	type_code->methods[1] = ::vnx::ModuleInterface_vnx_get_config::static_get_type_code();
	type_code->methods[2] = ::vnx::ModuleInterface_vnx_get_config_object::static_get_type_code();
	type_code->methods[3] = ::vnx::ModuleInterface_vnx_get_module_info::static_get_type_code();
	type_code->methods[4] = ::vnx::ModuleInterface_vnx_get_type_code::static_get_type_code();
	type_code->methods[5] = ::vnx::ModuleInterface_vnx_restart::static_get_type_code();
	type_code->methods[6] = ::vnx::ModuleInterface_vnx_self_test::static_get_type_code();
	type_code->methods[7] = ::vnx::ModuleInterface_vnx_set_config::static_get_type_code();
	type_code->methods[8] = ::vnx::ModuleInterface_vnx_set_config_object::static_get_type_code();
	type_code->methods[9] = ::vnx::ModuleInterface_vnx_stop::static_get_type_code();
	type_code->methods[10] = ::vnx::addons::HttpComponent_http_request::static_get_type_code();
	type_code->methods[11] = ::vnx::addons::HttpComponent_http_request_chunk::static_get_type_code();
	type_code->fields.resize(8);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "input_blocks";
		field.value = vnx::to_string("node.verified_blocks");
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "input_proofs";
		field.value = vnx::to_string("harvester.proof");
		field.code = {12, 5};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "node_server";
		field.value = vnx::to_string("Node");
		field.code = {32};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "wallet_server";
		field.value = vnx::to_string("Wallet");
		field.code = {32};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "farmer_server";
		field.value = vnx::to_string("Farmer");
		field.code = {32};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "exchange_server";
		field.value = vnx::to_string("ExchClient");
		field.code = {32};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "config_path";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[7];
		field.data_size = 4;
		field.name = "max_log_history";
		field.value = vnx::to_string(10000);
		field.code = {3};
	}
	type_code->build();
	return type_code;
}

void WebAPIBase::vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) {
	const auto* _type_code = _value->get_type_code();
	while(_type_code) {
		switch(_type_code->type_hash) {
			case 0x94965d816d328467ull:
				handle(std::static_pointer_cast<const ::mmx::Block>(_value));
				return;
			case 0x816e898b36befae0ull:
				handle(std::static_pointer_cast<const ::mmx::ProofResponse>(_value));
				return;
			case 0x2a13f6d072f9b852ull:
				handle(std::static_pointer_cast<const ::vnx::LogMsg>(_value));
				return;
			default:
				_type_code = _type_code->super;
		}
	}
	handle(std::static_pointer_cast<const vnx::Value>(_value));
}

std::shared_ptr<vnx::Value> WebAPIBase::vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) {
	switch(_method->get_type_hash()) {
		case 0x75dd6111dc25b9d6ull: {
			auto _args = std::static_pointer_cast<const ::mmx::WebAPI_shutdown>(_method);
			auto _return_value = ::mmx::WebAPI_shutdown_return::create();
			shutdown();
			return _return_value;
		}
		case 0xbbc7f1a01044d294ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_return::create();
			_return_value->_ret_0 = vnx_get_config(_args->name);
			return _return_value;
		}
		case 0x17f58f68bf83abc0ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_object_return::create();
			_return_value->_ret_0 = vnx_get_config_object();
			return _return_value;
		}
		case 0xf6d82bdf66d034a1ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_module_info_return::create();
			_return_value->_ret_0 = vnx_get_module_info();
			return _return_value;
		}
		case 0x305ec4d628960e5dull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_type_code_return::create();
			_return_value->_ret_0 = vnx_get_type_code();
			return _return_value;
		}
		case 0x9e95dc280cecca1bull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_restart>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_restart_return::create();
			vnx_restart();
			return _return_value;
		}
		case 0x6ce3775b41a42697ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_self_test_return::create();
			_return_value->_ret_0 = vnx_self_test();
			return _return_value;
		}
		case 0x362aac91373958b7ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_return::create();
			vnx_set_config(_args->name, _args->value);
			return _return_value;
		}
		case 0xca30f814f17f322full: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_object_return::create();
			vnx_set_config_object(_args->config);
			return _return_value;
		}
		case 0x7ab49ce3d1bfc0d2ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_stop>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_stop_return::create();
			vnx_stop();
			return _return_value;
		}
		case 0xe0b6c38f619bad92ull: {
			auto _args = std::static_pointer_cast<const ::vnx::addons::HttpComponent_http_request>(_method);
			http_request_async(_args->request, _args->sub_path, _request_id);
			return nullptr;
		}
		case 0x97e79d08440406d5ull: {
			auto _args = std::static_pointer_cast<const ::vnx::addons::HttpComponent_http_request_chunk>(_method);
			http_request_chunk_async(_args->request, _args->sub_path, _args->offset, _args->max_bytes, _request_id);
			return nullptr;
		}
	}
	auto _ex = vnx::NoSuchMethod::create();
	_ex->method = _method->get_type_name();
	return _ex;
}

void WebAPIBase::http_request_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpResponse>& _ret_0) const {
	auto _return_value = ::vnx::addons::HttpComponent_http_request_return::create();
	_return_value->_ret_0 = _ret_0;
	vnx_async_return(_request_id, _return_value);
}

void WebAPIBase::http_request_chunk_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpData>& _ret_0) const {
	auto _return_value = ::vnx::addons::HttpComponent_http_request_chunk_return::create();
	_return_value->_ret_0 = _ret_0;
	vnx_async_return(_request_id, _return_value);
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::WebAPIBase& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[7]) {
			vnx::read_value(_buf + _field->offset, value.max_log_history, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.input_blocks, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.input_proofs, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.node_server, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.wallet_server, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.farmer_server, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.exchange_server, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.config_path, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::WebAPIBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_WebAPIBase;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::WebAPIBase>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.max_log_history);
	vnx::write(out, value.input_blocks, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.input_proofs, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.node_server, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.wallet_server, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.farmer_server, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.exchange_server, type_code, type_code->fields[5].code.data());
	vnx::write(out, value.config_path, type_code, type_code->fields[6].code.data());
}

void read(std::istream& in, ::mmx::WebAPIBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::WebAPIBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::WebAPIBase& value) {
	value.accept(visitor);
}

} // vnx
