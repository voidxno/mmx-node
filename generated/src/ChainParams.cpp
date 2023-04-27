
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/ulong_fraction_t.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 ChainParams::VNX_TYPE_HASH(0x51bba8d28881e8e7ull);
const vnx::Hash64 ChainParams::VNX_CODE_HASH(0xfeb0f44193e37315ull);

vnx::Hash64 ChainParams::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string ChainParams::get_type_name() const {
	return "mmx.ChainParams";
}

const vnx::TypeCode* ChainParams::get_type_code() const {
	return mmx::vnx_native_type_code_ChainParams;
}

std::shared_ptr<ChainParams> ChainParams::create() {
	return std::make_shared<ChainParams>();
}

std::shared_ptr<vnx::Value> ChainParams::clone() const {
	return std::make_shared<ChainParams>(*this);
}

void ChainParams::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void ChainParams::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void ChainParams::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_ChainParams;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, port);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, decimals);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, min_ksize);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, max_ksize);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, plot_filter);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, plot_filter_nhash);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, commit_delay);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, infuse_delay);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, challenge_delay);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, challenge_interval);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, max_diff_adjust);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, min_vdf_segments);
	_visitor.type_field(_type_code->fields[12], 12); vnx::accept(_visitor, num_vdf_segments);
	_visitor.type_field(_type_code->fields[13], 13); vnx::accept(_visitor, max_vdf_segments);
	_visitor.type_field(_type_code->fields[14], 14); vnx::accept(_visitor, score_bits);
	_visitor.type_field(_type_code->fields[15], 15); vnx::accept(_visitor, score_target);
	_visitor.type_field(_type_code->fields[16], 16); vnx::accept(_visitor, score_threshold);
	_visitor.type_field(_type_code->fields[17], 17); vnx::accept(_visitor, vdf_reward);
	_visitor.type_field(_type_code->fields[18], 18); vnx::accept(_visitor, min_reward);
	_visitor.type_field(_type_code->fields[19], 19); vnx::accept(_visitor, reward_factor);
	_visitor.type_field(_type_code->fields[20], 20); vnx::accept(_visitor, time_diff_constant);
	_visitor.type_field(_type_code->fields[21], 21); vnx::accept(_visitor, space_diff_constant);
	_visitor.type_field(_type_code->fields[22], 22); vnx::accept(_visitor, virtual_space_constant);
	_visitor.type_field(_type_code->fields[23], 23); vnx::accept(_visitor, min_time_diff);
	_visitor.type_field(_type_code->fields[24], 24); vnx::accept(_visitor, initial_time_diff);
	_visitor.type_field(_type_code->fields[25], 25); vnx::accept(_visitor, initial_space_diff);
	_visitor.type_field(_type_code->fields[26], 26); vnx::accept(_visitor, min_txfee);
	_visitor.type_field(_type_code->fields[27], 27); vnx::accept(_visitor, min_txfee_io);
	_visitor.type_field(_type_code->fields[28], 28); vnx::accept(_visitor, min_txfee_sign);
	_visitor.type_field(_type_code->fields[29], 29); vnx::accept(_visitor, min_txfee_exec);
	_visitor.type_field(_type_code->fields[30], 30); vnx::accept(_visitor, min_txfee_deploy);
	_visitor.type_field(_type_code->fields[31], 31); vnx::accept(_visitor, min_txfee_byte);
	_visitor.type_field(_type_code->fields[32], 32); vnx::accept(_visitor, min_txfee_activate);
	_visitor.type_field(_type_code->fields[33], 33); vnx::accept(_visitor, max_block_size);
	_visitor.type_field(_type_code->fields[34], 34); vnx::accept(_visitor, max_block_cost);
	_visitor.type_field(_type_code->fields[35], 35); vnx::accept(_visitor, block_time);
	_visitor.type_field(_type_code->fields[36], 36); vnx::accept(_visitor, vdf_seed);
	_visitor.type_field(_type_code->fields[37], 37); vnx::accept(_visitor, plot_binary);
	_visitor.type_field(_type_code->fields[38], 38); vnx::accept(_visitor, swap_binary);
	_visitor.type_field(_type_code->fields[39], 39); vnx::accept(_visitor, offer_binary);
	_visitor.type_field(_type_code->fields[40], 40); vnx::accept(_visitor, token_binary);
	_visitor.type_field(_type_code->fields[41], 41); vnx::accept(_visitor, plot_nft_binary);
	_visitor.type_field(_type_code->fields[42], 42); vnx::accept(_visitor, project_addr);
	_visitor.type_field(_type_code->fields[43], 43); vnx::accept(_visitor, fixed_project_reward);
	_visitor.type_field(_type_code->fields[44], 44); vnx::accept(_visitor, project_ratio);
	_visitor.type_end(*_type_code);
}

