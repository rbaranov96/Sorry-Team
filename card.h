//define a card

#pragma once
#include <string>
#include <iostream>

using namespace std;

//enum to hold the possible card faces
//author: Jay Brideau
enum cardface { one = 1, two = 2, three = 3, four = 4, five = 5, seven = 7, eight = 8, ten = 10, eleven = 11, twelve = 12, sorry = 13 };

class card {
public:
	//constructor
	card(cardface face_given);
	//attributes
	cardface face;
	string human_rules;
	//print out card's information
	void print_info();

};