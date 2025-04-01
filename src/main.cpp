#include <iostream>
#include "card.h"
#include "utilities.h"

int main(int argc, char** argv) {
    std::cout << "poker for the cli!" << std::endl;

    Card card('J', utilities::suits[0]);
    std::cout << "the card is " << card.card_representation() << std::endl;

    return 0;
}
