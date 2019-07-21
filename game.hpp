#ifndef GAME_HPP
#define GAME_HPP

#include "deck.hpp"

class Game
{
public:

    Game();
    ~Game() = default;

    void StartNewGame ();

    void RefreshScreen ( bool revealDealerHand );

    void PrintUserOptions ();

    void InitializeGame();

    void DetermineWinner();

private:
    Deck mDeck;
    Hand mDealerHand;
    Hand mPlayerHand;
};


#endif // GAME_HPP
