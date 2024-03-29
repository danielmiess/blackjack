#ifndef HAND_HPP
#define HAND_HPP

#include <vector>

#include "card.hpp"




class Hand
{
public:
    Hand();
    ~Hand() = default;

    void AddCard ( const Card card );
    void RemoveCard ();
    void RemoveCard ( const Card card );

    const unsigned short GetNumberOfCards();

    void Print() const;

    std::vector < Card > GetCards();

    int CalculateScore ( ) const;
    int CalculateScore ( bool isDealerHand ) const;

protected:
    std::vector < Card > mCards;
};

#endif // HAND_HPP
