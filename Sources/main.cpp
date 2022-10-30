#include "Components.hpp"
#include "Simulator.hpp"
#include "CircuitBuilder.hpp"

#include <iostream>

int main() {

	Simulator sim{
		CircuitBuilder{}
			.from<DCVoltageSource>("DC", 5.f)
			.to<Resistor>("R", 10e3f)
			.to<Capacitor>("C", 1e-6f)
			.close() // equivalently .to("DC")
			.build()
	};

	sim.run_for(1e-3f, 1e-2f, [](Simulator& sim) {
		std::cout << sim.read_time() << ": " << sim.read_voltage("C") << std::endl;
	});

	return EXIT_SUCCESS;
}