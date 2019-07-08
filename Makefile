blackjack: main.cpp card.cpp hand.cpp deck.cpp
	g++ -g -o blackjack main.cpp card.cpp hand.cpp deck.cpp -I.

all: blackjack
