#include <iostream>
#include <vector>
#include "piece.h"

using namespace std;

//move function
/*
 R:i,game_board,piece,red_piece,blue_piece,green_piece,yellow_piece,player1,player2,player3,player4,wp1,wp2,wp3,wp4,wp1a,wp2a,wp3a,wp4a
 M:gameboard , player1,player2,player3,player4 ,wp1,wp2,wp3,wp4  ,wp1a,wp2a,wp3a,wp4a
 E:moves the peices on gameboard of size 60, mini wining gameboard of size 6, removes and puts peices back to start position and fill the safe area for players
 */
void move(int *i,vector<Piece> &game_board,Piece piece,Piece red_piece,Piece blue_piece,Piece green_piece,Piece yellow_piece, vector<Piece> &player1, vector<Piece> &player2, vector<Piece> &player3, vector<Piece> &player4,vector<Piece> &wp1,vector<Piece> &wp2, vector<Piece>  &wp3,vector<Piece> &wp4,vector<Piece> &wp1a,vector<Piece> &wp2a, vector<Piece>  &wp3a,vector<Piece> &wp4a){
    //checks the turn
    if (*i==0) {
        cout << "Player 1: Enter the card no " << endl;
        //m should be the card integer in future
        int m;
        cin >> m;
        //y created for checking whether the player wants to put their peice on the start position, for red it is 0
        int y;
        if (m == 1 | m == 2) {
            cout << "Player 1: Do you want to place your peice on the board from the start area" << endl;
            cin >> y;
        }
        if (y==1) {
            //if statement for checking
            if ((m == 1 | m == 2) && (player1.size() != 0) && (game_board[0].get_color() != "red")) {
                //remves piece from start area
                player1.pop_back();
                //puts peice on gameboard
                game_board[0] = red_piece;
                cout << "A " <<game_board[0].get_color()<< " piece has entered the gameboard" << endl;
                //for bumping other pieces
                if ((game_board[0].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[0].get_color() == "green")){player3.push_back(green_piece);}
                if ((game_board[0].get_color() == "yelllow")){player4.push_back(yellow_piece);}
            }
            //if all the pieces are already on the board.
            else if (player1.size() == 0) {
                cout << "All your pieces are on the board" << endl;
            }
        } else {
            //if y != 1 that means user wants to moves pieces already on the gameboard
            cout << "Player 1: Position of all the red peices on the board" << endl;
            //for future input handling maybe ?
            vector<int> valid_p;
            //prints the position of red pieces on the gameboard
            for (int i = 0; i < 60; i++) {
                if (game_board[i].get_color() == "red") {
                    cout << i <<endl;
                    valid_p.push_back(i);
                }
            }
            int p_for_red, moves;
            cout << "Player 1: Enter the position of the peice you want to move" << endl;
            cin >> p_for_red;
            cout << "Player 1: enter the moves" << endl;
            //this should be integer from card in future
            cin >> moves;
            //if peice loops the gameboard area
            if ((moves + p_for_red) > 59) {
                moves = moves - (59 - p_for_red);
                //for bumping other pieces
                if ((game_board[moves].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[moves].get_color() == "green")){player3.push_back(green_piece);}
                if ((game_board[moves].get_color() == "yelllow")){player4.push_back(yellow_piece);}
                game_board[moves] = red_piece;
                game_board[p_for_red]= piece;
            }
            //to enter the mini gameboard
            else if (((moves + p_for_red) > 58)&&(((moves - (58 - p_for_red)))<=6)){
                moves = moves - (58 - p_for_red);
                wp1a[moves] = red_piece;
                game_board[p_for_red]= piece;
            }
            else {
                if ((p_for_red+moves)==57||(p_for_red+moves)==5){moves=moves+4;}
                moves = moves + p_for_red;
                //for bumping other pieces
                if ((game_board[moves].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[moves].get_color() == "green")){player3.push_back(green_piece);}
                if ((game_board[moves].get_color() == "yelllow")){player4.push_back(yellow_piece);}
                game_board[moves] = red_piece;
                game_board[p_for_red]= piece;
            }
            
            valid_p.clear();
        }
        
        
        
        
    }
    
    if (*i==1) {
        
        cout << "Player 2: Enter the card no " << endl;
        int m;
        cin >> m;
        int y;
        if (m == 1 | m == 2) {
            cout << "Player 2: Do you want to place your peice on the board from the start area" << endl;
            cin >> y;
        }
        if (y==1) {
            if ((m == 1 | m == 2) && (player2.size() != 0) && (game_board[14].get_color() == "empty")) {
                player2.pop_back();
                game_board[14] = blue_piece;
                cout << "A " <<game_board[14].get_color()<< " piece has entered the gameboard" << endl;
            }else if ((m == 1 | m == 2) && (player2.size() != 0) && (((game_board[14].get_color() == "red")||((game_board[14].get_color() == "green"))||((game_board[14].get_color() == "yellow"))))) {
                player2.pop_back();
                game_board[14] = blue_piece;
                cout << "A " <<game_board[14].get_color()<< " piece has entered the gameboard" << endl;
                if ((game_board[14].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[14].get_color() == "green")){player3.push_back(green_piece);}
                if ((game_board[14].get_color() == "yelllow")){player4.push_back(yellow_piece);}
            }
            
            else if (player2.size() == 0) {
                cout << "All your pieces are on the board" << endl;
            }
        } else {
            cout << "Player 2: Position of all the blue peices on the board" << endl;
            vector<int> valid_p;
            for (int i = 0; i < 60; i++) {
                if (game_board[i].get_color() == "blue") {
                    cout << i << endl;
                    valid_p.push_back(i);
                }
            }
            cout <<endl;
            int p_for_blue, moves;
            cout << "Player 2: Enter the position of the peice you want to move" << endl;
            cin >> p_for_blue;
            cout << "Player 2: enter the moves" << endl;
            cin >> moves;
            if (((moves + p_for_blue) > 59)) {
                moves = moves - (59 - p_for_blue);
                if ((game_board[moves].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[moves].get_color() == "green")){player3.push_back(green_piece);}
                if ((game_board[moves].get_color() == "yelllow")){player4.push_back(yellow_piece);}
                game_board[moves] = blue_piece;
                game_board[p_for_blue]= piece;
            }
            else if (((moves + p_for_blue) > 12)&&((moves - (12 - p_for_blue))<=6)){
                moves = moves - (12 - p_for_blue);
                wp2a[moves]=blue_piece;
                game_board[p_for_blue]= piece;
            }
            else {
                if (((p_for_blue+moves )==11)||((p_for_blue+moves )==19)){moves=moves+4;}
                moves = moves + p_for_blue;
                if ((game_board[moves].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[moves].get_color() == "green")){player3.push_back(green_piece);}
                if ((game_board[moves].get_color() == "yelllow")){player4.push_back(yellow_piece);}
                game_board[moves] = blue_piece;
                game_board[p_for_blue]= piece;
            }
            valid_p.clear();
        }
        
    }
    if (*i==2) {
        cout << "Player 3: Enter the card no " << endl;
        int m;
        cin >> m;
        int y;
        if (m == 1 | m == 2) {
            cout << "Player 3: Do you want to place your peice on the board from the start area" << endl;
            cin >> y;
        }
        if (y==1) {
            if ((m == 1 | m == 2) && (player3.size() != 0) && (game_board[29].get_color() == "empty")){
                player3.pop_back();
                game_board[29] = green_piece;
                cout << "A " <<game_board[29].get_color()<< " piece has entered the gameboard" << endl;
            } else if ((m == 1 | m == 2) && (player3.size() != 0) && (( (game_board[29].get_color() == "red")||(game_board[29].get_color() == "blue")|| (game_board[29].get_color() == "yellow")))) {
                player3.pop_back();
                game_board[29] = green_piece;
                cout << "A " <<game_board[29].get_color()<< " piece has entered the gameboard" << endl;
                if ((game_board[29].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[29].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[29].get_color() == "yellow")){player4.push_back(yellow_piece);}
            }
            
            else if (player3.size() == 0) {
                cout << "All your pieces are on the board" << endl;
            }
        } else {
            cout << "Player 3: Position of all the green peices on the board" << endl;
            vector<int> valid_p;
            for (int i = 0; i < 60; i++) {
                if (game_board[i].get_color() == "green") {
                    cout << i << endl;
                    valid_p.push_back(i);
                }
            }
            cout <<endl;
            int p_for_green, moves;
            cout << "Player 3: Enter the position of the peice you want to move" << endl;
            cin >> p_for_green;
            cout << "Player 3: enter the moves" << endl;
            cin >> moves;
            if ((moves + p_for_green) > 59) {
                moves = moves - (59 - p_for_green);
                if ((game_board[moves].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[moves].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[moves].get_color() == "yellow")){player4.push_back(yellow_piece);}
                game_board[moves] = green_piece;
                game_board[p_for_green]= piece;
            }
            else if (((moves - (27 - p_for_green))<=6)&&((moves + p_for_green) > 27)){
                moves = moves - (27 - p_for_green);
                game_board[p_for_green]= piece;
                wp3a[moves] = green_piece;
            }
            else {
                if(((p_for_green+moves)==26)||((p_for_green+moves)==34)){moves=moves+4;}
                moves = moves + p_for_green;
                if ((game_board[moves].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[moves].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[moves].get_color() == "yellow")){player4.push_back(yellow_piece);}
                game_board[moves] = green_piece;
                game_board[p_for_green]= piece;
            }
            
            valid_p.clear();
        }
    }
    if (*i==3) {
        cout << "Player 4: Enter the card no " << endl;
        int m;
        cin >> m;
        int y;
        if (m == 1 | m == 2) {
            cout << "Player 4: Do you want to place your peice on the board from the start area" << endl;
            cin >> y;
        }
        if (y==1) {
            if ((m == 1 | m == 2) && (player4.size() != 0) && (game_board[44].get_color() == "empty")) {
                player4.pop_back();
                game_board[44] = yellow_piece;
                cout << "A " <<game_board[44].get_color()<< " piece has entered the gameboard" << endl;
            } else if ((m == 1 | m == 2) && (player4.size() != 0) && (((game_board[44].get_color() == "red"))||((game_board[44].get_color() == "blue"))||((game_board[44].get_color() == "green")))) {
                player4.pop_back();
                game_board[44] = yellow_piece;
                cout << "A " <<game_board[44].get_color()<< " piece has entered the gameboard" << endl;
                if ((game_board[44].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[44].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[44].get_color() == "green")){player3.push_back(green_piece);}
            }
            else if (player4.size() == 0) {
                cout << "All your pieces are on the board" << endl;
            }
        } else {
            cout << "Player 4: Position of all the yellow peices on the board" << endl;
            vector<int> valid_p;
            for (int i = 0; i < 60; i++) {
                if (game_board[i].get_color() == "yellow") {
                    cout << i << endl;
                    valid_p.push_back(i);
                }
            }
            cout <<endl;
            int p_for_yellow, moves;
            cout << "Player 4: Enter the position of the peice you want to move" << endl;
            cin >> p_for_yellow;
            cout << "Player 4: enter the moves" << endl;
            cin >> moves;
            if ((moves + p_for_yellow) > 59) {
                moves = moves - (59 - p_for_yellow);
                if ((game_board[moves].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[moves].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[moves].get_color() == "green")){player3.push_back(green_piece);}
                game_board[moves] = yellow_piece;
                game_board[p_for_yellow]= piece;
            }
            else if (((moves - (42 - p_for_yellow))<=6)&&((moves + p_for_yellow) > 42)){
                moves = moves - (42 - p_for_yellow);
                wp4a[moves] = yellow_piece;
                game_board[p_for_yellow]= piece;
            }
            else {
                if(((p_for_yellow+moves)==41)||((p_for_yellow+moves)==49)){moves=moves+4;}
                moves = moves + p_for_yellow;
                if ((game_board[moves].get_color() == "red")){player1.push_back(red_piece);}
                if ((game_board[moves].get_color() == "blue")){player2.push_back(blue_piece);}
                if ((game_board[moves].get_color() == "green")){player3.push_back(green_piece);}
                game_board[moves] = yellow_piece;
                game_board[p_for_yellow]= piece;
            }
            valid_p.clear();
        }
    }
    
}
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
    
    //intialising the gameboard.
    vector<Piece> game_board;
    for (int i = 0; i < 60; i++){
        game_board.push_back(piece);
    }
    
    //filling each player
    
    
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
    //mini wining gameboard area for each player
    //6th position leads to the safe area
    vector<Piece> wp1a;
    vector<Piece> wp2a;
    vector<Piece> wp3a;
    vector<Piece> wp4a;
    for (int i = 0; i <6; i++){
        wp1a.push_back(piece);
        wp2a.push_back(piece);
        wp3a.push_back(piece);
        wp4a.push_back(piece);
    }
    
    //for safe area for each player
    vector<Piece> wp1;
    vector<Piece> wp2;
    vector<Piece> wp3;
    vector<Piece> wp4;
    
    cout << "The outside ring of the game board has " << game_board.size()<< " pieces" << endl;
    cout << "All the spaces on the gameboard are " << piece.get_color() << endl;
    //checks whether someone won the game or not.
    while(wp1.size()!=4|wp2.size()!=4|wp3.size()!=4|wp4.size()!=4){
        //checks turns
        for (int i = 0; i<4; i++){
            
           
            move(&i,game_board,piece,red_piece,blue_piece,green_piece,yellow_piece,player1,player2,player3,player4,wp1,wp2,wp3,wp4,wp1a,wp2a,wp3a,wp4a);
            
        }
        
    }
    
    
    return 0;
}
