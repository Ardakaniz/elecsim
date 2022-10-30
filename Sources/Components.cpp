#include "Components.hpp"

DCVoltageSource::DCVoltageSource(const std::string& name, float V)
	: Component{ name }
	, _V{ V }
{ }

Resistor::Resistor(const std::string& name, float R)
	: Component{ name }
	, _R{ R }
{ }

Capacitor::Capacitor(const std::string& name, float C)
	: Component{ name }
	, _C{ C }
{ }

Inductance::Inductance(const std::string& name, float L)
	: Component{ name }
	, _L{ L }
{ }

void DCVoltageSource::process(Complex& u, Complex&) {
	u = _V;
}

void Resistor::process(Complex& u, Complex& i) {
	u = _R * i;
}

void Capacitor::process(Complex& u, Complex& i) {
	i = _C * Complex{0., 1.} * u;
}

void Inductance::process(Complex& u, Complex& i) {
	u = _L * Complex{0., 1.} * i;
}