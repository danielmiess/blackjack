#include "game.hpp"
#include "display.hpp"
#include "card.hpp"

Game::Game() :
    mDeck(),
    mDealerHand(),
    mPlayerHand()
{

}


void Game::StartNewGame()
{
    Display::ClearScreen();

    mDeck.DealCards ( 2, mDealerHand );
    mDeck.DealCards ( 2, mPlayerHand );

//    mDealerHand.Print();
//    mPlayerHand.Print();

//    Display::DisplayFaceDownCard();
    std::cout << "Dealer Hand:" << std::endl;
    Display::DisplayHand ( mDealerHand, true );

    std::cout << "Player Hand:" << std::endl;
    Display::DisplayHand ( mPlayerHand );
}
