#pragma once

#include <string>
#include <complex>

using Complex = std::complex<float>;

class Component {
public:
	Component(const std::string& name) : _name{ name }
	{ }

	inline const std::string& get_name() const noexcept
	{ return _name; }

	virtual void process(Complex& u, Complex& i) = 0; 

protected:
	std::string _name;
};