void ChainParams::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.ChainParams\"";
	_out << ", \"port\": "; vnx::write(_out, port);
	_out << ", \"decimals\": "; vnx::write(_out, decimals);
	_out << ", \"min_ksize\": "; vnx::write(_out, min_ksize);
	_out << ", \"max_ksize\": "; vnx::write(_out, max_ksize);
	_out << ", \"plot_filter\": "; vnx::write(_out, plot_filter);
	_out << ", \"plot_filter_nhash\": "; vnx::write(_out, plot_filter_nhash);
	_out << ", \"commit_delay\": "; vnx::write(_out, commit_delay);
	_out << ", \"infuse_delay\": "; vnx::write(_out, infuse_delay);
	_out << ", \"challenge_delay\": "; vnx::write(_out, challenge_delay);
	_out << ", \"challenge_interval\": "; vnx::write(_out, challenge_interval);
	_out << ", \"max_diff_adjust\": "; vnx::write(_out, max_diff_adjust);
	_out << ", \"min_vdf_segments\": "; vnx::write(_out, min_vdf_segments);
	_out << ", \"num_vdf_segments\": "; vnx::write(_out, num_vdf_segments);
	_out << ", \"max_vdf_segments\": "; vnx::write(_out, max_vdf_segments);
	_out << ", \"score_bits\": "; vnx::write(_out, score_bits);
	_out << ", \"score_target\": "; vnx::write(_out, score_target);
	_out << ", \"score_threshold\": "; vnx::write(_out, score_threshold);
	_out << ", \"vdf_reward\": "; vnx::write(_out, vdf_reward);
	_out << ", \"min_reward\": "; vnx::write(_out, min_reward);
	_out << ", \"reward_factor\": "; vnx::write(_out, reward_factor);
	_out << ", \"time_diff_constant\": "; vnx::write(_out, time_diff_constant);
	_out << ", \"space_diff_constant\": "; vnx::write(_out, space_diff_constant);
	_out << ", \"virtual_space_constant\": "; vnx::write(_out, virtual_space_constant);
	_out << ", \"min_time_diff\": "; vnx::write(_out, min_time_diff);
	_out << ", \"initial_time_diff\": "; vnx::write(_out, initial_time_diff);
	_out << ", \"initial_space_diff\": "; vnx::write(_out, initial_space_diff);
	_out << ", \"min_txfee\": "; vnx::write(_out, min_txfee);
	_out << ", \"min_txfee_io\": "; vnx::write(_out, min_txfee_io);
	_out << ", \"min_txfee_sign\": "; vnx::write(_out, min_txfee_sign);
	_out << ", \"min_txfee_exec\": "; vnx::write(_out, min_txfee_exec);
	_out << ", \"min_txfee_deploy\": "; vnx::write(_out, min_txfee_deploy);
	_out << ", \"min_txfee_byte\": "; vnx::write(_out, min_txfee_byte);
	_out << ", \"min_txfee_activate\": "; vnx::write(_out, min_txfee_activate);
	_out << ", \"max_block_size\": "; vnx::write(_out, max_block_size);
	_out << ", \"max_block_cost\": "; vnx::write(_out, max_block_cost);
	_out << ", \"block_time\": "; vnx::write(_out, block_time);
	_out << ", \"vdf_seed\": "; vnx::write(_out, vdf_seed);
	_out << ", \"plot_binary\": "; vnx::write(_out, plot_binary);
	_out << ", \"swap_binary\": "; vnx::write(_out, swap_binary);
	_out << ", \"offer_binary\": "; vnx::write(_out, offer_binary);
	_out << ", \"token_binary\": "; vnx::write(_out, token_binary);
	_out << ", \"plot_nft_binary\": "; vnx::write(_out, plot_nft_binary);
	_out << ", \"project_addr\": "; vnx::write(_out, project_addr);
	_out << ", \"fixed_project_reward\": "; vnx::write(_out, fixed_project_reward);
	_out << ", \"project_ratio\": "; vnx::write(_out, project_ratio);
	_out << "}";
}

