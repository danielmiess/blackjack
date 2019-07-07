#ifndef CARD_H
#define CARD_H

#include <string>

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

    static const std::string GetSuitString ( eSuit suit );
    static const std::string GetRankString ( eRank rank );

    eSuit GetSuit() const;
    eRank GetRank() const;

private:
    eSuit mSuit;
    eRank mRank;
};

#endif // CARD_H
