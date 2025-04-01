#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <array>

namespace utilities {
	inline constexpr std::array<std::string, 4> suits = {"♠", "♥", "♦", "♣"};
	inline constexpr std::array<std::string, 13> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", 
		"J", "Q", "K", "A"};
};

#endif // UTILITIES_H