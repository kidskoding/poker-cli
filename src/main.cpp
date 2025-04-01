#include <iostream>
#include "card.h"
#include "deck.h"
#include "utilities.h"

int main(int argc, char** argv) {
    std::cout << "poker for the cli!" << std::endl;

    Deck deck = Deck();
    while(!deck.deck.empty()) {
        std::cout << deck.deck.top().card_representation() << std::endl;
        deck.deck.pop();
    }

    return 0;
}