void ChainParams::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object ChainParams::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.ChainParams";
	_object["port"] = port;
	_object["decimals"] = decimals;
	_object["min_ksize"] = min_ksize;
	_object["max_ksize"] = max_ksize;
	_object["plot_filter"] = plot_filter;
	_object["plot_filter_nhash"] = plot_filter_nhash;
	_object["commit_delay"] = commit_delay;
	_object["infuse_delay"] = infuse_delay;
	_object["challenge_delay"] = challenge_delay;
	_object["challenge_interval"] = challenge_interval;
	_object["max_diff_adjust"] = max_diff_adjust;
	_object["min_vdf_segments"] = min_vdf_segments;
	_object["num_vdf_segments"] = num_vdf_segments;
	_object["max_vdf_segments"] = max_vdf_segments;
	_object["score_bits"] = score_bits;
	_object["score_target"] = score_target;
	_object["score_threshold"] = score_threshold;
	_object["vdf_reward"] = vdf_reward;
	_object["min_reward"] = min_reward;
	_object["reward_factor"] = reward_factor;
	_object["time_diff_constant"] = time_diff_constant;
	_object["space_diff_constant"] = space_diff_constant;
	_object["virtual_space_constant"] = virtual_space_constant;
	_object["min_time_diff"] = min_time_diff;
	_object["initial_time_diff"] = initial_time_diff;
	_object["initial_space_diff"] = initial_space_diff;
	_object["min_txfee"] = min_txfee;
	_object["min_txfee_io"] = min_txfee_io;
	_object["min_txfee_sign"] = min_txfee_sign;
	_object["min_txfee_exec"] = min_txfee_exec;
	_object["min_txfee_deploy"] = min_txfee_deploy;
	_object["min_txfee_byte"] = min_txfee_byte;
	_object["min_txfee_activate"] = min_txfee_activate;
	_object["max_block_size"] = max_block_size;
	_object["max_block_cost"] = max_block_cost;
	_object["block_time"] = block_time;
	_object["vdf_seed"] = vdf_seed;
	_object["plot_binary"] = plot_binary;
	_object["swap_binary"] = swap_binary;
	_object["offer_binary"] = offer_binary;
	_object["token_binary"] = token_binary;
	_object["plot_nft_binary"] = plot_nft_binary;
	_object["project_addr"] = project_addr;
	_object["fixed_project_reward"] = fixed_project_reward;
	_object["project_ratio"] = project_ratio;
	return _object;
}

