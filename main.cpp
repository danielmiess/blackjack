#include <iostream>

#include "card.hpp"
#include "hand.hpp"
#include "deck.hpp"

int main ( int argc, char *argv[] )
{
    Hand myHand;
    Deck myDeck;

    myDeck.DealCards ( 2, myHand );


    myHand.Print();

    std::cout << "Normal Exit" << std::endl;
    return 0;
}
