blackjack: main.cpp card.cpp hand.cpp deck.cpp game.cpp display.cpp
	g++ -g -o blackjack main.cpp card.cpp hand.cpp deck.cpp game.cpp display.cpp -I.

all: blackjack
