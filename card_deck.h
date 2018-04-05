#pragma once
#include "card.h"
#include <vector>

class card_deck {
public:
	//hold the cards
	vector<card> deck;

	void fill_deck();
};