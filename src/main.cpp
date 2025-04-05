#include <iostream>
#include <ostream>
#include <stdexcept>
#include <exception>
#include "chip.h"
#include "deck.h"
#include "utilities.hpp"

int main(int argc, char** argv) {
    std::cout << "poker for the cli!" << std::endl;
    std::cout << "what is your name?" << std::endl;
    
    std::string name;
    std::cin >> name;

    std::cout << "\nwhat is your buy in for this game?" << std::endl;
    int buyIn;
    if(buyIn < utilities::buyInValue) {
        throw std::runtime_error("buy in value does not meet the requirement for the game buy in value");
    } else {
        std::cin >> buyIn;
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

    std::cout << "\ninitializing the deck" << '\n';
    Deck deck = Deck();
    for(int x = 1; x <= 5; x++) {
        deck.shuffle();
    }

    return 0;
}
