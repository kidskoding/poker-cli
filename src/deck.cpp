#include "deck.h"
#include "utilities.hpp"
#include <random>

Deck::Deck() {
	for(int i = 0; i < 52; i++) {
		deck.push(Card(utilities::values[i % 13], utilities::suits[i / 13]));
	}
}

void Deck::shuffle() {
	std::vector<Card> tempDeck;
	while(!deck.empty()) {
		tempDeck.push_back(deck.top());
		deck.pop();
	}

	std::random_device rd;
	std::mt19937 rng(rd());

	for(int i = tempDeck.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(rng);
        std::swap(tempDeck[i], tempDeck[j]);
    }

    for(const auto& card : tempDeck) {
        deck.push(card);
    }
}