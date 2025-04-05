#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "chip.h"
#include <memory>
#include <vector>

struct Player {
	std::shared_ptr<std::vector<Card>> hand;
	std::shared_ptr<std::vector<Chip>> chips;
	std::string name;

	Player(std::string& name) : name(name) {
		this->hand = std::make_shared<std::vector<Card>>();
		this->chips = std::make_shared<std::vector<Chip>>();
	}
};

#endif // PLAYER_H