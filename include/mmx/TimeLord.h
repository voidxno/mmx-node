/*
 * TimeLord.h
 *
 *  Created on: Dec 6, 2021
 *      Author: mad
 */

#ifndef INCLUDE_MMX_TIMELORD_H_
#define INCLUDE_MMX_TIMELORD_H_

#include <mmx/TimeLordBase.hxx>


namespace mmx {

class TimeLord : public TimeLordBase {
public:
	TimeLord(const std::string& _vnx_name);

protected:
	void init() override;

	void main() override;

	void handle(std::shared_ptr<const TimeInfusion> value) override;

	void handle(std::shared_ptr<const IntervalRequest> value) override;

private:
	struct vdf_point_t {
		uint64_t num_iters = 0;
		std::array<hash_t, 2> output;
	};

	void update();

	void start_vdf(vdf_point_t begin);

	void vdf_loop(vdf_point_t point);

	hash_t compute(const hash_t& input, const uint64_t num_iters);

	void print_info();

private:
	std::thread vdf_thread;
	std::recursive_mutex mutex;

	bool do_restart = false;
	bool is_running = false;
	uint64_t checkpoint_iters = 0;

	std::map<uint64_t, hash_t> infuse[2];
	std::map<uint64_t, hash_t> infuse_history[2];
	std::map<uint64_t, std::array<hash_t, 2>> history;

	std::set<std::pair<uint64_t, uint64_t>> pending;

	std::shared_ptr<vdf_point_t> latest_point;

};


} // mmx

#endif /* INCLUDE_MMX_TIMELORD_H_ */
