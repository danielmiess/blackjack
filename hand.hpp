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
    void RemoveCard ( const Card card );

    const unsigned short GetNumberOfCards();

    void Print() const;

protected:
    std::vector < Card > mCards;
};

#endif // HAND_HPP
