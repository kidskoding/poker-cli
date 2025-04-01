#include "deck.h"
#include "utilities.h"

Deck::Deck() {
	for(int i = 0; i < 52; i++) {
		deck.push(Card(utilities::values[i % 13], utilities::suits[i / 13]));
	}
}

void Deck::shuffle() {

}