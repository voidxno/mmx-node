/*
 * mmx_node.cpp
 *
 *  Created on: Dec 10, 2021
 *      Author: mad
 */

#include <mmx/Node.h>
#include <mmx/Wallet.h>
#include <mmx/TimeLord.h>
#include <mmx/Farmer.h>
#include <mmx/Harvester.h>
#include <mmx/Router.h>
#include <mmx/WalletClient.hxx>
#include <mmx/secp256k1.hpp>
#include <mmx/utils.h>

#include <vnx/vnx.h>
#include <vnx/Server.h>
#include <vnx/Terminal.h>
#include <vnx/TcpEndpoint.hxx>
#include <vnx/addons/HttpServer.h>


int main(int argc, char** argv)
{
	mmx::secp256k1_init();

	std::map<std::string, std::string> options;
	options["t"] = "timelord";

	vnx::init("mmx_node", argc, argv, options);

	const auto params = mmx::get_params();

	if(params->vdf_seed == "test1" || params->vdf_seed == "test2") {
		vnx::log_error() << "This version is not compatible with testnet1/2, please remove NETWORK file and try again to switch to testnet3.";
		vnx::close();
		return -1;
	}
	bool with_farmer = true;
	bool with_wallet = true;
	bool with_timelord = true;
	bool with_harvester = true;
	bool light_mode = false;
	std::string endpoint = ":11331";
	std::string public_endpoint = "0.0.0.0:11330";
	std::string root_path;
	vnx::read_config("wallet", with_wallet);
	vnx::read_config("farmer", with_farmer);
	vnx::read_config("timelord", with_timelord);
	vnx::read_config("harvester", with_harvester);
	vnx::read_config("light_mode", light_mode);
	vnx::read_config("endpoint", endpoint);
	vnx::read_config("public_endpoint", public_endpoint);
	vnx::read_config("root_path", root_path);

#ifdef WITH_OPENCL
	try {
		std::string platform_name;
		vnx::read_config("opencl.platform", platform_name);
		automy::basic_opencl::create_context(CL_DEVICE_TYPE_GPU, platform_name);
	}
	catch(const std::exception& ex) {
		vnx::log_info() << "No OpenCL GPU platform found: " << ex.what();
	}
#endif

	if(light_mode) {
		with_farmer = false;
		with_timelord = false;
		root_path += "light_node/";
	}
	if(!root_path.empty()) {
		vnx::Directory(root_path).create();
	}
	if(with_farmer) {
		with_wallet = true;
	} else {
		with_harvester = false;
	}

	{
		vnx::Handle<vnx::Terminal> module = new vnx::Terminal("Terminal");
		module.start_detached();
	}
	{
		vnx::Handle<vnx::Server> module = new vnx::Server("Server0", vnx::Endpoint::from_url(public_endpoint));
		module.start_detached();
	}
	{
		vnx::Handle<vnx::Server> module = new vnx::Server("Server1", vnx::Endpoint::from_url(endpoint));
		module.start_detached();
	}
	if(with_wallet) {
		vnx::Handle<mmx::Wallet> module = new mmx::Wallet("Wallet");
		module.start_detached();
		{
			vnx::Handle<vnx::Server> module = new vnx::Server("Server5", vnx::Endpoint::from_url(":11335"));
			module.start_detached();
		}
	}
	if(light_mode) {
		std::vector<mmx::addr_t> light_set;
		vnx::File file(root_path + "light_address_set.dat");
		if(file.exists()) {
			file.open("rb");
			vnx::read_generic(file.in, light_set);
		} else {
			mmx::WalletClient wallet("Wallet");
			light_set = wallet.get_all_addresses(-1);
			file.open("wb");
			vnx::write_generic(file.out, light_set);
		}
		vnx::write_config("light_address_set", light_set);
	}
	{
		vnx::Handle<vnx::addons::HttpServer> module = new vnx::addons::HttpServer("HttpServer");
		module->components["/api/node/"] = "Node";
		module->components["/api/wallet/"] = "Wallet";
		module.start_detached();
	}
	{
		vnx::Handle<mmx::Router> module = new mmx::Router("Router");
		module->storage_path = root_path + module->storage_path;
		module.start_detached();
	}
	if(with_timelord) {
		vnx::Handle<mmx::TimeLord> module = new mmx::TimeLord("TimeLord");
		module.start_detached();
		{
			vnx::Handle<vnx::Server> module = new vnx::Server("Server2", vnx::Endpoint::from_url(":11332"));
			module.start_detached();
		}
	}
	if(with_farmer) {
		vnx::Handle<mmx::Farmer> module = new mmx::Farmer("Farmer");
		module.start_detached();
		{
			vnx::Handle<vnx::Server> module = new vnx::Server("Server3", vnx::Endpoint::from_url(":11333"));
			module.start_detached();
		}
	}
	if(with_harvester) {
		vnx::Handle<mmx::Harvester> module = new mmx::Harvester("Harvester");
		module.start_detached();
	}

	while(vnx::do_run())
	{
		vnx::Handle<mmx::Node> module = new mmx::Node("Node");
		module->storage_path = root_path + module->storage_path;
		module->database_path = root_path + module->database_path;
		module.start();
		module.wait();
	}
	vnx::close();

	mmx::secp256k1_free();

#ifdef WITH_OPENCL
	automy::basic_opencl::release_context();
#endif

	return 0;
}


