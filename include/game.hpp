#ifndef GAME_HPP
#define GAME_HPP

#include "player.h"
#include <vector>

struct Game {
	int buyInValue;
	std::vector<Player> players;

	Game(int buyInValue) {
		this->buyInValue = buyInValue;
	}
};

#endif // GAME_HPP