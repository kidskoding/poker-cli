#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "chip.h"
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <array>
#include <map>
#include <utility>
#include <vector>

namespace utilities {
	inline constexpr std::array<std::string, 4> suits = {"♠", "♥", "♦", "♣"};
	inline constexpr std::array<std::string, 13> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", 
		"J", "Q", "K", "A"};
	inline const std::map<int, std::string> availableChips = {
		std::make_pair(1, "white"),
		std::make_pair(5, "red"),
		std::make_pair(10, "blue"),
		std::make_pair(25, "green"),
		std::make_pair(100, "black"),
	};
	inline const int buyInValue = 200;

	inline std::vector<Chip> toChips(int money) {
		std::vector<Chip> chips;
		int copyBuyInValue = money;

		std::vector<int> chipValues;
		std::transform(
			availableChips.begin(), 
			availableChips.end(),
			std::back_inserter(chipValues),
			[](const auto& pair) { return pair.first; }
		);

		if(money < chipValues[0]) {
			throw std::runtime_error("no money available to trade into chips!");
		} if(money == 1) {
			auto firstPair = *availableChips.begin();
			return { Chip(firstPair.first, firstPair.second) };
		}

		for(int i = chipValues.size() - 1; i >= 0; i--) {
            while(copyBuyInValue >= chipValues[i]) {
                copyBuyInValue -= chipValues[i];
                auto it = std::find_if(availableChips.begin(), availableChips.end(),
                                       [chipValue = chipValues[i]](const auto& pair) {
                                           return pair.first == chipValue;
                                       });
                if(it != availableChips.end()) {
                    chips.push_back(Chip(it->first, it->second));
                }
            }
        }

		return chips;
	}
};

#endif // UTILITIES_HPP