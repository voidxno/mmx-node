
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/PlotHeader.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/pubkey_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 PlotHeader::VNX_TYPE_HASH(0x299c5790983c47b6ull);
const vnx::Hash64 PlotHeader::VNX_CODE_HASH(0x7b8ddf3d002be0f0ull);

vnx::Hash64 PlotHeader::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string PlotHeader::get_type_name() const {
	return "mmx.PlotHeader";
}

const vnx::TypeCode* PlotHeader::get_type_code() const {
	return mmx::vnx_native_type_code_PlotHeader;
}

std::shared_ptr<PlotHeader> PlotHeader::create() {
	return std::make_shared<PlotHeader>();
}

std::shared_ptr<vnx::Value> PlotHeader::clone() const {
	return std::make_shared<PlotHeader>(*this);
}

void PlotHeader::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void PlotHeader::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void PlotHeader::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_PlotHeader;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, ksize);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, xbits);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, has_meta);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, seed);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, plot_id);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, farmer_key);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, contract);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, plot_size);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, park_size_x);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, park_size_y);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, park_size_pd);
	_visitor.type_field(_type_code->fields[12], 12); vnx::accept(_visitor, park_size_meta);
	_visitor.type_field(_type_code->fields[13], 13); vnx::accept(_visitor, park_bytes_x);
	_visitor.type_field(_type_code->fields[14], 14); vnx::accept(_visitor, park_bytes_y);
	_visitor.type_field(_type_code->fields[15], 15); vnx::accept(_visitor, park_bytes_pd);
	_visitor.type_field(_type_code->fields[16], 16); vnx::accept(_visitor, park_bytes_meta);
	_visitor.type_field(_type_code->fields[17], 17); vnx::accept(_visitor, entry_bits_x);
	_visitor.type_field(_type_code->fields[18], 18); vnx::accept(_visitor, num_entries_y);
	_visitor.type_field(_type_code->fields[19], 19); vnx::accept(_visitor, table_offset_x);
	_visitor.type_field(_type_code->fields[20], 20); vnx::accept(_visitor, table_offset_y);
	_visitor.type_field(_type_code->fields[21], 21); vnx::accept(_visitor, table_offset_meta);
	_visitor.type_field(_type_code->fields[22], 22); vnx::accept(_visitor, table_offset_pd);
	_visitor.type_end(*_type_code);
}

void PlotHeader::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.PlotHeader\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"ksize\": "; vnx::write(_out, ksize);
	_out << ", \"xbits\": "; vnx::write(_out, xbits);
	_out << ", \"has_meta\": "; vnx::write(_out, has_meta);
	_out << ", \"seed\": "; vnx::write(_out, seed);
	_out << ", \"plot_id\": "; vnx::write(_out, plot_id);
	_out << ", \"farmer_key\": "; vnx::write(_out, farmer_key);
	_out << ", \"contract\": "; vnx::write(_out, contract);
	_out << ", \"plot_size\": "; vnx::write(_out, plot_size);
	_out << ", \"park_size_x\": "; vnx::write(_out, park_size_x);
	_out << ", \"park_size_y\": "; vnx::write(_out, park_size_y);
	_out << ", \"park_size_pd\": "; vnx::write(_out, park_size_pd);
	_out << ", \"park_size_meta\": "; vnx::write(_out, park_size_meta);
	_out << ", \"park_bytes_x\": "; vnx::write(_out, park_bytes_x);
	_out << ", \"park_bytes_y\": "; vnx::write(_out, park_bytes_y);
	_out << ", \"park_bytes_pd\": "; vnx::write(_out, park_bytes_pd);
	_out << ", \"park_bytes_meta\": "; vnx::write(_out, park_bytes_meta);
	_out << ", \"entry_bits_x\": "; vnx::write(_out, entry_bits_x);
	_out << ", \"num_entries_y\": "; vnx::write(_out, num_entries_y);
	_out << ", \"table_offset_x\": "; vnx::write(_out, table_offset_x);
	_out << ", \"table_offset_y\": "; vnx::write(_out, table_offset_y);
	_out << ", \"table_offset_meta\": "; vnx::write(_out, table_offset_meta);
	_out << ", \"table_offset_pd\": "; vnx::write(_out, table_offset_pd);
	_out << "}";
}

