#include "chip.h"
#include "utilities.hpp"
#include <stdexcept>

Chip::Chip(int value, const std::string& color) {
	auto it = utilities::availableChips.find(value);
	if(it != utilities::availableChips.end() && it->first == value) {
		this->color = color;
		this->value = value;
	} else {
		throw std::runtime_error("cannot initialize chip. invalid color and value");
	}
}