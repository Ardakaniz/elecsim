#pragma once

#include "Component.hpp"

class DCVoltageSource : public Component {
public:
	DCVoltageSource(const std::string& name, float V);

	void process(Complex& u, Complex&) override;

private:
	const float _V;
};

class Resistor : public Component {
public:
	Resistor(const std::string& name, float R);

	void process(Complex& u, Complex& i) override;

private:
	const float _R;
};

class Capacitor : public Component {
public:
	Capacitor(const std::string& name, float C);

	void process(Complex& u, Complex& i) override;

private:
	const float _C;
};

class Inductance : public Component {
public:
	Inductance(const std::string& name, float L);

	void process(Complex& u, Complex& i) override;

private:
	const float _L;
};