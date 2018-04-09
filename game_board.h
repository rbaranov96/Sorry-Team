//
// Created by Robert Baranov on 4/4/18.
//

#ifndef UNTITLED5_GAME_BOARD_H
#define UNTITLED5_GAME_BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include "piece.h"


using namespace std;
class Spaces {
public:
    Piece piece;
    int space_number;


    Spaces();
    Spaces(Piece game_piece, int space);
    vector<Spaces> game_board;


    Piece is_occupied() const;
    int get_location() const;

};


#endif //UNTITLED5_GAME_BOARD_H
