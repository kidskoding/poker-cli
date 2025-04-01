#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <stack>

struct Deck {
	std::stack<Card> deck;

	Deck();
	void shuffle();
};

#endif // DECK_H