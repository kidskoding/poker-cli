#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <exception>
#include "chip.h"
#include "deck.h"
#include "game.h"
#include "utilities.hpp"
#include "client.h"

int main(int argc, char** argv) {
    std::cout << "poker for the cli!" << std::endl;
    
    try {
        connect();
    } catch(const std::exception& e) {
        std::cerr << "cannot connect to server: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nwhat is your name?" << std::endl;
    
    std::string name;
    std::cin >> name;

    std::cout << "\ninitializing the deck" << '\n';
    std::shared_ptr<Deck> deck = std::make_shared<Deck>();

    Game g = Game(utilities::buyInValue, deck);
    g.addPlayer(new Player(name));
    g.initializeDeck(deck);

    std::cout << "\nwhat is your buy in for this game?" << std::endl;
    int buyIn;
    std::cin >> buyIn;
    if(buyIn < g.buyIn) {
        throw std::runtime_error("buy in value does not meet the requirement for the game buy in value");
    }

    std::cout << "\nhere are your chips" << "\n";
    try {
        std::vector<Chip> chips = utilities::toChips(buyIn);

        std::cout << "Chips received for $" << buyIn << ":\n";
        for(const auto& chip : chips) {
            std::cout << chip.color << " chip worth " << chip.value << "\n";
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nhere are your cards" << std::endl;
    g.distributeDeck(deck);

    return 0;
}
