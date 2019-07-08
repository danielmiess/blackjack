#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "card.hpp"
#include "hand.hpp"

class Display
{
public:
    static void ClearScreen();

    static std::string GetCardAsciiArt ( Card card );
    static std::string GetFaceDownCard ( );

    static void DisplayHand ( Hand hand );
    static void DisplayHand ( Hand hand, bool isDealerHand );

private:
    static std::string ConvertSuitToString ( eSuit suit );
    static std::string ConvertRankToString ( eRank rank );

};




#endif // DISPLAY_HPP
