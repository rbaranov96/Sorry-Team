#include <iostream>
#include "card_deck.h"
#include <ctime>

using namespace std;


int main(int argc, char** argv) {

	//seed true random
	srand(time(NULL));

	//card deck
	card_deck deck1 = card_deck();
	deck1.fill_deck();

	deck1.shuffle_deck();
	cout << "DISCARD DECK TEST" << endl;
	card_deck discard = card_deck();
	discard.add_card(card(two));
	//card discard_test = discard.draw_card();
	//discard_test.print_card_info();

	//test card deck fill
	/*for (int i = 0; i < 45; i++) {
		card print = deck1.get_card_at_position(i);
		print.print_card_info();
	}*/
	cout << "DRAW TESTING" << endl;
	for (int j = 0; j < 10; j++) {
		card test_card = deck1.draw_card_discard(discard);
		//test_card.print_card_info();
		cout << discard.deck.size << endl;
	}
	cout << "DISCARD TESTING" << endl;
	for (int k = 0; k < 10; k++) {
		card test_discard = discard.draw_card_discard(deck1);
		test_discard.print_card_info();
	}
	

	return 0;
}
