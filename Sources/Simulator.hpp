#pragma once

#include "Circuit.hpp"

#include <string>
#include <functional>

class Simulator {
public:
	Simulator(const Circuit& circ) : _circ{ circ } {};

	void run(float timestep, const std::function<bool (Simulator&)>& callback);
	void run_for(float timestep, float duration, const std::function<void (Simulator&)>& callback);
	void step(float timestep);
	float read_voltage(const std::string& comp_name) const;
	float read_time() const noexcept;
	
private:
	Circuit _circ;
	float _time{ 0.f };
};