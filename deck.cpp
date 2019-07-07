#include "deck.hpp"

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
}
