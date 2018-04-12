#include <iostream>
#include <vector>
#include "piece.h"

using namespace std;

int main() {
    Piece piece;
    piece.set_color("empty");
    Piece red_piece;
    red_piece.set_color("red");
    Piece blue_piece;
    blue_piece.set_color("blue");
    Piece green_piece;
    green_piece.set_color("green");
    Piece yellow_piece;
    yellow_piece.set_color("yellow");

    vector<Piece> game_board;
    for (int i = 1; i <= 60; i++){
        game_board.push_back(piece);
    }
    vector<Piece> player1;
    for(int i = 0; i < 4; i++) {
        player1.push_back(red_piece);
    }
    vector<Piece> player2;
    for(int i = 0; i < 4; i++){
        player2.push_back(blue_piece);
    }
    vector<Piece> player3;
    for(int i = 0; i < 4; i++){
        player3.push_back(green_piece);
    }
    vector<Piece> player4;
    for(int i = 0; i < 4; i++){
        player4.push_back(yellow_piece);
    }

    vector<Piece> wp1;
    vector<Piece> wp2;
    vector<Piece> wp3;
    vector<Piece> wp4;

    cout << "The outside ring of the game board has " << game_board.size()<< " pieces" << endl;
    cout << "All the spaces on the gameboard are " << piece.get_color() << endl;

    while(wp1.size()!=4|wp2.size()!=4|wp3.size()!=4|wp4.size()!=4){
        for (int i = 0; i<4; i++) {
            if (i==0) {
                cout << "Player 1: Enter the no of moves" << endl;
                int m;
                cin >> m;
                int y;
                if (m == 1 | m == 2) {
                    cout << "Player 1: Do you want to place your peice on the board from the start area" << endl;
                    cin >> y;
                }
                if (y==1) {
                    if ((m == 1 | m == 2) && (player1.size() != 0) && (game_board[0].get_color() == "empty")) {
                        player1.pop_back();
                        game_board[0] = red_piece;
                        cout << "A " <<game_board[0].get_color()<< " piece has entered the gameboard" << endl;
                    } else if (player1.size() == 0) {
                        cout << "All your pieces are on the board" << endl;
                    }
                } else {
                    cout << "Player 1: Position of all the red peices on the board" << endl;
                    vector<int> valid_p;
                    for (int i = 0; i < 60; i++) {
                        if (game_board[i].get_color() == "red") {
                            cout << i << endl;
                            valid_p.push_back(i);
                        }
                    }
                    int p_for_red, moves;
                    cout << "Player 1: Enter the position of the peice you want to move" << endl;
                    cin >> p_for_red;
                    cout << "Player 1: enter the moves" << endl;
                    cin >> moves;
                    if ((moves + p_for_red) > 59) {
                        moves = moves - (59 - p_for_red);
                    } else {
                        moves = moves + p_for_red;
                    }
                    game_board[moves] = red_piece;
                    game_board[p_for_red]= piece;
                    valid_p.clear();
                }



            }
            if (i==1) {
                cout<<"Player 2: Enter the no of moves"<<endl;
                int m;
                cin>>m;
                if ((m == 1|m == 2 ) && (player2.size() != 0)&&(game_board[14].get_color()=="empty")){
                    player2.pop_back();
                    game_board[14] = blue_piece;
                }
                else if (player2.size() == 0){
                    cout << "All your pieces are on the board" << endl;
                }
                cout << game_board[14].get_color() << endl;
                //moves(m,loop,p1,wp2);

            }
            if (i==2) {
                cout<<"Player 3: Enter the no of moves"<<endl;
                int m;
                cin>>m;
                if ((m == 1|m == 2 ) && (player3.size() != 0)&&(game_board[29].get_color()=="empty")){
                    player3.pop_back();
                    game_board[29] = green_piece;
                }
                else if (player3.size() == 0){
                    cout << "All your pieces are on the board" << endl;
                }
                cout << game_board[29].get_color() << endl;
            }
            if (i==3) {
                cout<<"Player 4: Enter the no of moves"<<endl;
                int m;
                cin>>m;
                if ((m == 1|m == 2 ) && (player4.size() != 0)&&(game_board[44].get_color()=="empty")){
                    player4.pop_back();
                    game_board[44] = yellow_piece;
                }
                else if (player4.size() == 0){
                    cout << "All your pieces are on the board" << endl;
                }
                cout << game_board[44].get_color() << endl;
            }

        }

    }


    return 0;
}