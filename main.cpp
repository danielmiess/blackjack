#include <iostream>

#include "card.hpp"
#include "hand.hpp"
#include "deck.hpp"

int main ( int argc, char *argv[] )
{
    Card myCard ( eSuit::eDiamond, eRank::eQueen );

    myCard.Print();

    Hand myHand;
    myHand.AddCard ( myCard );
    myHand.AddCard ( Card ( eSuit::eSpade, eRank::eSeven ) );
    myHand.AddCard ( Card ( eSuit::eHeart, eRank::eAce ) );

    std::cout << "Number of cards in hand: " << myHand.GetNumberOfCards() << std::endl;

    Deck myDeck;
    std::cout << "Number of cards in my deck: " << myDeck.GetNumberOfCards() << std::endl;

    myDeck.RemoveCard ( Card ( eSuit::eHeart, eRank::eAce ) );
    std::cout << "Number of cards in my deck: " << myDeck.GetNumberOfCards() << std::endl;

    std::cout << "Contents of deck after removing card:" << std::endl;
    myDeck.Print();

    return 0;
}
