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
    InitializeGame();
    RefreshScreen ( false );
    PrintUserOptions();

    int userInput = 0;
    std::cin >> userInput;

    // Main game loop
    while ( userInput != 3 )
    {
        // Hit
        if ( userInput == 1 )
        {
            mDeck.DealCard ( mPlayerHand );
        }

        // Stand
        if ( userInput == 2 )
        {
            // Dealer hits on 16 or below, stands on 17 or above
            while ( mDealerHand.CalculateScore() < 17 )
            {
                mDeck.DealCard ( mDealerHand );
            }

            RefreshScreen ( true );

            DetermineWinner();

            std::cout << "Play again? (y/n)" << std::endl;
            char playAgain = 0;
            std::cin >> playAgain;

            if ( playAgain != 'y' )
            {
                exit ( 0 );
            }
            else
            {
                InitializeGame();

                RefreshScreen ( false );
            }
        }
        else
        {
            RefreshScreen ( false );
        }

        if ( mPlayerHand.CalculateScore() > 21 )
        {
            RefreshScreen ( true );

            std::cout << "You Lose!" << std::endl;
            std::cout << "Play again? (y/n)" << std::endl;

            char playAgain = 0;
            std::cin >> playAgain;

            if ( playAgain != 'y' )
            {
                exit ( 0 );
            }
            else
            {
                InitializeGame();

                RefreshScreen ( false );
            }
        }

        PrintUserOptions();

        std::cin >> userInput;
    }

    exit ( 0 );
}

void Game::RefreshScreen ( bool revealDealerHand )
{
    Display::ClearScreen();
    std::cout << "Dealer Hand (" << mDealerHand.CalculateScore ( ! revealDealerHand ) << "):" << std::endl;
    Display::DisplayHand ( mDealerHand, ! revealDealerHand );

    std::cout << "Player Hand (" << mPlayerHand.CalculateScore ( false ) << "):" << std::endl;
    Display::DisplayHand ( mPlayerHand, false );
}

void Game::PrintUserOptions ( )
{
    std::cout << "1. Hit"   << std::endl;
    std::cout << "2. Stand" << std::endl;
    std::cout << "3. Quit"  << std::endl;
}

void Game::InitializeGame ( )
{
    mDeck = Deck();
    mDealerHand = Hand();
    mPlayerHand = Hand();
    mDeck.DealCards ( 2, mDealerHand );
    mDeck.DealCards ( 2, mPlayerHand );
}

void Game::DetermineWinner()
{
    if ( mPlayerHand.CalculateScore() > mDealerHand.CalculateScore() || mDealerHand.CalculateScore() > 21 )
    {
        std::cout << "You Win!" << std::endl;
    }
    else if ( mPlayerHand.CalculateScore() < mDealerHand.CalculateScore() )
    {
        std::cout << "You Lose!" << std::endl;
    }
    else if ( mPlayerHand.CalculateScore() == mDealerHand.CalculateScore() )
    {
        std::cout << "Push!" << std::endl;
    }
    else
    {
        std::cout << "Unknown end case" << std::endl;
    }
}
