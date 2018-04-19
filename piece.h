//
// Created by Robert Baranov on 4/2/18.
//

#ifndef UNTITLED5_PIECE_H
#define UNTITLED5_PIECE_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Piece{
private:
    string color;
    int location;
public:
    Piece();
    Piece(string c, int loc);
    ~Piece();



    string get_color() const;
    int get_location() const;

    void set_color(string c);
    void set_location(int loc);

    void move(int delta_spaces);

};

#endif //UNTITLED5_PIECE_H