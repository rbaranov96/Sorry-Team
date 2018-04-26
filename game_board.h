//
// Created by Robert Baranov on 4/4/18.
//

#ifndef UNTITLED5_GAME_BOARD_H
#define UNTITLED5_GAME_BOARD_H

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Spaces {
public:
    bool has_piece;
    int space_number;


    Spaces();
    Spaces(bool occupied, int space);
    vector<Spaces> game_board;


    bool is_occupied() const;
    int get_location() const;

};


#endif //UNTITLED5_GAME_BOARD_H
