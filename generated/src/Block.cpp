
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Block.hxx>
#include <mmx/Block_calc_cost.hxx>
#include <mmx/Block_calc_cost_return.hxx>
#include <mmx/Block_calc_tx_hash.hxx>
#include <mmx/Block_calc_tx_hash_return.hxx>
#include <mmx/Block_finalize.hxx>
#include <mmx/Block_finalize_return.hxx>
#include <mmx/Block_get_all_transactions.hxx>
#include <mmx/Block_get_all_transactions_return.hxx>
#include <mmx/Block_get_header.hxx>
#include <mmx/Block_get_header_return.hxx>
#include <mmx/Block_is_valid.hxx>
#include <mmx/Block_is_valid_return.hxx>
#include <mmx/Block_validate.hxx>
#include <mmx/Block_validate_return.hxx>
#include <mmx/BlockHeader.hxx>
#include <mmx/BlockHeader_calc_hash.hxx>
#include <mmx/BlockHeader_calc_hash_return.hxx>
#include <mmx/BlockHeader_get_full_hash.hxx>
#include <mmx/BlockHeader_get_full_hash_return.hxx>
#include <mmx/BlockHeader_get_header.hxx>
#include <mmx/BlockHeader_get_header_return.hxx>
#include <mmx/BlockHeader_is_valid.hxx>
#include <mmx/BlockHeader_is_valid_return.hxx>
#include <mmx/BlockHeader_validate.hxx>
#include <mmx/BlockHeader_validate_return.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/hash_t.hpp>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Block::VNX_TYPE_HASH(0x94965d816d328467ull);
const vnx::Hash64 Block::VNX_CODE_HASH(0x5619d2c918be895full);

vnx::Hash64 Block::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Block::get_type_name() const {
	return "mmx.Block";
}

const vnx::TypeCode* Block::get_type_code() const {
	return mmx::vnx_native_type_code_Block;
}

std::shared_ptr<Block> Block::create() {
	return std::make_shared<Block>();
}

std::shared_ptr<vnx::Value> Block::clone() const {
	return std::make_shared<Block>(*this);
}

void Block::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Block::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Block::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Block;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, hash);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, prev);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, height);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, nonce);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, time_diff);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, space_diff);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, weight);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, total_weight);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, vdf_iters);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, vdf_output);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, proof);
	_visitor.type_field(_type_code->fields[12], 12); vnx::accept(_visitor, tx_base);
	_visitor.type_field(_type_code->fields[13], 13); vnx::accept(_visitor, tx_count);
	_visitor.type_field(_type_code->fields[14], 14); vnx::accept(_visitor, tx_fees);
	_visitor.type_field(_type_code->fields[15], 15); vnx::accept(_visitor, tx_cost);
	_visitor.type_field(_type_code->fields[16], 16); vnx::accept(_visitor, tx_hash);
	_visitor.type_field(_type_code->fields[17], 17); vnx::accept(_visitor, node_info);
	_visitor.type_field(_type_code->fields[18], 18); vnx::accept(_visitor, farmer_sig);
	_visitor.type_field(_type_code->fields[19], 19); vnx::accept(_visitor, tx_list);
	_visitor.type_end(*_type_code);
}

void Block::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Block\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"hash\": "; vnx::write(_out, hash);
	_out << ", \"prev\": "; vnx::write(_out, prev);
	_out << ", \"height\": "; vnx::write(_out, height);
	_out << ", \"nonce\": "; vnx::write(_out, nonce);
	_out << ", \"time_diff\": "; vnx::write(_out, time_diff);
	_out << ", \"space_diff\": "; vnx::write(_out, space_diff);
	_out << ", \"weight\": "; vnx::write(_out, weight);
	_out << ", \"total_weight\": "; vnx::write(_out, total_weight);
	_out << ", \"vdf_iters\": "; vnx::write(_out, vdf_iters);
	_out << ", \"vdf_output\": "; vnx::write(_out, vdf_output);
	_out << ", \"proof\": "; vnx::write(_out, proof);
	_out << ", \"tx_base\": "; vnx::write(_out, tx_base);
	_out << ", \"tx_count\": "; vnx::write(_out, tx_count);
	_out << ", \"tx_fees\": "; vnx::write(_out, tx_fees);
	_out << ", \"tx_cost\": "; vnx::write(_out, tx_cost);
	_out << ", \"tx_hash\": "; vnx::write(_out, tx_hash);
	_out << ", \"node_info\": "; vnx::write(_out, node_info);
	_out << ", \"farmer_sig\": "; vnx::write(_out, farmer_sig);
	_out << ", \"tx_list\": "; vnx::write(_out, tx_list);
	_out << "}";
}

