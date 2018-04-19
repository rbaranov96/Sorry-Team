//
// Created by Robert Baranov on 4/2/18.
//

#include "piece.h"


Piece::Piece() {
    color = " ";
    location = 0;
}

Piece::Piece(string c, int loc) {
    color = c;
    location = loc;
}

Piece::~Piece() {

}
string Piece::get_color() const {
    return color;

}

int Piece::get_location() const {
    return location;
}

void Piece::set_color(string c) {
    color = c;
}

void Piece::set_location(int loc) {
    location = loc;
}

void Piece::move(int delta_spaces) {
    location = location + delta_spaces;
}
