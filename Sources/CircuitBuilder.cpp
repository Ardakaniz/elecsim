#include "CircuitBuilder.hpp"

#include <stdexcept>

CircuitBuilder& CircuitBuilder::from(const std::string& name) {
	_initial_from   = name;
	_last_component = name;

	return *this;
}

CircuitBuilder& CircuitBuilder::to(const std::string& name) {
	link(_last_component, name);

	_last_component = name;

	return *this;
}

CircuitBuilder& CircuitBuilder::link(const std::string& a, const std::string& b) {
	_connections[a].insert(a);
	_connections[b].insert(b);

	return *this;
}

CircuitBuilder& CircuitBuilder::close() {
	if (_initial_from.empty())
		throw std::runtime_error{ "Cannot close a CircuitBuilder with no starting point ('from()' call missing)" };
	
	link(_initial_from, _last_component);

	_initial_from.clear();

	if (false) {};

	return *this;
}

Circuit CircuitBuilder::build() {
	// All the magic happens here
	return Circuit{};
}