#include "game.h"
#include <iostream>
#include <memory>

Game::Game(int buyIn, std::shared_ptr<Deck>& deck) : buyIn(buyIn), deck(deck) {}

Game::~Game() {
	for(auto& player : players) {
		delete player;
	}
}

void Game::addPlayer(Player* player) {
	players.push_back(player);
}

void Game::initializeDeck(std::shared_ptr<Deck>& deck) {
	for(int x = 1; x <= 5; x++) {
        deck->shuffle();
    }
}

void Game::distributeDeck(std::shared_ptr<Deck>& deck) {
	for(Player* player : players) {
		int k = 0;
		while(k < 5) {
			player->hand->push_back(deck->deck.top());
			std::cout << deck->deck.top().card_representation() << " ";
			deck->deck.pop();
			k += 1;
		}
		std::cout << "\n";
	}
}