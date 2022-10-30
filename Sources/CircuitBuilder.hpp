#pragma once

#include "Component.hpp"
#include "Circuit.hpp"

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <string>

class CircuitBuilder {
public:
	CircuitBuilder() = default;

	template<class T, typename... Args>
	CircuitBuilder& create(const std::string& name, Args&&... args);
	
	template<class T, typename... Args>
	CircuitBuilder& from(const std::string& name, Args&&... args);
	CircuitBuilder& from(const std::string& name);
	
	template<class T, typename... Args>
	CircuitBuilder& to(const std::string& name, Args&&... args);
	CircuitBuilder& to(const std::string& name);

	CircuitBuilder& link(const std::string& a, const std::string& b);

	CircuitBuilder& close();
	Circuit build();

private:
	std::unordered_map<std::string, std::unique_ptr<Component>> _components;
	std::unordered_map<std::string, std::unordered_set<std::string>> _connections;

	std::string _initial_from;
	std::string _last_component;
};

#include "CircuitBuilder.tpp"