void Block::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Block::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Block";
	_object["version"] = version;
	_object["hash"] = hash;
	_object["prev"] = prev;
	_object["height"] = height;
	_object["nonce"] = nonce;
	_object["time_diff"] = time_diff;
	_object["space_diff"] = space_diff;
	_object["weight"] = weight;
	_object["total_weight"] = total_weight;
	_object["vdf_iters"] = vdf_iters;
	_object["vdf_output"] = vdf_output;
	_object["proof"] = proof;
	_object["tx_base"] = tx_base;
	_object["tx_count"] = tx_count;
	_object["tx_fees"] = tx_fees;
	_object["tx_cost"] = tx_cost;
	_object["tx_hash"] = tx_hash;
	_object["node_info"] = node_info;
	_object["farmer_sig"] = farmer_sig;
	_object["tx_list"] = tx_list;
	return _object;
}

void Block::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "farmer_sig") {
			_entry.second.to(farmer_sig);
		} else if(_entry.first == "hash") {
			_entry.second.to(hash);
		} else if(_entry.first == "height") {
			_entry.second.to(height);
		} else if(_entry.first == "node_info") {
			_entry.second.to(node_info);
		} else if(_entry.first == "nonce") {
			_entry.second.to(nonce);
		} else if(_entry.first == "prev") {
			_entry.second.to(prev);
		} else if(_entry.first == "proof") {
			_entry.second.to(proof);
		} else if(_entry.first == "space_diff") {
			_entry.second.to(space_diff);
		} else if(_entry.first == "time_diff") {
			_entry.second.to(time_diff);
		} else if(_entry.first == "total_weight") {
			_entry.second.to(total_weight);
		} else if(_entry.first == "tx_base") {
			_entry.second.to(tx_base);
		} else if(_entry.first == "tx_cost") {
			_entry.second.to(tx_cost);
		} else if(_entry.first == "tx_count") {
			_entry.second.to(tx_count);
		} else if(_entry.first == "tx_fees") {
			_entry.second.to(tx_fees);
		} else if(_entry.first == "tx_hash") {
			_entry.second.to(tx_hash);
		} else if(_entry.first == "tx_list") {
			_entry.second.to(tx_list);
		} else if(_entry.first == "vdf_iters") {
			_entry.second.to(vdf_iters);
		} else if(_entry.first == "vdf_output") {
			_entry.second.to(vdf_output);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		} else if(_entry.first == "weight") {
			_entry.second.to(weight);
		}
	}
}

vnx::Variant Block::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "hash") {
		return vnx::Variant(hash);
	}
	if(_name == "prev") {
		return vnx::Variant(prev);
	}
	if(_name == "height") {
		return vnx::Variant(height);
	}
	if(_name == "nonce") {
		return vnx::Variant(nonce);
	}
	if(_name == "time_diff") {
		return vnx::Variant(time_diff);
	}
	if(_name == "space_diff") {
		return vnx::Variant(space_diff);
	}
	if(_name == "weight") {
		return vnx::Variant(weight);
	}
	if(_name == "total_weight") {
		return vnx::Variant(total_weight);
	}
	if(_name == "vdf_iters") {
		return vnx::Variant(vdf_iters);
	}
	if(_name == "vdf_output") {
		return vnx::Variant(vdf_output);
	}
	if(_name == "proof") {
		return vnx::Variant(proof);
	}
	if(_name == "tx_base") {
		return vnx::Variant(tx_base);
	}
	if(_name == "tx_count") {
		return vnx::Variant(tx_count);
	}
	if(_name == "tx_fees") {
		return vnx::Variant(tx_fees);
	}
	if(_name == "tx_cost") {
		return vnx::Variant(tx_cost);
	}
	if(_name == "tx_hash") {
		return vnx::Variant(tx_hash);
	}
	if(_name == "node_info") {
		return vnx::Variant(node_info);
	}
	if(_name == "farmer_sig") {
		return vnx::Variant(farmer_sig);
	}
	if(_name == "tx_list") {
		return vnx::Variant(tx_list);
	}
	return vnx::Variant();
}

