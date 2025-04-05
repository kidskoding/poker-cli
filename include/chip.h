#ifndef CHIP_H
#define CHIP_H

#include <string>

struct Chip {
	int value;
	std::string color;

	Chip(int value, const std::string& color);
};

#endif // CHIP_H