void PlotHeader::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object PlotHeader::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.PlotHeader";
	_object["version"] = version;
	_object["ksize"] = ksize;
	_object["xbits"] = xbits;
	_object["has_meta"] = has_meta;
	_object["seed"] = seed;
	_object["plot_id"] = plot_id;
	_object["farmer_key"] = farmer_key;
	_object["contract"] = contract;
	_object["plot_size"] = plot_size;
	_object["park_size_x"] = park_size_x;
	_object["park_size_y"] = park_size_y;
	_object["park_size_pd"] = park_size_pd;
	_object["park_size_meta"] = park_size_meta;
	_object["park_bytes_x"] = park_bytes_x;
	_object["park_bytes_y"] = park_bytes_y;
	_object["park_bytes_pd"] = park_bytes_pd;
	_object["park_bytes_meta"] = park_bytes_meta;
	_object["entry_bits_x"] = entry_bits_x;
	_object["num_entries_y"] = num_entries_y;
	_object["table_offset_x"] = table_offset_x;
	_object["table_offset_y"] = table_offset_y;
	_object["table_offset_meta"] = table_offset_meta;
	_object["table_offset_pd"] = table_offset_pd;
	return _object;
}

void PlotHeader::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "contract") {
			_entry.second.to(contract);
		} else if(_entry.first == "entry_bits_x") {
			_entry.second.to(entry_bits_x);
		} else if(_entry.first == "farmer_key") {
			_entry.second.to(farmer_key);
		} else if(_entry.first == "has_meta") {
			_entry.second.to(has_meta);
		} else if(_entry.first == "ksize") {
			_entry.second.to(ksize);
		} else if(_entry.first == "num_entries_y") {
			_entry.second.to(num_entries_y);
		} else if(_entry.first == "park_bytes_meta") {
			_entry.second.to(park_bytes_meta);
		} else if(_entry.first == "park_bytes_pd") {
			_entry.second.to(park_bytes_pd);
		} else if(_entry.first == "park_bytes_x") {
			_entry.second.to(park_bytes_x);
		} else if(_entry.first == "park_bytes_y") {
			_entry.second.to(park_bytes_y);
		} else if(_entry.first == "park_size_meta") {
			_entry.second.to(park_size_meta);
		} else if(_entry.first == "park_size_pd") {
			_entry.second.to(park_size_pd);
		} else if(_entry.first == "park_size_x") {
			_entry.second.to(park_size_x);
		} else if(_entry.first == "park_size_y") {
			_entry.second.to(park_size_y);
		} else if(_entry.first == "plot_id") {
			_entry.second.to(plot_id);
		} else if(_entry.first == "plot_size") {
			_entry.second.to(plot_size);
		} else if(_entry.first == "seed") {
			_entry.second.to(seed);
		} else if(_entry.first == "table_offset_meta") {
			_entry.second.to(table_offset_meta);
		} else if(_entry.first == "table_offset_pd") {
			_entry.second.to(table_offset_pd);
		} else if(_entry.first == "table_offset_x") {
			_entry.second.to(table_offset_x);
		} else if(_entry.first == "table_offset_y") {
			_entry.second.to(table_offset_y);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		} else if(_entry.first == "xbits") {
			_entry.second.to(xbits);
		}
	}
}

