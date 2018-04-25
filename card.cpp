//implement a card
#include "card.h"

//construct a card with a given face value
//author: Jay Brideau
card::card(cardface face_given) {
	face = face_given;
	switch (face){
	case one: 
		human_rules = "Either start a pawn OR move one pawn forward 1 space.";
		move_rules = 1;
		startable = true;
		break;
	case two:
		human_rules = "Either start a pawn OR move one pawn forward 2 spaces. Draw again.";
		move_rules = 2;
		startable = true;
		break;
	case three:
		human_rules = "Move one pawn forward 3 spaces.";
		move_rules = 3;
		startable = false;
		break;
	case four:
		human_rules = "Move one pawn backwards 4 spaces.";
		move_rules = -4;
		startable = false;
		break;
	case five:
		human_rules = "Move one pawn forward 5 spaces.";
		move_rules = 5;
		startable = false;
		break;
	case seven:
		human_rules = "Either move one pawn forward 7 spaces OR split the forward move between any two pawns. You may not use this to start a pawn.";
		move_rules = 7;
		startable = false;
		break;
	case eight:
		human_rules = "Move one pawn forward 8 spaces.";
		move_rules = 8;
		startable = false;
		break;
	case ten: 
		human_rules = "Either move one pawn forward 10 spaces OR move one pawn back 1 space.";
		move_rules = 10;
		startable = false;
		break;
	case eleven:
		human_rules = "Move one pawn forward 11 spaces OR switch any one of your pawns with any one of your opponent's.";
		move_rules = 11;
		startable = false;
		break;
	case twelve:
		human_rules = "Move one pawn forward 12 spaces.";
		move_rules = 12;
		startable = false;
		break;
	case sorry:
		human_rules = "Take one pawn from start, move it to any space occupied by an opponent, and bump that player's pawn back to its START.";
		//CHANGE LATER
		move_rules = 4;
		startable = true;
		break;
	}
}

//print out card's information
//author: Jay Brideau
void card::print_info() {
	if (face == 13) {
		cout << "Sorry!" << endl;
	}
	else {
		cout << face << endl;
	}
	cout << human_rules << endl;
}

//return card's face, with corrections
string card::get_face() {
	if (face == 13) {
		return "Sorry!";
	}
	else {
		return to_string(face);
	}
}