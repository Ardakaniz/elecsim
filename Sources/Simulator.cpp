#include "Simulator.hpp"

void Simulator::run(float timestep, const std::function<bool (Simulator&)>& callback) {
	do step(timestep);
	while (callback(*this));
}

void Simulator::run_for(float timestep, float duration, const std::function<void (Simulator&)>& callback) {
	do {
		step(timestep);
		callback(*this);
	} while (_time < duration);
}

void Simulator::step(float timestep) {
	_time += timestep;
}

float Simulator::read_voltage(const std::string& comp_name) const {
	(void)comp_name;
	return 0.f;
}

float Simulator::read_time() const noexcept {
	return _time;
}