//
// Created by Robert Baranov on 4/4/18.
//

#include "game_board.h"

Spaces::Spaces() {
}

Spaces::Spaces(Piece game_piece, int space) {
    piece = game_piece;
    space_number = space;
}

Piece Spaces::is_occupied() const {
    return piece;
}

int Spaces::get_location() const {
    return space_number;
}
