#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "chip.h"
#include <vector>

struct Player {
	std::vector<Card> hand;
	std::vector<Chip> chips;
	std::string name;

	Player();
};

#endif // PLAYER_H