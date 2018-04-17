//define a card deck

#pragma once
#include "card.h"
#include <vector>

class card_deck {
public:
	//hold the cards in a vector
	vector<card> deck;
	//method to fill the deck with the appropriate cards
	void fill_deck();
	//return a card at a specific index for testing
	card get_card_at_position(int i);
	//randomly shuffle the deck
	void shuffle_deck();
	//pull out the card on the 'top' of the deck and return it to the user
	card draw_card();
};