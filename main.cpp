#include <iostream>

#include "card.hpp"
#include "hand.hpp"
#include "deck.hpp"
#include "game.hpp"

int main ( int argc, char *argv[] )
{
//    Hand myHand;
//    Deck myDeck;
//
//    myDeck.DealCards ( 2, myHand );
//
//
//    myHand.Print();

    Game myGame;
    myGame.StartNewGame();

    std::cout << "Normal Exit" << std::endl;
    return 0;
}
