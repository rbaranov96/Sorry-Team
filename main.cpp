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

	//test card deck fill
	/*for (int i = 0; i < 45; i++) {
		card print = deck1.get_card_at_position(i);
		print.print_card_info();
	}
	cout << "DRAW TESTING" << endl;
	for (int j = 0; j < 10; j++) {
		card test_card = deck1.draw_card();
		test_card.print_card_info();
	};*/
	

	return 0;
}