void ChainParams::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "block_time") {
			_entry.second.to(block_time);
		} else if(_entry.first == "challenge_delay") {
			_entry.second.to(challenge_delay);
		} else if(_entry.first == "challenge_interval") {
			_entry.second.to(challenge_interval);
		} else if(_entry.first == "commit_delay") {
			_entry.second.to(commit_delay);
		} else if(_entry.first == "decimals") {
			_entry.second.to(decimals);
		} else if(_entry.first == "fixed_project_reward") {
			_entry.second.to(fixed_project_reward);
		} else if(_entry.first == "infuse_delay") {
			_entry.second.to(infuse_delay);
		} else if(_entry.first == "initial_space_diff") {
			_entry.second.to(initial_space_diff);
		} else if(_entry.first == "initial_time_diff") {
			_entry.second.to(initial_time_diff);
		} else if(_entry.first == "max_block_cost") {
			_entry.second.to(max_block_cost);
		} else if(_entry.first == "max_block_size") {
			_entry.second.to(max_block_size);
		} else if(_entry.first == "max_diff_adjust") {
			_entry.second.to(max_diff_adjust);
		} else if(_entry.first == "max_ksize") {
			_entry.second.to(max_ksize);
		} else if(_entry.first == "max_vdf_segments") {
			_entry.second.to(max_vdf_segments);
		} else if(_entry.first == "min_ksize") {
			_entry.second.to(min_ksize);
		} else if(_entry.first == "min_reward") {
			_entry.second.to(min_reward);
		} else if(_entry.first == "min_time_diff") {
			_entry.second.to(min_time_diff);
		} else if(_entry.first == "min_txfee") {
			_entry.second.to(min_txfee);
		} else if(_entry.first == "min_txfee_activate") {
			_entry.second.to(min_txfee_activate);
		} else if(_entry.first == "min_txfee_byte") {
			_entry.second.to(min_txfee_byte);
		} else if(_entry.first == "min_txfee_deploy") {
			_entry.second.to(min_txfee_deploy);
		} else if(_entry.first == "min_txfee_exec") {
			_entry.second.to(min_txfee_exec);
		} else if(_entry.first == "min_txfee_io") {
			_entry.second.to(min_txfee_io);
		} else if(_entry.first == "min_txfee_sign") {
			_entry.second.to(min_txfee_sign);
		} else if(_entry.first == "min_vdf_segments") {
			_entry.second.to(min_vdf_segments);
		} else if(_entry.first == "num_vdf_segments") {
			_entry.second.to(num_vdf_segments);
		} else if(_entry.first == "offer_binary") {
			_entry.second.to(offer_binary);
		} else if(_entry.first == "plot_binary") {
			_entry.second.to(plot_binary);
		} else if(_entry.first == "plot_filter") {
			_entry.second.to(plot_filter);
		} else if(_entry.first == "plot_filter_nhash") {
			_entry.second.to(plot_filter_nhash);
		} else if(_entry.first == "plot_nft_binary") {
			_entry.second.to(plot_nft_binary);
		} else if(_entry.first == "port") {
			_entry.second.to(port);
		} else if(_entry.first == "project_addr") {
			_entry.second.to(project_addr);
		} else if(_entry.first == "project_ratio") {
			_entry.second.to(project_ratio);
		} else if(_entry.first == "reward_factor") {
			_entry.second.to(reward_factor);
		} else if(_entry.first == "score_bits") {
			_entry.second.to(score_bits);
		} else if(_entry.first == "score_target") {
			_entry.second.to(score_target);
		} else if(_entry.first == "score_threshold") {
			_entry.second.to(score_threshold);
		} else if(_entry.first == "space_diff_constant") {
			_entry.second.to(space_diff_constant);
		} else if(_entry.first == "swap_binary") {
			_entry.second.to(swap_binary);
		} else if(_entry.first == "time_diff_constant") {
			_entry.second.to(time_diff_constant);
		} else if(_entry.first == "token_binary") {
			_entry.second.to(token_binary);
		} else if(_entry.first == "vdf_reward") {
			_entry.second.to(vdf_reward);
		} else if(_entry.first == "vdf_seed") {
			_entry.second.to(vdf_seed);
		} else if(_entry.first == "virtual_space_constant") {
			_entry.second.to(virtual_space_constant);
		}
	}
}

vnx::Variant ChainParams::get_field(const std::string& _name) const {
	if(_name == "port") {
		return vnx::Variant(port);
	}
	if(_name == "decimals") {
		return vnx::Variant(decimals);
	}
	if(_name == "min_ksize") {
		return vnx::Variant(min_ksize);
	}
	if(_name == "max_ksize") {
		return vnx::Variant(max_ksize);
	}
	if(_name == "plot_filter") {
		return vnx::Variant(plot_filter);
	}
	if(_name == "plot_filter_nhash") {
		return vnx::Variant(plot_filter_nhash);
	}
	if(_name == "commit_delay") {
		return vnx::Variant(commit_delay);
	}
	if(_name == "infuse_delay") {
		return vnx::Variant(infuse_delay);
	}
	if(_name == "challenge_delay") {
		return vnx::Variant(challenge_delay);
	}
	if(_name == "challenge_interval") {
		return vnx::Variant(challenge_interval);
	}
	if(_name == "max_diff_adjust") {
		return vnx::Variant(max_diff_adjust);
	}
	if(_name == "min_vdf_segments") {
		return vnx::Variant(min_vdf_segments);
	}
	if(_name == "num_vdf_segments") {
		return vnx::Variant(num_vdf_segments);
	}
	if(_name == "max_vdf_segments") {
		return vnx::Variant(max_vdf_segments);
	}
	if(_name == "score_bits") {
		return vnx::Variant(score_bits);
	}
	if(_name == "score_target") {
		return vnx::Variant(score_target);
	}
	if(_name == "score_threshold") {
		return vnx::Variant(score_threshold);
	}
	if(_name == "vdf_reward") {
		return vnx::Variant(vdf_reward);
	}
	if(_name == "min_reward") {
		return vnx::Variant(min_reward);
	}
	if(_name == "reward_factor") {
		return vnx::Variant(reward_factor);
	}
	if(_name == "time_diff_constant") {
		return vnx::Variant(time_diff_constant);
	}
	if(_name == "space_diff_constant") {
		return vnx::Variant(space_diff_constant);
	}
	if(_name == "virtual_space_constant") {
		return vnx::Variant(virtual_space_constant);
	}
	if(_name == "min_time_diff") {
		return vnx::Variant(min_time_diff);
	}
	if(_name == "initial_time_diff") {
		return vnx::Variant(initial_time_diff);
	}
	if(_name == "initial_space_diff") {
		return vnx::Variant(initial_space_diff);
	}
	if(_name == "min_txfee") {
		return vnx::Variant(min_txfee);
	}
	if(_name == "min_txfee_io") {
		return vnx::Variant(min_txfee_io);
	}
	if(_name == "min_txfee_sign") {
		return vnx::Variant(min_txfee_sign);
	}
	if(_name == "min_txfee_exec") {
		return vnx::Variant(min_txfee_exec);
	}
	if(_name == "min_txfee_deploy") {
		return vnx::Variant(min_txfee_deploy);
	}
	if(_name == "min_txfee_byte") {
		return vnx::Variant(min_txfee_byte);
	}
	if(_name == "min_txfee_activate") {
		return vnx::Variant(min_txfee_activate);
	}
	if(_name == "max_block_size") {
		return vnx::Variant(max_block_size);
	}
	if(_name == "max_block_cost") {
		return vnx::Variant(max_block_cost);
	}
	if(_name == "block_time") {
		return vnx::Variant(block_time);
	}
	if(_name == "vdf_seed") {
		return vnx::Variant(vdf_seed);
	}
	if(_name == "plot_binary") {
		return vnx::Variant(plot_binary);
	}
	if(_name == "swap_binary") {
		return vnx::Variant(swap_binary);
	}
	if(_name == "offer_binary") {
		return vnx::Variant(offer_binary);
	}
	if(_name == "token_binary") {
		return vnx::Variant(token_binary);
	}
	if(_name == "plot_nft_binary") {
		return vnx::Variant(plot_nft_binary);
	}
	if(_name == "project_addr") {
		return vnx::Variant(project_addr);
	}
	if(_name == "fixed_project_reward") {
		return vnx::Variant(fixed_project_reward);
	}
	if(_name == "project_ratio") {
		return vnx::Variant(project_ratio);
	}
	return vnx::Variant();
}

