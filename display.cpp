#include "display.hpp"
#include <iostream>

void Display::ClearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

std::string Display::GetCardAsciiArt ( Card card )
{
    std::string outputCard = " \
    ┌─────────┐\n \
    │#        │\n \
    │         │\n \
    │         │\n \
    │    *    │\n \
    │         │\n \
    │         │\n \
    │        #│\n \
    └─────────┘";

    std::string toReplace("*");
    size_t pos = outputCard.find(toReplace);
    outputCard.replace(pos, toReplace.length(), ConvertSuitToString(card.GetSuit()));

    if ( card.GetRank() == eRank::eTen )
    {
        toReplace = "# ";
        pos = outputCard.find(toReplace);
        outputCard.replace(pos, toReplace.length(), ConvertRankToString(card.GetRank()));
    }
    else
    {
        toReplace = "#";
        pos = outputCard.find(toReplace);
        outputCard.replace(pos, toReplace.length(), ConvertRankToString(card.GetRank()));
    }

    if ( card.GetRank() == eRank::eTen )
    {
        toReplace = " #";
        pos = outputCard.find(toReplace);
        outputCard.replace(pos, toReplace.length(), ConvertRankToString(card.GetRank()));
    }
    else
    {
        toReplace = "#";
        pos = outputCard.find(toReplace);
        outputCard.replace(pos, toReplace.length(), ConvertRankToString(card.GetRank()));
    }


    return outputCard;
}

std::string Display::GetFaceDownCard()
{
    const std::string faceDownCard = " \
    ┌─────────┐\n \
    │░░░░░░░░░│\n \
    │░░░░░░░░░│\n \
    │░░░░░░░░░│\n \
    │░░░░░░░░░│\n \
    │░░░░░░░░░│\n \
    │░░░░░░░░░│\n \
    │░░░░░░░░░│\n \
    └─────────┘";

    return faceDownCard;
}

void Display::DisplayHand ( Hand hand )
{
    DisplayHand ( hand, false );
}

void Display::DisplayHand ( Hand hand, bool isDealerHand )
{
    std::string output;

    bool first = true;

    for ( const auto& card : hand.GetCards() )
    {
        if ( first )
        {
            if ( isDealerHand )
            {
                output = GetFaceDownCard();
            }
            else
            {
                output = GetCardAsciiArt ( card );
            }

            first = false;
            continue;
        }

        size_t cardLineStart = 0;
        size_t cardLineEnd = 0;

        size_t outputLineStart = 0;
        size_t outputLineEnd = 0;

        std::string cardString = GetCardAsciiArt ( card );
        for ( int i = 0; i < 9; ++i )
        {

            cardLineEnd = cardString.find ( '\n', cardLineStart );
            std::string cardLineToInsert = cardString.substr ( cardLineStart, cardLineEnd - cardLineStart );


            outputLineEnd = output.find ( '\n', outputLineStart );
            if ( outputLineEnd != std::string::npos )
            {
                output.insert ( outputLineEnd, cardLineToInsert );
            }
            else
            {
                output.append ( cardLineToInsert );
            }

            cardLineStart = cardLineEnd + 1;
            outputLineStart = outputLineEnd + cardLineToInsert.length() + 1;
        }

    }

    std::cout << output << std::endl;
}

std::string Display::ConvertSuitToString ( eSuit suit )
{
    switch ( suit )
    {
        case eSuit::eClub:    return "♣";
        case eSuit::eSpade:   return "♠";
        case eSuit::eHeart:   return "♥";
        case eSuit::eDiamond: return "♦";
        default:              return "";
    }
}

std::string Display::ConvertRankToString ( eRank rank )
{
    switch ( rank )
    {
        case eRank::eAce:   return "A";
        case eRank::eTwo:   return "2";
        case eRank::eThree: return "3";
        case eRank::eFour:  return "4";
        case eRank::eFive:  return "5";
        case eRank::eSix:   return "6";
        case eRank::eSeven: return "7";
        case eRank::eEight: return "8";
        case eRank::eNine:  return "9";
        case eRank::eTen:   return "10";
        case eRank::eJack:  return "J";
        case eRank::eQueen: return "Q";
        case eRank::eKing:  return "K";
        default:            return "";
    }
}
