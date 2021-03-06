#include "space.h"

using namespace std;

space::space() {
	space_number = 0;
	x_center = 0;
	y_center = 0;
}

space::space(int in_space_number, int in_x_center, int in_y_center) {
	space_number = in_space_number;
	x_center = in_x_center;
	y_center = in_y_center;
}

int space::get_x_center() {
	return x_center;
}

int space::get_y_center() {
	return y_center;
}

int space::get_space_number() {
	return space_number;
}