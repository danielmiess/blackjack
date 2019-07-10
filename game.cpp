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
    mDeck.DealCards ( 2, mDealerHand );
    mDeck.DealCards ( 2, mPlayerHand );

    Display::ClearScreen();
    std::cout << "Dealer Hand (" << mDealerHand.CalculateScore(true) << "):" << std::endl;
    Display::DisplayHand ( mDealerHand, true );

    std::cout << "Player Hand (" << mPlayerHand.CalculateScore() << "):" << std::endl;
    Display::DisplayHand ( mPlayerHand );

    std::cout << "1. Hit" << std::endl;
    std::cout << "2. Stand" << std::endl;
    std::cout << "3. Quit" << std::endl;

    char playAgain = 0;

    int userInput = 0;
    std::cin >> userInput;



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
            Display::ClearScreen();
            std::cout << "Dealer Hand (" << mDealerHand.CalculateScore() << "):" << std::endl;
            Display::DisplayHand ( mDealerHand );

            std::cout << "Player Hand (" << mPlayerHand.CalculateScore() << "):" << std::endl;
            Display::DisplayHand ( mPlayerHand );

            // Dealer keeps hitting until 17
            while ( mDealerHand.CalculateScore() < 17 )
            {
                mDeck.DealCard ( mDealerHand );

                Display::ClearScreen();
                std::cout << "Dealer Hand (" << mDealerHand.CalculateScore() << "):" << std::endl;
                Display::DisplayHand ( mDealerHand );

                std::cout << "Player Hand (" << mPlayerHand.CalculateScore() << "):" << std::endl;
                Display::DisplayHand ( mPlayerHand );
            }

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


            std::cout << "Play again? (y/n)" << std::endl;

            std::cin >> playAgain;

            if ( playAgain != 'y' )
            {
                exit ( 0 );
            }
            else
            {
                mDeck = Deck();
                mDealerHand = Hand();
                mPlayerHand = Hand();
                mDeck.DealCards ( 2, mDealerHand );
                mDeck.DealCards ( 2, mPlayerHand );

                Display::ClearScreen();
                std::cout << "Dealer Hand (" << mDealerHand.CalculateScore(true) << "):" << std::endl;
                Display::DisplayHand ( mDealerHand, true );

                std::cout << "Player Hand (" << mPlayerHand.CalculateScore() << "):" << std::endl;
                Display::DisplayHand ( mPlayerHand );
            }
        }
        else
        {
            Display::ClearScreen();
            std::cout << "Dealer Hand (" << mDealerHand.CalculateScore(true) << "):" << std::endl;
            Display::DisplayHand ( mDealerHand, true );

            std::cout << "Player Hand (" << mPlayerHand.CalculateScore() << "):" << std::endl;
            Display::DisplayHand ( mPlayerHand );
        }

        if ( mPlayerHand.CalculateScore() > 21 )
        {
            std::cout << "You Lose!" << std::endl;
            std::cout << "Play again? (y/n)" << std::endl;

            std::cin >> playAgain;

            if ( playAgain != 'y' )
            {
                exit ( 0 );
            }
            else
            {
                mDeck = Deck();
                mDealerHand = Hand();
                mPlayerHand = Hand();
                mDeck.DealCards ( 2, mDealerHand );
                mDeck.DealCards ( 2, mPlayerHand );

                Display::ClearScreen();
                std::cout << "Dealer Hand (" << mDealerHand.CalculateScore(true) << "):" << std::endl;
                Display::DisplayHand ( mDealerHand, true );

                std::cout << "Player Hand (" << mPlayerHand.CalculateScore() << "):" << std::endl;
                Display::DisplayHand ( mPlayerHand );
            }
        }

        std::cout << "1. Hit" << std::endl;
        std::cout << "2. Stand" << std::endl;
        std::cout << "3. Quit" << std::endl;

        std::cin >> userInput;
    }

    exit ( 0 );
}