void ChainParams::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "port") {
		_value.to(port);
	} else if(_name == "decimals") {
		_value.to(decimals);
	} else if(_name == "min_ksize") {
		_value.to(min_ksize);
	} else if(_name == "max_ksize") {
		_value.to(max_ksize);
	} else if(_name == "plot_filter") {
		_value.to(plot_filter);
	} else if(_name == "plot_filter_nhash") {
		_value.to(plot_filter_nhash);
	} else if(_name == "commit_delay") {
		_value.to(commit_delay);
	} else if(_name == "infuse_delay") {
		_value.to(infuse_delay);
	} else if(_name == "challenge_delay") {
		_value.to(challenge_delay);
	} else if(_name == "challenge_interval") {
		_value.to(challenge_interval);
	} else if(_name == "max_diff_adjust") {
		_value.to(max_diff_adjust);
	} else if(_name == "min_vdf_segments") {
		_value.to(min_vdf_segments);
	} else if(_name == "num_vdf_segments") {
		_value.to(num_vdf_segments);
	} else if(_name == "max_vdf_segments") {
		_value.to(max_vdf_segments);
	} else if(_name == "score_bits") {
		_value.to(score_bits);
	} else if(_name == "score_target") {
		_value.to(score_target);
	} else if(_name == "score_threshold") {
		_value.to(score_threshold);
	} else if(_name == "vdf_reward") {
		_value.to(vdf_reward);
	} else if(_name == "min_reward") {
		_value.to(min_reward);
	} else if(_name == "reward_factor") {
		_value.to(reward_factor);
	} else if(_name == "time_diff_constant") {
		_value.to(time_diff_constant);
	} else if(_name == "space_diff_constant") {
		_value.to(space_diff_constant);
	} else if(_name == "virtual_space_constant") {
		_value.to(virtual_space_constant);
	} else if(_name == "min_time_diff") {
		_value.to(min_time_diff);
	} else if(_name == "initial_time_diff") {
		_value.to(initial_time_diff);
	} else if(_name == "initial_space_diff") {
		_value.to(initial_space_diff);
	} else if(_name == "min_txfee") {
		_value.to(min_txfee);
	} else if(_name == "min_txfee_io") {
		_value.to(min_txfee_io);
	} else if(_name == "min_txfee_sign") {
		_value.to(min_txfee_sign);
	} else if(_name == "min_txfee_exec") {
		_value.to(min_txfee_exec);
	} else if(_name == "min_txfee_deploy") {
		_value.to(min_txfee_deploy);
	} else if(_name == "min_txfee_byte") {
		_value.to(min_txfee_byte);
	} else if(_name == "min_txfee_activate") {
		_value.to(min_txfee_activate);
	} else if(_name == "max_block_size") {
		_value.to(max_block_size);
	} else if(_name == "max_block_cost") {
		_value.to(max_block_cost);
	} else if(_name == "block_time") {
		_value.to(block_time);
	} else if(_name == "vdf_seed") {
		_value.to(vdf_seed);
	} else if(_name == "plot_binary") {
		_value.to(plot_binary);
	} else if(_name == "swap_binary") {
		_value.to(swap_binary);
	} else if(_name == "offer_binary") {
		_value.to(offer_binary);
	} else if(_name == "token_binary") {
		_value.to(token_binary);
	} else if(_name == "plot_nft_binary") {
		_value.to(plot_nft_binary);
	} else if(_name == "project_addr") {
		_value.to(project_addr);
	} else if(_name == "fixed_project_reward") {
		_value.to(fixed_project_reward);
	} else if(_name == "project_ratio") {
		_value.to(project_ratio);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const ChainParams& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, ChainParams& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* ChainParams::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> ChainParams::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.ChainParams";
	type_code->type_hash = vnx::Hash64(0x51bba8d28881e8e7ull);
	type_code->code_hash = vnx::Hash64(0xfeb0f44193e37315ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::ChainParams);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<ChainParams>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::ulong_fraction_t::static_get_type_code();
	type_code->fields.resize(45);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "port";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "decimals";
		field.value = vnx::to_string(6);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "min_ksize";
		field.value = vnx::to_string(30);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "max_ksize";
		field.value = vnx::to_string(60);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 4;
		field.name = "plot_filter";
		field.value = vnx::to_string(9);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[5];
		field.data_size = 4;
		field.name = "plot_filter_nhash";
		field.value = vnx::to_string(64);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[6];
		field.data_size = 4;
		field.name = "commit_delay";
		field.value = vnx::to_string(18);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[7];
		field.data_size = 4;
		field.name = "infuse_delay";
		field.value = vnx::to_string(6);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[8];
		field.data_size = 4;
		field.name = "challenge_delay";
		field.value = vnx::to_string(9);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[9];
		field.data_size = 4;
		field.name = "challenge_interval";
		field.value = vnx::to_string(48);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[10];
		field.data_size = 4;
		field.name = "max_diff_adjust";
		field.value = vnx::to_string(10);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[11];
		field.data_size = 4;
		field.name = "min_vdf_segments";
		field.value = vnx::to_string(320);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[12];
		field.data_size = 4;
		field.name = "num_vdf_segments";
		field.value = vnx::to_string(760);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[13];
		field.data_size = 4;
		field.name = "max_vdf_segments";
		field.value = vnx::to_string(1024);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[14];
		field.data_size = 4;
		field.name = "score_bits";
		field.value = vnx::to_string(16);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[15];
		field.data_size = 4;
		field.name = "score_target";
		field.value = vnx::to_string(8192);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[16];
		field.data_size = 4;
		field.name = "score_threshold";
		field.value = vnx::to_string(65536);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[17];
		field.data_size = 8;
		field.name = "vdf_reward";
		field.value = vnx::to_string(2000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[18];
		field.data_size = 8;
		field.name = "min_reward";
		field.value = vnx::to_string(200000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[19];
		field.is_extended = true;
		field.name = "reward_factor";
		field.code = {19, 0};
	}
	{
		auto& field = type_code->fields[20];
		field.data_size = 8;
		field.name = "time_diff_constant";
		field.value = vnx::to_string(1000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[21];
		field.data_size = 8;
		field.name = "space_diff_constant";
		field.value = vnx::to_string(100000000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[22];
		field.data_size = 8;
		field.name = "virtual_space_constant";
		field.value = vnx::to_string(500);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[23];
		field.data_size = 8;
		field.name = "min_time_diff";
		field.value = vnx::to_string(10000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[24];
		field.data_size = 8;
		field.name = "initial_time_diff";
		field.value = vnx::to_string(50000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[25];
		field.data_size = 8;
		field.name = "initial_space_diff";
		field.value = vnx::to_string(10);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[26];
		field.data_size = 8;
		field.name = "min_txfee";
		field.value = vnx::to_string(100);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[27];
		field.data_size = 8;
		field.name = "min_txfee_io";
		field.value = vnx::to_string(100);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[28];
		field.data_size = 8;
		field.name = "min_txfee_sign";
		field.value = vnx::to_string(1000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[29];
		field.data_size = 8;
		field.name = "min_txfee_exec";
		field.value = vnx::to_string(10000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[30];
		field.data_size = 8;
		field.name = "min_txfee_deploy";
		field.value = vnx::to_string(100000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[31];
		field.data_size = 8;
		field.name = "min_txfee_byte";
		field.value = vnx::to_string(10);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[32];
		field.data_size = 8;
		field.name = "min_txfee_activate";
		field.value = vnx::to_string(100000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[33];
		field.data_size = 8;
		field.name = "max_block_size";
		field.value = vnx::to_string(10000000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[34];
		field.data_size = 8;
		field.name = "max_block_cost";
		field.value = vnx::to_string(100000000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[35];
		field.data_size = 8;
		field.name = "block_time";
		field.value = vnx::to_string(10);
		field.code = {10};
	}
	{
		auto& field = type_code->fields[36];
		field.is_extended = true;
		field.name = "vdf_seed";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[37];
		field.is_extended = true;
		field.name = "plot_binary";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[38];
		field.is_extended = true;
		field.name = "swap_binary";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[39];
		field.is_extended = true;
		field.name = "offer_binary";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[40];
		field.is_extended = true;
		field.name = "token_binary";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[41];
		field.is_extended = true;
		field.name = "plot_nft_binary";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[42];
		field.is_extended = true;
		field.name = "project_addr";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[43];
		field.data_size = 8;
		field.name = "fixed_project_reward";
		field.value = vnx::to_string(50000);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[44];
		field.is_extended = true;
		field.name = "project_ratio";
		field.code = {19, 0};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> ChainParams::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
	}
	return nullptr;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::ChainParams& value, const TypeCode* type_code, const uint16_t* code) {
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
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.port, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.decimals, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.min_ksize, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.max_ksize, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.plot_filter, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[5]) {
			vnx::read_value(_buf + _field->offset, value.plot_filter_nhash, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[6]) {
			vnx::read_value(_buf + _field->offset, value.commit_delay, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[7]) {
			vnx::read_value(_buf + _field->offset, value.infuse_delay, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[8]) {
			vnx::read_value(_buf + _field->offset, value.challenge_delay, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[9]) {
			vnx::read_value(_buf + _field->offset, value.challenge_interval, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[10]) {
			vnx::read_value(_buf + _field->offset, value.max_diff_adjust, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[11]) {
			vnx::read_value(_buf + _field->offset, value.min_vdf_segments, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[12]) {
			vnx::read_value(_buf + _field->offset, value.num_vdf_segments, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[13]) {
			vnx::read_value(_buf + _field->offset, value.max_vdf_segments, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[14]) {
			vnx::read_value(_buf + _field->offset, value.score_bits, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[15]) {
			vnx::read_value(_buf + _field->offset, value.score_target, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[16]) {
			vnx::read_value(_buf + _field->offset, value.score_threshold, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[17]) {
			vnx::read_value(_buf + _field->offset, value.vdf_reward, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[18]) {
			vnx::read_value(_buf + _field->offset, value.min_reward, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[20]) {
			vnx::read_value(_buf + _field->offset, value.time_diff_constant, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[21]) {
			vnx::read_value(_buf + _field->offset, value.space_diff_constant, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[22]) {
			vnx::read_value(_buf + _field->offset, value.virtual_space_constant, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[23]) {
			vnx::read_value(_buf + _field->offset, value.min_time_diff, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[24]) {
			vnx::read_value(_buf + _field->offset, value.initial_time_diff, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[25]) {
			vnx::read_value(_buf + _field->offset, value.initial_space_diff, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[26]) {
			vnx::read_value(_buf + _field->offset, value.min_txfee, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[27]) {
			vnx::read_value(_buf + _field->offset, value.min_txfee_io, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[28]) {
			vnx::read_value(_buf + _field->offset, value.min_txfee_sign, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[29]) {
			vnx::read_value(_buf + _field->offset, value.min_txfee_exec, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[30]) {
			vnx::read_value(_buf + _field->offset, value.min_txfee_deploy, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[31]) {
			vnx::read_value(_buf + _field->offset, value.min_txfee_byte, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[32]) {
			vnx::read_value(_buf + _field->offset, value.min_txfee_activate, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[33]) {
			vnx::read_value(_buf + _field->offset, value.max_block_size, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[34]) {
			vnx::read_value(_buf + _field->offset, value.max_block_cost, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[35]) {
			vnx::read_value(_buf + _field->offset, value.block_time, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[43]) {
			vnx::read_value(_buf + _field->offset, value.fixed_project_reward, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 19: vnx::read(in, value.reward_factor, type_code, _field->code.data()); break;
			case 36: vnx::read(in, value.vdf_seed, type_code, _field->code.data()); break;
			case 37: vnx::read(in, value.plot_binary, type_code, _field->code.data()); break;
			case 38: vnx::read(in, value.swap_binary, type_code, _field->code.data()); break;
			case 39: vnx::read(in, value.offer_binary, type_code, _field->code.data()); break;
			case 40: vnx::read(in, value.token_binary, type_code, _field->code.data()); break;
			case 41: vnx::read(in, value.plot_nft_binary, type_code, _field->code.data()); break;
			case 42: vnx::read(in, value.project_addr, type_code, _field->code.data()); break;
			case 44: vnx::read(in, value.project_ratio, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::ChainParams& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_ChainParams;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::ChainParams>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(220);
	vnx::write_value(_buf + 0, value.port);
	vnx::write_value(_buf + 4, value.decimals);
	vnx::write_value(_buf + 8, value.min_ksize);
	vnx::write_value(_buf + 12, value.max_ksize);
	vnx::write_value(_buf + 16, value.plot_filter);
	vnx::write_value(_buf + 20, value.plot_filter_nhash);
	vnx::write_value(_buf + 24, value.commit_delay);
	vnx::write_value(_buf + 28, value.infuse_delay);
	vnx::write_value(_buf + 32, value.challenge_delay);
	vnx::write_value(_buf + 36, value.challenge_interval);
	vnx::write_value(_buf + 40, value.max_diff_adjust);
	vnx::write_value(_buf + 44, value.min_vdf_segments);
	vnx::write_value(_buf + 48, value.num_vdf_segments);
	vnx::write_value(_buf + 52, value.max_vdf_segments);
	vnx::write_value(_buf + 56, value.score_bits);
	vnx::write_value(_buf + 60, value.score_target);
	vnx::write_value(_buf + 64, value.score_threshold);
	vnx::write_value(_buf + 68, value.vdf_reward);
	vnx::write_value(_buf + 76, value.min_reward);
	vnx::write_value(_buf + 84, value.time_diff_constant);
	vnx::write_value(_buf + 92, value.space_diff_constant);
	vnx::write_value(_buf + 100, value.virtual_space_constant);
	vnx::write_value(_buf + 108, value.min_time_diff);
	vnx::write_value(_buf + 116, value.initial_time_diff);
	vnx::write_value(_buf + 124, value.initial_space_diff);
	vnx::write_value(_buf + 132, value.min_txfee);
	vnx::write_value(_buf + 140, value.min_txfee_io);
	vnx::write_value(_buf + 148, value.min_txfee_sign);
	vnx::write_value(_buf + 156, value.min_txfee_exec);
	vnx::write_value(_buf + 164, value.min_txfee_deploy);
	vnx::write_value(_buf + 172, value.min_txfee_byte);
	vnx::write_value(_buf + 180, value.min_txfee_activate);
	vnx::write_value(_buf + 188, value.max_block_size);
	vnx::write_value(_buf + 196, value.max_block_cost);
	vnx::write_value(_buf + 204, value.block_time);
	vnx::write_value(_buf + 212, value.fixed_project_reward);
	vnx::write(out, value.reward_factor, type_code, type_code->fields[19].code.data());
	vnx::write(out, value.vdf_seed, type_code, type_code->fields[36].code.data());
	vnx::write(out, value.plot_binary, type_code, type_code->fields[37].code.data());
	vnx::write(out, value.swap_binary, type_code, type_code->fields[38].code.data());
	vnx::write(out, value.offer_binary, type_code, type_code->fields[39].code.data());
	vnx::write(out, value.token_binary, type_code, type_code->fields[40].code.data());
	vnx::write(out, value.plot_nft_binary, type_code, type_code->fields[41].code.data());
	vnx::write(out, value.project_addr, type_code, type_code->fields[42].code.data());
	vnx::write(out, value.project_ratio, type_code, type_code->fields[44].code.data());
}

void read(std::istream& in, ::mmx::ChainParams& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::ChainParams& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::ChainParams& value) {
	value.accept(visitor);
}

} // vnx
