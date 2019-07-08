#include "deck.hpp"

#include <cstdlib>
#include <ctime>

Deck::Deck()
{
    const std::vector < eSuit > suits = { eSuit::eClub,
                                          eSuit::eDiamond,
                                          eSuit::eHeart,
                                          eSuit::eSpade };

    const std::vector < eRank > ranks = { eRank::eAce,
                                          eRank::eTwo,
                                          eRank::eThree,
                                          eRank::eFour,
                                          eRank::eFive,
                                          eRank::eSix,
                                          eRank::eSeven,
                                          eRank::eEight,
                                          eRank::eNine,
                                          eRank::eTen,
                                          eRank::eJack,
                                          eRank::eQueen,
                                          eRank::eKing };

    for ( const auto& suit : suits )
    {
        for ( const auto& rank : ranks )
        {
            mCards.push_back ( Card ( suit, rank ) );
        }
    }

    srand ( time ( 0 ) );
}

// This needs to be updated to move the card rather than copying it
void Deck::DealCard ( Hand& hand )
{
    // Generate a random number between 0 and the max number of cards in the deck
    unsigned short randomNumber = rand() % GetNumberOfCards();

    hand.AddCard ( mCards.at ( randomNumber ) );
    mCards.erase ( mCards.begin() + randomNumber );
}

void Deck::DealCards ( unsigned short numberOfCards, Hand& hand )
{
    for ( unsigned short cardIndex = 0; cardIndex < numberOfCards; ++cardIndex )
    {
        DealCard ( hand );
    }
}
