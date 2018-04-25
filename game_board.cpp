//
// Created by Robert Baranov on 4/4/18.
//

#include "game_board.h"

Spaces::Spaces() {
    has_piece = false;
}

Spaces::Spaces(bool occupied, int space) {
    has_piece = occupied;
    space_number = space;
}

bool Spaces::is_occupied() const {
    return has_piece;
}

int Spaces::get_location() const {
    return space_number;
}
