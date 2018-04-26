//
// Created by Robert Baranov on 4/1/18.
//

#ifndef space_h
#define space_h

using namespace std;

//create a space that holds an identifying number and coordinates
//Author: Jay Brideau
class space {
public:
	space(int space_number,  int x_center, int y_center);
	int space_number;
	int x_center;
	int y_center;

	int get_x_center();
	int get_y_center();

};

#endif //space_h
