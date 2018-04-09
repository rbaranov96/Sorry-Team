#include <iostream>
#include "game_board.h"
#include "piece.h"

using namespace std;

int main() {
    Piece piece;
    vector<Spaces> game_board;
    for (int i = 1; i <= 60; i++){
        game_board.push_back(Spaces(piece, i ));
    }

    cout << "The outside ring of the game board has " << game_board.size()<< " pieces" << endl;



    return 0;
}