//implement a card deck

#include "card_deck.h"
#include "card.h"
#include <algorithm>

//fill card_deck with proper number of cards
//author: Jay Brideau
void card_deck::fill_deck() {
	//there are 5 'one' cards and 4 of all other cards
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

//return card at a given index for testing
//Author: Jay Brideau
card card_deck::get_card_at(int i) {
	return deck.at(i);
}

//shuffle the deck of cards
//Author: Jay Brideau
void card_deck::shuffle_deck() {
	random_shuffle(deck.begin(), deck.end());
}

//pull out the card on the 'top' of the deck and return it to the user
//Author: Jay Brideau
card card_deck::draw_card() {
	card drawn_card = deck.back();
	deck.pop_back();
	return drawn_card;
}

//method to add a card to a deck
void card_deck::add_card(card added_card) {
	deck.push_back(added_card);
}