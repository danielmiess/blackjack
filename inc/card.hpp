#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

enum class eSuit
{
    eDiamond,
    eHeart,
    eClub,
    eSpade
};

enum class eRank
{
    eAce,
    eTwo,
    eThree,
    eFour,
    eFive,
    eSix,
    eSeven,
    eEight,
    eNine,
    eTen,
    eJack,
    eQueen,
    eKing
};

class Card
{
public:
    Card ( eSuit suit, eRank rank );
    ~Card() = default;

    bool operator== ( const Card& rhsCard );

    static const std::string GetSuitString ( eSuit suit );
    static const std::string GetRankString ( eRank rank );

    eSuit GetSuit() const;
    eRank GetRank() const;

    void Print () const;

private:
    eSuit mSuit;
    eRank mRank;
};

#endif // CARD_HPP