vnx::Variant PlotHeader::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "ksize") {
		return vnx::Variant(ksize);
	}
	if(_name == "xbits") {
		return vnx::Variant(xbits);
	}
	if(_name == "has_meta") {
		return vnx::Variant(has_meta);
	}
	if(_name == "seed") {
		return vnx::Variant(seed);
	}
	if(_name == "plot_id") {
		return vnx::Variant(plot_id);
	}
	if(_name == "farmer_key") {
		return vnx::Variant(farmer_key);
	}
	if(_name == "contract") {
		return vnx::Variant(contract);
	}
	if(_name == "plot_size") {
		return vnx::Variant(plot_size);
	}
	if(_name == "park_size_x") {
		return vnx::Variant(park_size_x);
	}
	if(_name == "park_size_y") {
		return vnx::Variant(park_size_y);
	}
	if(_name == "park_size_pd") {
		return vnx::Variant(park_size_pd);
	}
	if(_name == "park_size_meta") {
		return vnx::Variant(park_size_meta);
	}
	if(_name == "park_bytes_x") {
		return vnx::Variant(park_bytes_x);
	}
	if(_name == "park_bytes_y") {
		return vnx::Variant(park_bytes_y);
	}
	if(_name == "park_bytes_pd") {
		return vnx::Variant(park_bytes_pd);
	}
	if(_name == "park_bytes_meta") {
		return vnx::Variant(park_bytes_meta);
	}
	if(_name == "entry_bits_x") {
		return vnx::Variant(entry_bits_x);
	}
	if(_name == "num_entries_y") {
		return vnx::Variant(num_entries_y);
	}
	if(_name == "table_offset_x") {
		return vnx::Variant(table_offset_x);
	}
	if(_name == "table_offset_y") {
		return vnx::Variant(table_offset_y);
	}
	if(_name == "table_offset_meta") {
		return vnx::Variant(table_offset_meta);
	}
	if(_name == "table_offset_pd") {
		return vnx::Variant(table_offset_pd);
	}
	return vnx::Variant();
}

