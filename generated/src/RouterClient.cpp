
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/RouterClient.hxx>
#include <mmx/Block.hxx>
#include <mmx/PeerInfo.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/Router_discover.hxx>
#include <mmx/Router_discover_return.hxx>
#include <mmx/Router_fetch_block.hxx>
#include <mmx/Router_fetch_block_return.hxx>
#include <mmx/Router_fetch_block_at.hxx>
#include <mmx/Router_fetch_block_at_return.hxx>
#include <mmx/Router_get_blocks_at.hxx>
#include <mmx/Router_get_blocks_at_return.hxx>
#include <mmx/Router_get_connected_peers.hxx>
#include <mmx/Router_get_connected_peers_return.hxx>
#include <mmx/Router_get_id.hxx>
#include <mmx/Router_get_id_return.hxx>
#include <mmx/Router_get_info.hxx>
#include <mmx/Router_get_info_return.hxx>
#include <mmx/Router_get_known_peers.hxx>
#include <mmx/Router_get_known_peers_return.hxx>
#include <mmx/Router_get_peer_info.hxx>
#include <mmx/Router_get_peer_info_return.hxx>
#include <mmx/Router_get_peers.hxx>
#include <mmx/Router_get_peers_return.hxx>
#include <mmx/Router_kick_peer.hxx>
#include <mmx/Router_kick_peer_return.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/node_info_t.hxx>
#include <mmx/node_type_e.hxx>
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
#include <vnx/addons/MsgServer.h>

#include <vnx/Generic.hxx>
#include <vnx/vnx.h>


namespace mmx {

RouterClient::RouterClient(const std::string& service_name)
	:	Client::Client(vnx::Hash64(service_name))
{
}

RouterClient::RouterClient(vnx::Hash64 service_addr)
	:	Client::Client(service_addr)
{
}

void RouterClient::discover() {
	auto _method = ::mmx::Router_discover::create();
	vnx_request(_method, false);
}

void RouterClient::discover_async() {
	auto _method = ::mmx::Router_discover::create();
	vnx_request(_method, true);
}

::mmx::hash_t RouterClient::get_id() {
	auto _method = ::mmx::Router_get_id::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_get_id_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::hash_t>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

::mmx::node_info_t RouterClient::get_info() {
	auto _method = ::mmx::Router_get_info::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_get_info_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::mmx::node_info_t>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::vector<std::string> RouterClient::get_peers(const uint32_t& max_count) {
	auto _method = ::mmx::Router_get_peers::create();
	_method->max_count = max_count;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_get_peers_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<std::string>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::vector<std::string> RouterClient::get_known_peers() {
	auto _method = ::mmx::Router_get_known_peers::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_get_known_peers_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<std::string>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::vector<std::string> RouterClient::get_connected_peers() {
	auto _method = ::mmx::Router_get_connected_peers::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_get_connected_peers_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<std::string>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::shared_ptr<const ::mmx::PeerInfo> RouterClient::get_peer_info() {
	auto _method = ::mmx::Router_get_peer_info::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_get_peer_info_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::mmx::PeerInfo>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

void RouterClient::kick_peer(const std::string& address) {
	auto _method = ::mmx::Router_kick_peer::create();
	_method->address = address;
	vnx_request(_method, false);
}

void RouterClient::kick_peer_async(const std::string& address) {
	auto _method = ::mmx::Router_kick_peer::create();
	_method->address = address;
	vnx_request(_method, true);
}

std::vector<std::shared_ptr<const ::mmx::Block>> RouterClient::get_blocks_at(const uint32_t& height) {
	auto _method = ::mmx::Router_get_blocks_at::create();
	_method->height = height;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_get_blocks_at_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::vector<std::shared_ptr<const ::mmx::Block>>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::shared_ptr<const ::mmx::Block> RouterClient::fetch_block(const ::mmx::hash_t& hash, const vnx::optional<std::string>& address) {
	auto _method = ::mmx::Router_fetch_block::create();
	_method->hash = hash;
	_method->address = address;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_fetch_block_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::mmx::Block>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::shared_ptr<const ::mmx::Block> RouterClient::fetch_block_at(const uint32_t& height, const std::string& address) {
	auto _method = ::mmx::Router_fetch_block_at::create();
	_method->height = height;
	_method->address = address;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::mmx::Router_fetch_block_at_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::mmx::Block>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::shared_ptr<const ::vnx::addons::HttpResponse> RouterClient::http_request(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path) {
	auto _method = ::vnx::addons::HttpComponent_http_request::create();
	_method->request = request;
	_method->sub_path = sub_path;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::addons::HttpComponent_http_request_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::addons::HttpResponse>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::shared_ptr<const ::vnx::addons::HttpData> RouterClient::http_request_chunk(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const int64_t& offset, const int64_t& max_bytes) {
	auto _method = ::vnx::addons::HttpComponent_http_request_chunk::create();
	_method->request = request;
	_method->sub_path = sub_path;
	_method->offset = offset;
	_method->max_bytes = max_bytes;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::addons::HttpComponent_http_request_chunk_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::addons::HttpData>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

::vnx::Object RouterClient::vnx_get_config_object() {
	auto _method = ::vnx::ModuleInterface_vnx_get_config_object::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::Object>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

::vnx::Variant RouterClient::vnx_get_config(const std::string& name) {
	auto _method = ::vnx::ModuleInterface_vnx_get_config::create();
	_method->name = name;
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::Variant>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

void RouterClient::vnx_set_config_object(const ::vnx::Object& config) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	vnx_request(_method, false);
}

void RouterClient::vnx_set_config_object_async(const ::vnx::Object& config) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config_object::create();
	_method->config = config;
	vnx_request(_method, true);
}

void RouterClient::vnx_set_config(const std::string& name, const ::vnx::Variant& value) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	vnx_request(_method, false);
}

void RouterClient::vnx_set_config_async(const std::string& name, const ::vnx::Variant& value) {
	auto _method = ::vnx::ModuleInterface_vnx_set_config::create();
	_method->name = name;
	_method->value = value;
	vnx_request(_method, true);
}

::vnx::TypeCode RouterClient::vnx_get_type_code() {
	auto _method = ::vnx::ModuleInterface_vnx_get_type_code::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<::vnx::TypeCode>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

std::shared_ptr<const ::vnx::ModuleInfo> RouterClient::vnx_get_module_info() {
	auto _method = ::vnx::ModuleInterface_vnx_get_module_info::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<std::shared_ptr<const ::vnx::ModuleInfo>>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}

void RouterClient::vnx_restart() {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	vnx_request(_method, false);
}

void RouterClient::vnx_restart_async() {
	auto _method = ::vnx::ModuleInterface_vnx_restart::create();
	vnx_request(_method, true);
}

void RouterClient::vnx_stop() {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	vnx_request(_method, false);
}

void RouterClient::vnx_stop_async() {
	auto _method = ::vnx::ModuleInterface_vnx_stop::create();
	vnx_request(_method, true);
}

vnx::bool_t RouterClient::vnx_self_test() {
	auto _method = ::vnx::ModuleInterface_vnx_self_test::create();
	auto _return_value = vnx_request(_method, false);
	if(auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test_return>(_return_value)) {
		return _result->_ret_0;
	} else if(_return_value && !_return_value->is_void()) {
		return _return_value->get_field_by_index(0).to<vnx::bool_t>();
	} else {
		throw std::logic_error("RouterClient: invalid return value");
	}
}


} // namespace mmx
