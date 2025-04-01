#ifndef CARD_H
#define CARD_H

#include <sstream>
#include <string>

struct Card {
	std::string value;
	std::string suit;

	Card(const std::string& value, const std::string& suit) {
		this->value = value;
		this->suit = suit;
	}

	std::string card_representation() {
		std::stringstream ss;
		ss << this->value;

		return ss.str() + this->suit;
	}
};

#endif // CARD_H