void PlotHeader::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "ksize") {
		_value.to(ksize);
	} else if(_name == "xbits") {
		_value.to(xbits);
	} else if(_name == "has_meta") {
		_value.to(has_meta);
	} else if(_name == "seed") {
		_value.to(seed);
	} else if(_name == "plot_id") {
		_value.to(plot_id);
	} else if(_name == "farmer_key") {
		_value.to(farmer_key);
	} else if(_name == "contract") {
		_value.to(contract);
	} else if(_name == "plot_size") {
		_value.to(plot_size);
	} else if(_name == "park_size_x") {
		_value.to(park_size_x);
	} else if(_name == "park_size_y") {
		_value.to(park_size_y);
	} else if(_name == "park_size_pd") {
		_value.to(park_size_pd);
	} else if(_name == "park_size_meta") {
		_value.to(park_size_meta);
	} else if(_name == "park_bytes_x") {
		_value.to(park_bytes_x);
	} else if(_name == "park_bytes_y") {
		_value.to(park_bytes_y);
	} else if(_name == "park_bytes_pd") {
		_value.to(park_bytes_pd);
	} else if(_name == "park_bytes_meta") {
		_value.to(park_bytes_meta);
	} else if(_name == "entry_bits_x") {
		_value.to(entry_bits_x);
	} else if(_name == "num_entries_y") {
		_value.to(num_entries_y);
	} else if(_name == "table_offset_x") {
		_value.to(table_offset_x);
	} else if(_name == "table_offset_y") {
		_value.to(table_offset_y);
	} else if(_name == "table_offset_meta") {
		_value.to(table_offset_meta);
	} else if(_name == "table_offset_pd") {
		_value.to(table_offset_pd);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const PlotHeader& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, PlotHeader& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* PlotHeader::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> PlotHeader::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.PlotHeader";
	type_code->type_hash = vnx::Hash64(0x299c5790983c47b6ull);
	type_code->code_hash = vnx::Hash64(0x7b8ddf3d002be0f0ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::PlotHeader);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<PlotHeader>(); };
	type_code->fields.resize(23);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "ksize";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "xbits";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 1;
		field.name = "has_meta";
		field.code = {31};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "seed";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "plot_id";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "farmer_key";
		field.code = {11, 33, 1};
	}
	{
		auto& field = type_code->fields[7];
		field.is_extended = true;
		field.name = "contract";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[8];
		field.data_size = 8;
		field.name = "plot_size";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[9];
		field.data_size = 4;
		field.name = "park_size_x";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[10];
		field.data_size = 4;
		field.name = "park_size_y";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[11];
		field.data_size = 4;
		field.name = "park_size_pd";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[12];
		field.data_size = 4;
		field.name = "park_size_meta";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[13];
		field.data_size = 4;
		field.name = "park_bytes_x";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[14];
		field.data_size = 4;
		field.name = "park_bytes_y";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[15];
		field.data_size = 4;
		field.name = "park_bytes_pd";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[16];
		field.data_size = 4;
		field.name = "park_bytes_meta";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[17];
		field.data_size = 4;
		field.name = "entry_bits_x";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[18];
		field.data_size = 8;
		field.name = "num_entries_y";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[19];
		field.data_size = 8;
		field.name = "table_offset_x";
		field.value = vnx::to_string(-1);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[20];
		field.data_size = 8;
		field.name = "table_offset_y";
		field.value = vnx::to_string(-1);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[21];
		field.data_size = 8;
		field.name = "table_offset_meta";
		field.value = vnx::to_string(-1);
		field.code = {4};
	}
	{
		auto& field = type_code->fields[22];
		field.is_extended = true;
		field.name = "table_offset_pd";
		field.code = {12, 4};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> PlotHeader::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
	}
	return nullptr;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::PlotHeader& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.ksize, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.xbits, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.has_meta, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[8]) {
			vnx::read_value(_buf + _field->offset, value.plot_size, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[9]) {
			vnx::read_value(_buf + _field->offset, value.park_size_x, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[10]) {
			vnx::read_value(_buf + _field->offset, value.park_size_y, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[11]) {
			vnx::read_value(_buf + _field->offset, value.park_size_pd, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[12]) {
			vnx::read_value(_buf + _field->offset, value.park_size_meta, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[13]) {
			vnx::read_value(_buf + _field->offset, value.park_bytes_x, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[14]) {
			vnx::read_value(_buf + _field->offset, value.park_bytes_y, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[15]) {
			vnx::read_value(_buf + _field->offset, value.park_bytes_pd, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[16]) {
			vnx::read_value(_buf + _field->offset, value.park_bytes_meta, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[17]) {
			vnx::read_value(_buf + _field->offset, value.entry_bits_x, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[18]) {
			vnx::read_value(_buf + _field->offset, value.num_entries_y, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[19]) {
			vnx::read_value(_buf + _field->offset, value.table_offset_x, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[20]) {
			vnx::read_value(_buf + _field->offset, value.table_offset_y, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[21]) {
			vnx::read_value(_buf + _field->offset, value.table_offset_meta, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 4: vnx::read(in, value.seed, type_code, _field->code.data()); break;
			case 5: vnx::read(in, value.plot_id, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.farmer_key, type_code, _field->code.data()); break;
			case 7: vnx::read(in, value.contract, type_code, _field->code.data()); break;
			case 22: vnx::read(in, value.table_offset_pd, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::PlotHeader& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_PlotHeader;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::PlotHeader>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(89);
	vnx::write_value(_buf + 0, value.version);
	vnx::write_value(_buf + 4, value.ksize);
	vnx::write_value(_buf + 8, value.xbits);
	vnx::write_value(_buf + 12, value.has_meta);
	vnx::write_value(_buf + 13, value.plot_size);
	vnx::write_value(_buf + 21, value.park_size_x);
	vnx::write_value(_buf + 25, value.park_size_y);
	vnx::write_value(_buf + 29, value.park_size_pd);
	vnx::write_value(_buf + 33, value.park_size_meta);
	vnx::write_value(_buf + 37, value.park_bytes_x);
	vnx::write_value(_buf + 41, value.park_bytes_y);
	vnx::write_value(_buf + 45, value.park_bytes_pd);
	vnx::write_value(_buf + 49, value.park_bytes_meta);
	vnx::write_value(_buf + 53, value.entry_bits_x);
	vnx::write_value(_buf + 57, value.num_entries_y);
	vnx::write_value(_buf + 65, value.table_offset_x);
	vnx::write_value(_buf + 73, value.table_offset_y);
	vnx::write_value(_buf + 81, value.table_offset_meta);
	vnx::write(out, value.seed, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.plot_id, type_code, type_code->fields[5].code.data());
	vnx::write(out, value.farmer_key, type_code, type_code->fields[6].code.data());
	vnx::write(out, value.contract, type_code, type_code->fields[7].code.data());
	vnx::write(out, value.table_offset_pd, type_code, type_code->fields[22].code.data());
}

void read(std::istream& in, ::mmx::PlotHeader& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::PlotHeader& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::PlotHeader& value) {
	value.accept(visitor);
}

} // vnx
