#pragma once
#include <string>

using namespace std;

enum cardface { one = 1, two = 2, three = 3, four = 4, five = 5, seven = 7, eight = 8, ten = 10, eleven = 11, twelve = 12, sorry = 13 };

class card {
public:
	//constructor
	card(cardface face_given);
	//attributes
	cardface face;
	string human_rules;

};