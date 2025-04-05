#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"
#include <memory>
#include <vector>

struct Game {
	int buyIn;
	std::vector<Player*> players;
	std::shared_ptr<Deck> deck;

	Game(int buyIn, std::shared_ptr<Deck>& deck);
	~Game();
	void addPlayer(Player* p);
	void initializeDeck(std::shared_ptr<Deck>& deck);
	void distributeDeck(std::shared_ptr<Deck>& deck);
};

#endif // GAME_H