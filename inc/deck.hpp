#ifndef DECK_HPP
#define DECK_HPP

#include "hand.hpp"

class Deck : public Hand
{
public:
    Deck ();
    ~Deck() = default;

    void DealCard ( Hand& hand );
    void DealCards ( unsigned short numberOfCards, Hand& hand );

};


#endif // DECK_HPP