void Block::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "hash") {
		_value.to(hash);
	} else if(_name == "prev") {
		_value.to(prev);
	} else if(_name == "height") {
		_value.to(height);
	} else if(_name == "nonce") {
		_value.to(nonce);
	} else if(_name == "time_diff") {
		_value.to(time_diff);
	} else if(_name == "space_diff") {
		_value.to(space_diff);
	} else if(_name == "weight") {
		_value.to(weight);
	} else if(_name == "total_weight") {
		_value.to(total_weight);
	} else if(_name == "vdf_iters") {
		_value.to(vdf_iters);
	} else if(_name == "vdf_output") {
		_value.to(vdf_output);
	} else if(_name == "proof") {
		_value.to(proof);
	} else if(_name == "tx_base") {
		_value.to(tx_base);
	} else if(_name == "tx_count") {
		_value.to(tx_count);
	} else if(_name == "tx_fees") {
		_value.to(tx_fees);
	} else if(_name == "tx_cost") {
		_value.to(tx_cost);
	} else if(_name == "tx_hash") {
		_value.to(tx_hash);
	} else if(_name == "node_info") {
		_value.to(node_info);
	} else if(_name == "farmer_sig") {
		_value.to(farmer_sig);
	} else if(_name == "tx_list") {
		_value.to(tx_list);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Block& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Block& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Block::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Block::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Block";
	type_code->type_hash = vnx::Hash64(0x94965d816d328467ull);
	type_code->code_hash = vnx::Hash64(0x5619d2c918be895full);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::Block);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::BlockHeader::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Block>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::node_account_t::static_get_type_code();
	type_code->methods.resize(12);
	type_code->methods[0] = ::mmx::Block_calc_cost::static_get_type_code();
	type_code->methods[1] = ::mmx::Block_calc_tx_hash::static_get_type_code();
	type_code->methods[2] = ::mmx::Block_finalize::static_get_type_code();
	type_code->methods[3] = ::mmx::Block_get_all_transactions::static_get_type_code();
	type_code->methods[4] = ::mmx::Block_get_header::static_get_type_code();
	type_code->methods[5] = ::mmx::Block_is_valid::static_get_type_code();
	type_code->methods[6] = ::mmx::Block_validate::static_get_type_code();
	type_code->methods[7] = ::mmx::BlockHeader_calc_hash::static_get_type_code();
	type_code->methods[8] = ::mmx::BlockHeader_get_full_hash::static_get_type_code();
	type_code->methods[9] = ::mmx::BlockHeader_get_header::static_get_type_code();
	type_code->methods[10] = ::mmx::BlockHeader_is_valid::static_get_type_code();
	type_code->methods[11] = ::mmx::BlockHeader_validate::static_get_type_code();
	type_code->fields.resize(20);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "hash";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "prev";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "height";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 8;
		field.name = "nonce";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[5];
		field.data_size = 8;
		field.name = "time_diff";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[6];
		field.data_size = 8;
		field.name = "space_diff";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[7];
		field.is_extended = true;
		field.name = "weight";
		field.code = {11, 16, 1};
	}
	{
		auto& field = type_code->fields[8];
		field.is_extended = true;
		field.name = "total_weight";
		field.code = {11, 16, 1};
	}
	{
		auto& field = type_code->fields[9];
		field.data_size = 8;
		field.name = "vdf_iters";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[10];
		field.is_extended = true;
		field.name = "vdf_output";
		field.code = {11, 2, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[11];
		field.is_extended = true;
		field.name = "proof";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[12];
		field.is_extended = true;
		field.name = "tx_base";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[13];
		field.data_size = 4;
		field.name = "tx_count";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[14];
		field.data_size = 8;
		field.name = "tx_fees";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[15];
		field.data_size = 8;
		field.name = "tx_cost";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[16];
		field.is_extended = true;
		field.name = "tx_hash";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[17];
		field.is_extended = true;
		field.name = "node_info";
		field.code = {33, 19, 0};
	}
	{
		auto& field = type_code->fields[18];
		field.is_extended = true;
		field.name = "farmer_sig";
		field.code = {33, 11, 96, 1};
	}
	{
		auto& field = type_code->fields[19];
		field.is_extended = true;
		field.name = "tx_list";
		field.code = {12, 16};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> Block::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
		case 0xf761b92f6b0c2594ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Block_calc_cost>(_method);
			auto _return_value = ::mmx::Block_calc_cost_return::create();
			_return_value->_ret_0 = calc_cost(_args->params);
			return _return_value;
		}
		case 0x4116f49822c328bcull: {
			auto _args = std::static_pointer_cast<const ::mmx::Block_calc_tx_hash>(_method);
			auto _return_value = ::mmx::Block_calc_tx_hash_return::create();
			_return_value->_ret_0 = calc_tx_hash();
			return _return_value;
		}
		case 0xc19dfeaa6a6a3814ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Block_finalize>(_method);
			auto _return_value = ::mmx::Block_finalize_return::create();
			finalize();
			return _return_value;
		}
		case 0x2a8ee6c560a7bfadull: {
			auto _args = std::static_pointer_cast<const ::mmx::Block_get_all_transactions>(_method);
			auto _return_value = ::mmx::Block_get_all_transactions_return::create();
			_return_value->_ret_0 = get_all_transactions();
			return _return_value;
		}
		case 0xb94157aaa956f7d7ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Block_get_header>(_method);
			auto _return_value = ::mmx::Block_get_header_return::create();
			_return_value->_ret_0 = get_header();
			return _return_value;
		}
		case 0xa203b4d10b9ca39bull: {
			auto _args = std::static_pointer_cast<const ::mmx::Block_is_valid>(_method);
			auto _return_value = ::mmx::Block_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
		case 0x83bc272701f21cdeull: {
			auto _args = std::static_pointer_cast<const ::mmx::Block_validate>(_method);
			auto _return_value = ::mmx::Block_validate_return::create();
			validate();
			return _return_value;
		}
		case 0xc525b15a3f7ee317ull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_calc_hash>(_method);
			auto _return_value = ::mmx::BlockHeader_calc_hash_return::create();
			_return_value->_ret_0 = calc_hash();
			return _return_value;
		}
		case 0x448d0ee44ea4ae66ull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_get_full_hash>(_method);
			auto _return_value = ::mmx::BlockHeader_get_full_hash_return::create();
			_return_value->_ret_0 = get_full_hash();
			return _return_value;
		}
		case 0xd7c88d66a260d84aull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_get_header>(_method);
			auto _return_value = ::mmx::BlockHeader_get_header_return::create();
			_return_value->_ret_0 = get_header();
			return _return_value;
		}
		case 0xee0825f87d03a5ebull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_is_valid>(_method);
			auto _return_value = ::mmx::BlockHeader_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
		case 0xcfb7b60e776d1aaeull: {
			auto _args = std::static_pointer_cast<const ::mmx::BlockHeader_validate>(_method);
			auto _return_value = ::mmx::BlockHeader_validate_return::create();
			validate();
			return _return_value;
		}
	}
	return nullptr;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Block& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.height, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.nonce, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[5]) {
			vnx::read_value(_buf + _field->offset, value.time_diff, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[6]) {
			vnx::read_value(_buf + _field->offset, value.space_diff, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[9]) {
			vnx::read_value(_buf + _field->offset, value.vdf_iters, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[13]) {
			vnx::read_value(_buf + _field->offset, value.tx_count, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[14]) {
			vnx::read_value(_buf + _field->offset, value.tx_fees, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[15]) {
			vnx::read_value(_buf + _field->offset, value.tx_cost, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.hash, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.prev, type_code, _field->code.data()); break;
			case 7: vnx::read(in, value.weight, type_code, _field->code.data()); break;
			case 8: vnx::read(in, value.total_weight, type_code, _field->code.data()); break;
			case 10: vnx::read(in, value.vdf_output, type_code, _field->code.data()); break;
			case 11: vnx::read(in, value.proof, type_code, _field->code.data()); break;
			case 12: vnx::read(in, value.tx_base, type_code, _field->code.data()); break;
			case 16: vnx::read(in, value.tx_hash, type_code, _field->code.data()); break;
			case 17: vnx::read(in, value.node_info, type_code, _field->code.data()); break;
			case 18: vnx::read(in, value.farmer_sig, type_code, _field->code.data()); break;
			case 19: vnx::read(in, value.tx_list, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Block& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Block;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Block>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(60);
	vnx::write_value(_buf + 0, value.version);
	vnx::write_value(_buf + 4, value.height);
	vnx::write_value(_buf + 8, value.nonce);
	vnx::write_value(_buf + 16, value.time_diff);
	vnx::write_value(_buf + 24, value.space_diff);
	vnx::write_value(_buf + 32, value.vdf_iters);
	vnx::write_value(_buf + 40, value.tx_count);
	vnx::write_value(_buf + 44, value.tx_fees);
	vnx::write_value(_buf + 52, value.tx_cost);
	vnx::write(out, value.hash, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.prev, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.weight, type_code, type_code->fields[7].code.data());
	vnx::write(out, value.total_weight, type_code, type_code->fields[8].code.data());
	vnx::write(out, value.vdf_output, type_code, type_code->fields[10].code.data());
	vnx::write(out, value.proof, type_code, type_code->fields[11].code.data());
	vnx::write(out, value.tx_base, type_code, type_code->fields[12].code.data());
	vnx::write(out, value.tx_hash, type_code, type_code->fields[16].code.data());
	vnx::write(out, value.node_info, type_code, type_code->fields[17].code.data());
	vnx::write(out, value.farmer_sig, type_code, type_code->fields[18].code.data());
	vnx::write(out, value.tx_list, type_code, type_code->fields[19].code.data());
}

void read(std::istream& in, ::mmx::Block& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Block& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Block& value) {
	value.accept(visitor);
}

} // vnx
