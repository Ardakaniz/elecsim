#include "CircuitBuilder.hpp"

#include <stdexcept>

template<class T, typename... Args>
CircuitBuilder& CircuitBuilder::create(const std::string& name, Args&&... args) {
	if (_components.contains(name))
		throw std::invalid_argument{ "Trying to create a new component with already-existing name '" + name + "'." };

	_components.emplace(name, std::make_unique<T>(name, std::forward<Args>(args)...));
	_connections.emplace(name, std::unordered_set<std::string>{});
	return *this;
}

template<class T, typename... Args>
CircuitBuilder& CircuitBuilder::from(const std::string& name, Args&&... args) {
	create<T>(name, std::forward<Args>(args)...);
	return from(name);
}

template<class T, typename... Args>
CircuitBuilder& CircuitBuilder::to(const std::string& name, Args&&... args) {
	create<T>(name, std::forward<Args>(args)...);

	return to(name);
}