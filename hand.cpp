#include "hand.hpp"
#include "card.hpp"

#include <algorithm>

Hand::Hand ( ) :
    mCards ( )
{

}

void Hand::AddCard ( const Card card )
{
    mCards.push_back ( card );
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
