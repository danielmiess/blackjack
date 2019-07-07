#include "card.hpp"

Card::Card ( eSuit suit, eRank rank ) :
    mSuit(suit),
    mRank(rank)
{

}

bool Card::operator== ( const Card& rhsCard )
{
    return ( mSuit == rhsCard.mSuit ) &&
           ( mRank == rhsCard.mRank );
}

const std::string Card::GetSuitString ( eSuit suit )
{
    switch ( suit )
    {
        case eSuit::eClub:    return "club";
        case eSuit::eDiamond: return "diamond";
        case eSuit::eHeart:   return "heart";
        case eSuit::eSpade:   return "spade";
        default:              return "";
    }
}

const std::string Card::GetRankString ( eRank rank )
{
    switch ( rank )
    {
        case eRank::eAce:   return "ace";
        case eRank::eTwo:   return "two";
        case eRank::eThree: return "three";
        case eRank::eFour:  return "four";
        case eRank::eFive:  return "five";
        case eRank::eSix:   return "six";
        case eRank::eSeven: return "seven";
        case eRank::eEight: return "eight";
        case eRank::eNine:  return "nine";
        case eRank::eTen:   return "ten";
        case eRank::eJack:  return "jack";
        case eRank::eQueen: return "queen";
        case eRank::eKing:  return "king";
        default:            return "";
    }
}

eSuit Card::GetSuit ( ) const
{
    return mSuit;
}

eRank Card::GetRank ( ) const
{
    return mRank;
}

void Card::Print () const
{
    std::cout << "suit: " << GetSuitString ( mSuit ) << " rank: " << GetRankString ( mRank ) << std::endl;
}

