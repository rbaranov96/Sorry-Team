#include "card_deck.h"
#include "card.h"

void card_deck::fill_deck() {
	//fill card_deck with proper number of cards
	deck.push_back(card(one));
	for (int i = 0; i < 4; i++) {
		deck.push_back(card(one));
		deck.push_back(card(two));
		deck.push_back(card(three));
		deck.push_back(card(four));
		deck.push_back(card(five));
		deck.push_back(card(seven));
		deck.push_back(card(eight));
		deck.push_back(card(ten));
		deck.push_back(card(eleven));
		deck.push_back(card(twelve));
		deck.push_back(card(sorry));
	}
}