#include <iostream>

#include "card.hpp"

int main ( int argc, char *argv[] )
{
    Card myCard ( eSuit::eDiamond, eRank::eQueen );

    std::cout << "Suit: " << Card::GetSuitString ( myCard.GetSuit() ) << std::endl;
    std::cout << "Rank: " << Card::GetRankString ( myCard.GetRank() ) << std::endl;

    return 0;
}
