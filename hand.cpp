#include "hand.hpp"
#include "card.hpp"

#include <algorithm>
#include <map>

Hand::Hand ( ) :
    mCards ( )
{

}

void Hand::AddCard ( const Card card )
{
    mCards.push_back ( card );
}

void Hand::RemoveCard ( )
{
    mCards.erase ( mCards.begin() );
}

void Hand::RemoveCard ( const Card card )
{
    mCards.erase ( std::remove ( mCards.begin(), mCards.end(), card ), mCards.end() );
}

const unsigned short Hand::GetNumberOfCards()
{
    return mCards.size();
}

std::vector < Card > Hand::GetCards()
{
    return mCards;
}

void Hand::Print() const
{
    for ( const Card& card : mCards )
    {
        card.Print();
    }
}

int Hand::CalculateScore( ) const
{
    return CalculateScore ( false );
}

int Hand::CalculateScore( bool isDealerHand ) const
{
    const std::map < eRank, unsigned short > rankToScoreMap =
    {
        { eRank::eAce,   11 },
        { eRank::eTwo,   2  },
        { eRank::eThree, 3  },
        { eRank::eFour,  4  },
        { eRank::eFive,  5  },
        { eRank::eSix,   6  },
        { eRank::eSeven, 7  },
        { eRank::eEight, 8  },
        { eRank::eNine,  9  },
        { eRank::eTen,   10 },
        { eRank::eJack,  10 },
        { eRank::eQueen, 10 },
        { eRank::eKing,  10 },

    };

    Hand newHand ( *this );
    if ( isDealerHand )
    {
        newHand.RemoveCard();
    }

    unsigned short score = 0;
    unsigned short numberOfAces = 0;

    for ( const auto& card : newHand.GetCards() )
    {

        if ( card.GetRank() == eRank::eAce )
        {
            ++numberOfAces;
        }

        score = score + rankToScoreMap.at ( card.GetRank() );
    }

    // Need to check if an Ace should be downgraded to a 1
    if ( score > 21 )
    {
        for ( unsigned short i = numberOfAces; i != 0; --i )
        {
            score -= 10;
            if ( score <= 21 )
            {
                break;
            }
        }
    }

    return score;
}
