////define graphics-related functions
//
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "piece.h"
#include "graphics.hpp"
#include "card_deck.h"
#include "card.h"
#include "space.h"

using namespace std;

//initialize various global variables
int width, height;
int wd;
card_deck discard_deck;
card_deck draw_deck;
card drawn_card = card(one);
int space_pixel_width = 45;
vector<space> game_board;
vector<space> red_home_run;
vector<space> blue_home_run;
vector<space> yellow_home_run;
vector<space> green_home_run;
vector<space> red_home_spaces;
vector<space> blue_home_spaces;
vector<space> yellow_home_spaces;
vector<space> green_home_spaces;
vector<space> red_start_spaces;
vector<space> blue_home_spaces;
vector<space> yellow_home_spaces;
vector<space> green_home_spaces;

//vector<piece> red_start;
//vector<piece> blue_start;
//vector<piece> yellow_start;
//vector<piece> green_start;



//initialize x and y for all pieces
//Author: Jay Brideau
//initialize red x and y
int red1_x = (4 * space_pixel_width);
int red1_y = 1 * space_pixel_width + (space_pixel_width / 2) + 10;
int red2_x = (5 * space_pixel_width);
int red2_y = 1 * space_pixel_width + (space_pixel_width / 2) + 10;
int red3_x = 4 * space_pixel_width;
int red3_y = 2 * space_pixel_width + (space_pixel_width / 2) + 10;
int red4_x = 5 * space_pixel_width;
int red4_y = 2 * space_pixel_width + (space_pixel_width / 2) + 10;
//initialize blue x and y
int blue1_x = 13 * space_pixel_width + 10;
int blue1_y = 4 * space_pixel_width;
int blue2_x = 14 * space_pixel_width + 10;
int blue2_y = 4 * space_pixel_width;
int blue3_x = 13 * space_pixel_width + 10;
int blue3_y = 5 * space_pixel_width;
int blue4_x = 14 * space_pixel_width + 10;
int blue4_y = 5 * space_pixel_width;
//initialize yellow x and y
int yellow1_x = 11 * space_pixel_width;
int yellow1_y = 13 * space_pixel_width + 10;
int yellow2_x = 12 * space_pixel_width;
int yellow2_y = 13 * space_pixel_width + 10;
int yellow3_x = 11 * space_pixel_width;
int yellow3_y = 14 * space_pixel_width + 10;
int yellow4_x = 12 * space_pixel_width;
int yellow4_y = 14 * space_pixel_width + 10;
//initialize green x and y
int green1_x = 2 * space_pixel_width - 10;
int green1_y = 11 * space_pixel_width;
int green2_x = 3 * space_pixel_width - 10;
int green2_y = 11 * space_pixel_width;
int green3_x = 2 * space_pixel_width - 10;
int green3_y = 12 * space_pixel_width;
int green4_x = 3 * space_pixel_width - 10;
int green4_y = 12 * space_pixel_width;

//GAME BOARD CLICKABILITY
int mouse_x, mouse_y;

//initialize text for the drawn card
string card_face = "";
string card_rules = "No card has been drawn yet.";

piece e_piece;

//initialize pieces
piece red1, red2, red3, red4;
piece blue1, blue2, blue3, blue4;
piece yellow1, yellow2, yellow3, yellow4;
piece green1, green2, green3, green4;


//initialize variables
//Author: Jay Brideau
void init() {
	//seed true random
	srand(time(NULL));
	width = 1200;
	height = 720;
	mouse_x = mouse_y = 0;
	draw_deck.fill_deck();
	draw_deck.shuffle_deck();

	//initialize pieces
	//red pieces
	red1 = piece({ 1,0,0 }, red1_x, red1_y);
	red2 = piece({ 1,0,0 }, red2_x, red2_y);
	red3 = piece({ 1,0,0 }, red3_x, red3_y);
	red4 = piece({ 1,0,0 }, red4_x, red4_y);
	//blue pieces
	blue1 = piece({ 0,0,1 }, blue1_x, blue1_y);
	blue2 = piece({ 0,0,1 }, blue2_x, blue2_y);
	blue3 = piece({ 0,0,1 }, blue3_x, blue3_y);
	blue4 = piece({ 0,0,1 }, blue4_x, blue4_y);
	//yellow pieces
	yellow1 = piece({ 1,1,0 }, yellow1_x, yellow1_y);
	yellow2 = piece({ 1,1,0 }, yellow2_x, yellow2_y);
	yellow3 = piece({ 1,1,0 }, yellow3_x, yellow3_y);
	yellow4 = piece({ 1,1,0 }, yellow4_x, yellow4_y);
	//green pieces
	green1 = piece({ 0,1,0 }, green1_x, green1_y);
	green2 = piece({ 0,1,0 }, green2_x, green2_y);
	green3 = piece({ 0,1,0 }, green3_x, green3_y);
	green4 = piece({ 0,1,0 }, green4_x, green4_y);

}

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.1f, 0.1f, 0.5f, 1.0f); // background color for game board gui
}

//draw a card from the draw deck and discard it to the discard deck
//Author: Jay Brideau
card draw_and_discard_card() {
	if (draw_deck.deck.size() > 0) {
		card drawn_card = draw_deck.draw_card();
		discard_deck.add_card(drawn_card);
		return drawn_card;
	}
	else {
		for (int i = 0; i < 45; i++) {
			card return_to_draw = discard_deck.draw_card();
			draw_deck.add_card(return_to_draw);
		}
		draw_deck.shuffle_deck();
		card drawn_card = draw_deck.draw_card();
		discard_deck.add_card(drawn_card);
		return drawn_card;
	}

}

//draw the game board GUI
//AUTHOR: Jay Brideau
void draw_gameboard() {
	//DRAW: base of the game board
	//Author: Jay Brideau
	//16 spaces around the edge
	glBegin(GL_QUADS);
	glColor3f(0.9, 1, 0.9);
	glVertex2i(0, 0);
	glVertex2i((16 * space_pixel_width), 0);
	glVertex2i((16 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i(0, (16 * space_pixel_width));
	glEnd();

	//Draw the spaces around the edge of the board
	//Author: Jay Brideau
	//top row of game board
	//space no: 0
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i(0, 0);
	glVertex2i((1 * space_pixel_width), 0);
	glVertex2i((1 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i(0, (1 * space_pixel_width));
	glEnd();
	space space0 = space(0, 0 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space0);
	//space no: 1
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i(space_pixel_width, 0);
	glVertex2i((2 * space_pixel_width), 0);
	glVertex2i((2 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i(space_pixel_width, (1 * space_pixel_width));
	glEnd();
	space space1 = space(1, 1 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space1);
	//space no: 2
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((2 * space_pixel_width), 0);
	glVertex2i((3 * space_pixel_width), 0);
	glVertex2i((3 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space2 = space(2, 2 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space2);
	//space no: 3
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((3 * space_pixel_width), 0);
	glVertex2i((4 * space_pixel_width), 0);
	glVertex2i((4 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space3 = space(3, 3 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space3);
	//space no: 4
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((4 * space_pixel_width), 0);
	glVertex2i((5 * space_pixel_width), 0);
	glVertex2i((5 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space4 = space(4, 4 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space4);
	//space no: 5
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((5 * space_pixel_width), 0);
	glVertex2i((6 * space_pixel_width), 0);
	glVertex2i((6 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space5 = space(5, 5 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space5);
	//space no: 6
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((6 * space_pixel_width), 0);
	glVertex2i((7 * space_pixel_width), 0);
	glVertex2i((7 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space6 = space(6, 6 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space6);
	//space no: 7
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((7 * space_pixel_width), 0);
	glVertex2i((8 * space_pixel_width), 0);
	glVertex2i((8 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space7 = space(7, 7 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space7);
	//space no: 8
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((8 * space_pixel_width), 0);
	glVertex2i((9 * space_pixel_width), 0);
	glVertex2i((9 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space8 = space(8, 8 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space8);
	//space no: 9
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((9 * space_pixel_width), 0);
	glVertex2i((10 * space_pixel_width), 0);
	glVertex2i((10 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space9 = space(9, 9 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space9);
	//space no: 10
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((10 * space_pixel_width), 0);
	glVertex2i((11 * space_pixel_width), 0);
	glVertex2i((11 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space10 = space(10, 10 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space10);
	//space no: 11
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((11 * space_pixel_width), 0);
	glVertex2i((12 * space_pixel_width), 0);
	glVertex2i((12 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space11 = space(11, 11 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space11);
	//space no: 12
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((12 * space_pixel_width), 0);
	glVertex2i((13 * space_pixel_width), 0);
	glVertex2i((13 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space12 = space(12, 12 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space12);
	//space no: 13
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((13 * space_pixel_width), 0);
	glVertex2i((14 * space_pixel_width), 0);
	glVertex2i((14 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space13 = space(13, 13 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space13);
	//space no: 14
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((14 * space_pixel_width), 0);
	glVertex2i((15 * space_pixel_width), 0);
	glVertex2i((15 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space14 = space(14, 14 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space14);
	//space no: 15
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), 0);
	glVertex2i((16 * space_pixel_width), 0);
	glVertex2i((16 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	space space15 = space(15, 15 * space_pixel_width + (space_pixel_width / 2), 0 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space15);
	//right side of game board
	//space no: 16
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (2 * space_pixel_width));
	glEnd();
	space space16 = space(16, 15 * space_pixel_width + (space_pixel_width / 2), 1 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space16);
	//space no: 17
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space17 = space(17, 15 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space17);
	//space no: 18
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (4 * space_pixel_width));
	glEnd();
	space space18 = space(18, 15 * space_pixel_width + (space_pixel_width / 2), 3 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space18);
	//space no: 19
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (5 * space_pixel_width));
	glEnd();
	space space19 = space(19, 15 * space_pixel_width + (space_pixel_width / 2), 4 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space19);
	//space no: 20
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (6 * space_pixel_width));
	glEnd();
	space space20 = space(20, 15 * space_pixel_width + (space_pixel_width / 2), 5 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space20);
	//space no: 21
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (7 * space_pixel_width));
	glEnd();
	space space21 = space(21, 15 * space_pixel_width + (space_pixel_width / 2), 6 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space21);
	//space no: 22
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (8 * space_pixel_width));
	glEnd();
	space space22 = space(22, 15 * space_pixel_width + (space_pixel_width / 2), 7 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space22);
	//space no: 23
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (9 * space_pixel_width));
	glEnd();
	space space23 = space(23, 15 * space_pixel_width + (space_pixel_width / 2), 8 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space23);
	//space no: 24
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (10 * space_pixel_width));
	glEnd();
	space space24 = space(24, 15 * space_pixel_width + (space_pixel_width / 2), 9 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space24);
	//space no: 25
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (11 * space_pixel_width));
	glEnd();
	space space25 = space(25, 15 * space_pixel_width + (space_pixel_width / 2), 10 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space25);
	//space no: 26
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (12 * space_pixel_width));
	glEnd();
	space space26 = space(26, 15 * space_pixel_width + (space_pixel_width / 2), 11 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space26);
	//space no: 27
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (13 * space_pixel_width));
	glEnd();
	space space27 = space(27, 15 * space_pixel_width + (space_pixel_width / 2), 12 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space27);
	//space no: 28
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space28 = space(28, 15 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space28);
	//space no: 29
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (15 * space_pixel_width));
	glEnd();
	space space29 = space(29, 15 * space_pixel_width + (space_pixel_width / 2), 14 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space29);
	//space no: 30
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space30 = space(30, 15 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space30);
	//bottom row of game board
	//space no: 31
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((14 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space31 = space(31, 14 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space31);
	//space no: 32
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((13 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space32 = space(32, 13 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space32);
	//space no: 33
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((12 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space33 = space(33, 12 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space33);
	//space no: 34
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((11 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space34 = space(34, 11 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space34);
	//space no: 35
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((10 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space35 = space(35, 10 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space35);
	//space no: 36
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((9 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space36 = space(36, 9 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space36);
	//space no: 37
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((8 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space37 = space(37, 8 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space37);
	//space no: 38
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((7 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space38 = space(38, 7 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space38);
	//space no: 39
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((6 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space39 = space(39, 6 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space39);
	//space no: 40
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((5 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space40 = space(40, 5 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space40);
	//space no: 41
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((4 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space41 = space(41, 4 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space41);
	//space no: 42
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((3 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space42 = space(42, 3 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space42);
	//space no: 43
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((2 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space43 = space(43, 2 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space43);
	//space no: 44
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((1 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space44 = space(44, 1 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space44);
	//space no: 45
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	space space45 = space(45, 0 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space45);
	//left side of board game
	//space no: 46
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (15 * space_pixel_width));
	glEnd();
	space space46 = space(46, 0 * space_pixel_width + (space_pixel_width / 2), 14 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space46);
	//space no: 47
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space47 = space(47, 0 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space47);
	//space no: 48
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (13 * space_pixel_width));
	glEnd();
	space space48 = space(48, 0 * space_pixel_width + (space_pixel_width / 2), 12 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space48);
	//space no: 49
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (12 * space_pixel_width));
	glEnd();
	space space49 = space(49, 0 * space_pixel_width + (space_pixel_width / 2), 11 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space49);
	//space no: 50
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (11 * space_pixel_width));
	glEnd();
	space space50 = space(50, 0 * space_pixel_width + (space_pixel_width / 2), 10 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space50);
	//space no: 51
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (10 * space_pixel_width));
	glEnd();
	space space51 = space(51, 0 * space_pixel_width + (space_pixel_width / 2), 9 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space51);
	//space no: 52
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (9 * space_pixel_width));
	glEnd();
	space space52 = space(52, 0 * space_pixel_width + (space_pixel_width / 2), 8 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space52);
	//space no: 53
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (8 * space_pixel_width));
	glEnd();
	space space53 = space(53, 0 * space_pixel_width + (space_pixel_width / 2), 7 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space53);
	//space no: 54
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (7 * space_pixel_width));
	glEnd();
	space space54 = space(54, 0 * space_pixel_width + (space_pixel_width / 2), 6 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space54);
	//space no: 55
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (6 * space_pixel_width));
	glEnd();
	space space55 = space(55, 0 * space_pixel_width + (space_pixel_width / 2), 5 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space55);
	//space no: 56
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (5 * space_pixel_width));
	glEnd();
	space space56 = space(56, 0 * space_pixel_width + (space_pixel_width / 2), 4 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space56);
	//space no: 57
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (4 * space_pixel_width));
	glEnd();
	space space57 = space(57, 0 * space_pixel_width + (space_pixel_width / 2), 3 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space57);
	//space no: 58
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space58 = space(58, 0 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space58);
	//space no: 59
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (2 * space_pixel_width));
	glEnd();
	space space59 = space(59, 0 * space_pixel_width + (space_pixel_width / 2), 1 * space_pixel_width + (space_pixel_width / 2));
	game_board.push_back(space59);
	//draw red home stretch
	//space no: 60
	glBegin(GL_QUADS);
	glColor3f(1, 0.9, 0.9);
	glVertex2i((2 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (2 * space_pixel_width));
	glEnd();
	space space60 = space(60, 2 * space_pixel_width + (space_pixel_width / 2), 1 * space_pixel_width + (space_pixel_width / 2));
	red_home_run.push_back(space60);
	//space no: 61
	glBegin(GL_QUADS);
	glColor3f(1, 0.8, 0.8);
	glVertex2i((2 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space61 = space(61, 2 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	red_home_run.push_back(space61);
	//space no: 62
	glBegin(GL_QUADS);
	glColor3f(1, 0.7, 0.7);
	glVertex2i((2 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (4 * space_pixel_width));
	glEnd();
	space space62 = space(62, 2 * space_pixel_width + (space_pixel_width / 2), 3 * space_pixel_width + (space_pixel_width / 2));
	red_home_run.push_back(space62);
	//space no: 63
	glBegin(GL_QUADS);
	glColor3f(1, 0.6, 0.6);
	glVertex2i((2 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (5 * space_pixel_width));
	glEnd();
	space space63 = space(63, 2 * space_pixel_width + (space_pixel_width / 2), 3 * space_pixel_width + (space_pixel_width / 2));
	red_home_run.push_back(space63);
	//space no: 64
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0.5);
	glVertex2i((2 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (6 * space_pixel_width));
	glEnd();
	space space64 = space(64, 2 * space_pixel_width + (space_pixel_width / 2), 4 * space_pixel_width + (space_pixel_width / 2));
	red_home_run.push_back(space64);
	//blue home run
	//space no: 65
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 1);
	glVertex2i((14 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space65 = space(65, 14 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	blue_home_run.push_back(space65);
	//space no: 66
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 1);
	glVertex2i((13 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space66 = space(66, 13 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	blue_home_run.push_back(space66);
	//space no: 67
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 1);
	glVertex2i((12 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space67 = space(67, 12 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	blue_home_run.push_back(space67);
	//space no: 68
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1);
	glVertex2i((11 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space68 = space(68, 11 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	blue_home_run.push_back(space68);
	//space no: 69
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 1);
	glVertex2i((10 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	space space69 = space(69, 10 * space_pixel_width + (space_pixel_width / 2), 2 * space_pixel_width + (space_pixel_width / 2));
	blue_home_run.push_back(space69);
	//yellow home run
	//space no: 70
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.9);
	glVertex2i((13 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (15 * space_pixel_width));
	glEnd();
	space space70 = space(70, 13 * space_pixel_width + (space_pixel_width / 2), 14 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space70);
	//space no: 71
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.8);
	glVertex2i((13 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space71 = space(71, 13 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space71);
	//space no: 72
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.7);
	glVertex2i((13 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (13 * space_pixel_width));
	glEnd();
	space space72 = space(72, 13 * space_pixel_width + (space_pixel_width / 2), 12 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space72);
	//space no: 73
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.6);
	glVertex2i((13 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (12 * space_pixel_width));
	glEnd();
	space space73 = space(73, 13 * space_pixel_width + (space_pixel_width / 2), 11 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space73);
	//space no: 74
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.5);
	glVertex2i((13 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (11 * space_pixel_width));
	glEnd();
	space space74 = space(74, 13 * space_pixel_width + (space_pixel_width / 2), 10 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space74);
	//green home run
	//space no: 75
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((1 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space75 = space(75, 1 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space75);
	//space no: 76
	glBegin(GL_QUADS);
	glColor3f(0.7, 1, 0.7);
	glVertex2i((2 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space76 = space(76, 2 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space76);
	//space no: 77
	glBegin(GL_QUADS);
	glColor3f(0.6, 1, 0.6);
	glVertex2i((3 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space77 = space(77, 3 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space77);
	//space no: 78
	glBegin(GL_QUADS);
	glColor3f(0.5, 1, 0.5);
	glVertex2i((4 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space78 = space(78, 4 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space78);
	//space no: 79
	glBegin(GL_QUADS);
	glColor3f(0.4, 1, 0.4);
	glVertex2i((5 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	space space79 = space(79, 5 * space_pixel_width + (space_pixel_width / 2), 13 * space_pixel_width + (space_pixel_width / 2));
	yellow_home_run.push_back(space79);

    //Red slides
	//Author: Robbie Baranov
    glBegin(GL_TRIANGLES);
    glColor3f(1,0.5,0.5);
    glVertex2f(space_pixel_width,0);
    glVertex2f(1.5 * space_pixel_width,22);
    glVertex2f(space_pixel_width,45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0.5,0.5);
    glVertex2i(space_pixel_width+10, 15);
    glVertex2i(4.5 * space_pixel_width, 15);
    glVertex2i(4.5 * space_pixel_width, 30);
    glVertex2i(space_pixel_width+10, 30);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0.5, 0.5);
    glVertex2i(4.5 * space_pixel_width + (space_pixel_width / 2), space_pixel_width/2);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i(4 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
                   space_pixel_width/2 + 15 * sin(i * M_PI / 180.0));
    }
    glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1,0.5,0.5);
	glVertex2f(10 * space_pixel_width,0);
	glVertex2f(10.5 * space_pixel_width,22);
	glVertex2f(10 * space_pixel_width,45.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,0.5,0.5);
	glVertex2i(10 * space_pixel_width+10, 15);
	glVertex2i(14.5 * space_pixel_width, 15);
	glVertex2i(14.5 * space_pixel_width, 30);
	glVertex2i(10 * space_pixel_width+10, 30);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.5, 0.5);
	glVertex2i(14.5 * space_pixel_width + (space_pixel_width / 2), space_pixel_width/2);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(14 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
				   space_pixel_width/2 + 15 * sin(i * M_PI / 180.0));
	}
	glEnd();

	//blue slides
	//Author: Robbie Baranov
	glBegin(GL_TRIANGLES);
	glColor3f(0.5,0.5,1);
	glVertex2f(15 * space_pixel_width,space_pixel_width);
	glVertex2f(16 * space_pixel_width,space_pixel_width);
	glVertex2f(15 * space_pixel_width + space_pixel_width/2, 1.5 * space_pixel_width);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,1);
	glVertex2i(15.32 * space_pixel_width, 1.3 * space_pixel_width);
	glVertex2i(15.67* space_pixel_width, 1.3 * space_pixel_width);
	glVertex2i(15.67 * space_pixel_width, 4.5 * space_pixel_width);
	glVertex2i(15.32 * space_pixel_width, 4.5 * space_pixel_width);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5,0.5,1);
	glVertex2i(15 * space_pixel_width + (space_pixel_width / 2), 5 * space_pixel_width);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(15 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
				   4.5 * space_pixel_width + 15 * sin(i * M_PI / 180.0));
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5,0.5,1);
	glVertex2f(15 * space_pixel_width,10 * space_pixel_width);
	glVertex2f(16 * space_pixel_width,10 *space_pixel_width);
	glVertex2f(15 * space_pixel_width + space_pixel_width/2, 10.5 * space_pixel_width);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,1);
	glVertex2i(15.32 * space_pixel_width, 10.3 * space_pixel_width);
	glVertex2i(15.67* space_pixel_width, 10.3 * space_pixel_width);
	glVertex2i(15.67 * space_pixel_width, 14.5 * space_pixel_width);
	glVertex2i(15.32 * space_pixel_width, 14.5 * space_pixel_width);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5,0.5,1);
	glVertex2i(15 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(15 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
				   14.5 * space_pixel_width + 15 * sin(i * M_PI / 180.0));
	}
	glEnd();

	//yellow slides
	//Author: Robbie Baranov
	glBegin(GL_TRIANGLES);
	glColor3f(1,1,0.5);
	glVertex2f(15 * space_pixel_width,15 * space_pixel_width);
	glVertex2f(14.5 * space_pixel_width,15.5 * space_pixel_width);
	glVertex2f(15 * space_pixel_width,16 * space_pixel_width);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,0.5);
	glVertex2i(11.5 * space_pixel_width+10, 15.33 * space_pixel_width);
	glVertex2i(14.7 * space_pixel_width, 15.33 * space_pixel_width);
	glVertex2i(14.7 * space_pixel_width, 15.67 * space_pixel_width);
	glVertex2i(11.5 * space_pixel_width+10, 15.67 * space_pixel_width);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,0.5);
	glVertex2i(10.5 * space_pixel_width + (space_pixel_width / 2), 15.5 * space_pixel_width);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(11 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
				   15.5 * space_pixel_width + 15 * sin(i * M_PI / 180.0));
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1,1,0.5);
	glVertex2f(6 * space_pixel_width,15 * space_pixel_width);
	glVertex2f(5.5 * space_pixel_width,15.5 * space_pixel_width);
	glVertex2f(6 * space_pixel_width,16 * space_pixel_width);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,0.5);
	glVertex2i(1.5 * space_pixel_width+10, 15.33 * space_pixel_width);
	glVertex2i(5.7 * space_pixel_width, 15.33 * space_pixel_width);
	glVertex2i(5.7 * space_pixel_width, 15.67 * space_pixel_width);
	glVertex2i(1.5 * space_pixel_width+10, 15.67 * space_pixel_width);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,0.5);
	glVertex2i(0.5 * space_pixel_width + (space_pixel_width / 2), 15.5 * space_pixel_width);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(1 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
				   15.5 * space_pixel_width + 15 * sin(i * M_PI / 180.0));
	}
	glEnd();

	//green slides
	//Author: Robbie Baranov
	glBegin(GL_TRIANGLES);
	glColor3f(0.5,1,0.5);
	glVertex2f(0,15 * space_pixel_width);
	glVertex2f(space_pixel_width,15 * space_pixel_width);
	glVertex2f(space_pixel_width - space_pixel_width/2, 14.5 * space_pixel_width);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,1,0.5);
	glVertex2i(0.32 * space_pixel_width, 11.5 * space_pixel_width);
	glVertex2i(0.67* space_pixel_width, 11.5 * space_pixel_width);
	glVertex2i(0.67 * space_pixel_width, 14.7 * space_pixel_width);
	glVertex2i(0.32 * space_pixel_width, 14.7 * space_pixel_width);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5,1,0.5);
	glVertex2i(0 * space_pixel_width + (space_pixel_width / 2), 11 * space_pixel_width);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(0 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
				   11.5 * space_pixel_width + 15 * sin(i * M_PI / 180.0));
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5,1,0.5);
	glVertex2f(0,6 * space_pixel_width);
	glVertex2f(space_pixel_width,6 * space_pixel_width);
	glVertex2f(space_pixel_width - space_pixel_width/2, 5.5 * space_pixel_width);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5,1,0.5);
	glVertex2i(0.32 * space_pixel_width, 5.7 * space_pixel_width);
	glVertex2i(0.67* space_pixel_width, 5.7 * space_pixel_width);
	glVertex2i(0.67 * space_pixel_width, 1.5 * space_pixel_width);
	glVertex2i(0.32 * space_pixel_width, 1.5 * space_pixel_width);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5,1,0.5);
	glVertex2i(0 * space_pixel_width + (space_pixel_width / 2), 1 * space_pixel_width);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(0 * space_pixel_width + (space_pixel_width / 2) + 15 * cos(i * M_PI / 180.0),
				   1.5 * space_pixel_width + 15 * sin(i * M_PI / 180.0));
	}
	glEnd();





	string sorry = "SORRY";
	glColor3f(0, 0, 0);
	glRasterPos2i(325, 350);
	for (int i = 0; i < sorry.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, sorry[i]);
	}

	//draw home and start spaces
	//Red home
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.4, 0.4);
	glVertex2i(2 * space_pixel_width + (space_pixel_width / 2), 4 * space_pixel_width + 55);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(2 * space_pixel_width + (space_pixel_width / 2) + 55 * cos(i * M_PI / 180.0),
				   6 * space_pixel_width + 55 + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//add spaces for home
	

	//red start
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.4, 0.4);
	glVertex2i(4 * space_pixel_width + (space_pixel_width / 2), space_pixel_width + 55);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(4 * space_pixel_width + (space_pixel_width / 2) + 55 * cos(i * M_PI / 180.0),
				   55 + space_pixel_width + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//blue home
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 0.4, 1);
	glVertex2i(11.5 * space_pixel_width + (space_pixel_width / 2) - 55, 2 * space_pixel_width + (space_pixel_width / 2));
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(10 * space_pixel_width - 55 + 55 * cos(i * M_PI / 180.0),
				   2 * space_pixel_width + (space_pixel_width / 2) + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//blue start
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 0.4, 1);
	glVertex2i(15 * space_pixel_width + (space_pixel_width / 2) - 55, 4 * space_pixel_width + (space_pixel_width / 2));
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(15 * space_pixel_width - 55 + 55 * cos(i * M_PI / 180.0),
				   4 * space_pixel_width + (space_pixel_width / 2) + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//yellow home
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 0.5);
	glVertex2i(13 * space_pixel_width + (space_pixel_width / 2), 12 * space_pixel_width - 55);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(13 * space_pixel_width + (space_pixel_width / 2) + 55 * cos(i * M_PI / 180.0),
				   10 * space_pixel_width - 50+ 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//yellow start
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 0.7);
	glVertex2i(11 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width - 55);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(11 * space_pixel_width + (space_pixel_width / 2) + 55 * cos(i * M_PI / 180.0),
				   15 * space_pixel_width - 55 + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//green home
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 1, 0.4);
	glVertex2i(3.5 * space_pixel_width + (space_pixel_width / 2) + 55, 13 * space_pixel_width + (space_pixel_width / 2));
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(6 * space_pixel_width + 55 + 55 * cos(i * M_PI / 180.0),
				   13 * space_pixel_width + (space_pixel_width / 2) + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//green start
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 1, 0.6);
	glVertex2i(1 * space_pixel_width + (space_pixel_width / 2) + 55, 11 * space_pixel_width + (space_pixel_width / 2));
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(1 * space_pixel_width + 55 + 55 * cos(i * M_PI / 180.0),
				   11 * space_pixel_width + (space_pixel_width / 2) + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();



	//draw the card decks
	//Author: Jay Brideau
	//Discard deck
	if (discard_deck.deck.size() != 0) {
		glBegin(GL_QUADS);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2i(740, 20);
		glVertex2i(1090, 20);
		glVertex2i(1090, 220);
		glVertex2i(740, 220);
		glEnd();
		string discard_label = "Discard pile";
		glColor3f(0, 0, 0);
		glRasterPos2i(740, 40);
		for (int i = 0; i < discard_label.length(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, discard_label[i]);
		}
	}

	//Draw deck
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i(740, 240);
	glVertex2i(1090, 240);
	glVertex2i(1090, 440);
	glVertex2i(740, 440);
	glEnd();
	//draw card's rules
	glColor3f(0, 0, 0);
	glRasterPos2i(740, 270);
	for (int i = 0; i < card_face.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, card_face[i]);
	}
	glColor3f(0, 0, 0);
	glRasterPos2i(740, 300);
	for (int i = 0; i < card_rules.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, card_rules[i]);
	}

}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
//Author: Professor Lisa Dion
void display() {
	// tell OpenGL to use the whole window for drawing
	glViewport(0, 0, width, height);

	// do an orthographic parallel projection with the coordinate
	// system set to first quadrant, limited by screen/window size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//draw the game board gui
	draw_gameboard();

	//draw pieces
	//draw red pieces
	red1.draw(red1_x, red1_y);
	red2.draw(red2_x, red2_y);
	red3.draw(red3_x, red3_y);
	red4.draw(red4_x, red4_y);

	red_start.push_back(red1);
	red_start.push_back(red2);
	red_start.push_back(red3);
	red_start.push_back(red4);

	//draw blue pieces
	blue1.draw(blue1_x, blue1_y);
	blue2.draw(blue2_x, blue2_y);
	blue3.draw(blue3_x, blue3_y);
	blue4.draw(blue4_x, blue4_y);

	blue_start.push_back(blue1);
	blue_start.push_back(blue2);
	blue_start.push_back(blue3);
	blue_start.push_back(blue4);
	//draw yellow pieces
	yellow1.draw(yellow1_x, yellow1_y);
	yellow2.draw(yellow2_x, yellow2_y);
	yellow3.draw(yellow3_x, yellow3_y);
	yellow4.draw(yellow4_x, yellow4_y);

	yellow_start.push_back(yellow1);
	yellow_start.push_back(yellow2);
	yellow_start.push_back(yellow3);
	yellow_start.push_back(yellow4);
	//draw green pieces
	green1.draw(green1_x, green1_y);
	green2.draw(green2_x, green2_y);
	green3.draw(green3_x, green3_y);
	green4.draw(green4_x, green4_y);

	green_start.push_back(green1);
	green_start.push_back(green2);
	green_start.push_back(green3);
	green_start.push_back(green4);
	glFlush();  // Render now
}

// handle keyboard input
void kbd(unsigned char key, int x, int y) {

	glutPostRedisplay();

	return;
}

//move method
//Author: Jay Brideau and Robbie Baranov
void move_piece(int &x, int &y, piece p, card c) {
	if (c.startable) {
		//red start
		if (p.get_fill().red == 1 && p.get_fill().green == 0) {
			x = game_board[4].get_x_center();
			y = game_board[4].get_y_center();
		}
		//blue start
		else if (p.get_fill().blue == 1) {
			x = game_board[19].get_x_center();
			y = game_board[19].get_y_center();
		}
		//yellow start
		else if (p.get_fill().red == 1 && p.get_fill().green == 1) {
			x = game_board[34].get_x_center();
			y = game_board[34].get_y_center();
		}
		//green start
		else if (p.get_fill().green == 1 && p.get_fill().red == 0) {
			x = game_board[49].get_x_center();
			y = game_board[49].get_y_center();
		}
	}
	else if (c.get_face() == "3"){
		if (p.get_fill().red == 1 && p.get_fill().green == 0
			&& p.get_fill().blue == 0) {
			x = 7 * space_pixel_width + (space_pixel_width / 2);
			y = space_pixel_width / 2;
		}
	}
	glutPostRedisplay();
}

//allow user to click things
//Author: Jay Brideau
void mouse(int button, int state, int x, int y) {
	//user can click on a test piece to move it around the board
	//Author: Jay Brideau
	if (state == GLUT_DOWN){
		if (
			//piece red1
				x >= red1_x - (space_pixel_width/2) && x <= red1_x + space_pixel_width/2
				&& y >= red1_y - (space_pixel_width/2) && y <= red1_y + space_pixel_width/2
				) {
			move_piece(red1_x, red1_y, red1, drawn_card);
		}
		else if (
			//piece red2
				x >= red2_x - (space_pixel_width / 2) && x <= red2_x + space_pixel_width / 2
				&& y >= red2_y - (space_pixel_width / 2) && y <= red2_y + space_pixel_width / 2
				) {

			move_piece(red2_x, red2_y, red2, drawn_card);
		}
		else if (
			//piece red3
				x >= red3_x - (space_pixel_width / 2) && x <= red3_x + space_pixel_width / 2
				&& y >= red3_y - (space_pixel_width / 2) && y <= red3_y + space_pixel_width / 2
				) {
			move_piece(red3_x, red3_y, red3, drawn_card);
		}
		else if (
			//piece red4
				x >= red4_x - (space_pixel_width / 2) && x <= red4_x + space_pixel_width / 2
				&& y >= red4_y - (space_pixel_width / 2) && y <= red4_y + space_pixel_width / 2
				) {
			move_piece(red4_x, red4_y, red4, drawn_card);
		}
		else if (
			//piece blue1
			x >= blue1_x - (space_pixel_width / 2) && x <= blue1_x + space_pixel_width / 2
			&& y >= blue1_y - (space_pixel_width / 2) && y <= blue1_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(blue1_x, blue1_y, blue1, drawn_card);
		}
		else if (
			//piece blue2
			x >= blue2_x - (space_pixel_width / 2) && x <= blue2_x + space_pixel_width / 2
			&& y >= blue2_y - (space_pixel_width / 2) && y <= blue2_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(blue2_x, blue2_y, blue2, drawn_card);
		}
		else if (
			//piece blue3
			x >= blue3_x - (space_pixel_width / 2) && x <= blue3_x + space_pixel_width / 2
			&& y >= blue3_y - (space_pixel_width / 2) && y <= blue3_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(blue3_x, blue3_y, blue3, drawn_card);
		}
		else if (
			//piece blue4
			x >= blue4_x - (space_pixel_width / 2) && x <= blue4_x + space_pixel_width / 2
			&& y >= blue4_y - (space_pixel_width / 2) && y <= blue4_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(blue4_x, blue4_y, blue4, drawn_card);
		}
		else if (
			//piece yellow1
			x >= yellow1_x - (space_pixel_width / 2) && x <= yellow1_x + space_pixel_width / 2
			&& y >= yellow1_y - (space_pixel_width / 2) && y <= yellow1_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(yellow1_x, yellow1_y, yellow1, drawn_card);
		}
		else if (
			//piece yellow2
			x >= yellow2_x - (space_pixel_width / 2) && x <= yellow2_x + space_pixel_width / 2
			&& y >= yellow2_y - (space_pixel_width / 2) && y <= yellow2_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(yellow2_x, yellow2_y, yellow2, drawn_card);
		}
		else if (
			//piece yellow3
			x >= yellow3_x - (space_pixel_width / 2) && x <= yellow3_x + space_pixel_width / 2
			&& y >= yellow3_y - (space_pixel_width / 2) && y <= yellow3_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(yellow3_x, yellow3_y, yellow3, drawn_card);
		}
		else if (
			//piece yellow4
			x >= yellow4_x - (space_pixel_width / 2) && x <= yellow4_x + space_pixel_width / 2
			&& y >= yellow4_y - (space_pixel_width / 2) && y <= yellow4_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(yellow4_x, yellow4_y, yellow4, drawn_card);
		}
		else if (
			//piece green1
			x >= green1_x - (space_pixel_width / 2) && x <= green1_x + space_pixel_width / 2
			&& y >= green1_y - (space_pixel_width / 2) && y <= green1_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(green1_x, green1_y, green1, drawn_card);
		}
		else if (
			//piece green2
			x >= green2_x - (space_pixel_width / 2) && x <= green2_x + space_pixel_width / 2
			&& y >= green2_y - (space_pixel_width / 2) && y <= green2_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(green2_x, green2_y, green2, drawn_card);
		}
		else if (
			//piece green3
			x >= green3_x - (space_pixel_width / 2) && x <= green3_x + space_pixel_width / 2
			&& y >= green3_y - (space_pixel_width / 2) && y <= green3_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(green3_x, green3_y, green3, drawn_card);
		}
		else if (
			//piece green4
			x >= green4_x - (space_pixel_width / 2) && x <= green4_x + space_pixel_width / 2
			&& y >= green4_y - (space_pixel_width / 2) && y <= green4_y + space_pixel_width / 2
			&& state == GLUT_DOWN
			) {
			move_piece(green4_x, green4_y, green4, drawn_card);
		}

	}


	/*else if (
		(x >= red1_x - (space_pixel_width / 2)) && (x <= red1_x + (space_pixel_width / 2))
		&& (y >= red1_y - (space_pixel_width / 2)) && (y <= red1_y + (space_pixel_width / 2))
		&& (red1_y + space_pixel_width / 2) < 15 * space_pixel_width
		&& (red1_x + space_pixel_width/2) >= 15 * space_pixel_width
		) {
		red1_y += space_pixel_width;
	}
	else if (
		(x >= red1_x - (space_pixel_width / 2)) && (x <= red1_x + (space_pixel_width / 2))
		&& (y >= red1_y - (space_pixel_width / 2)) && (y <= red1_y + (space_pixel_width / 2))
		&& (red1_y + (space_pixel_width/2) >= 15 * space_pixel_width)
		&& (red1_x -(space_pixel_width/2) > 0)
		) {
		red1_x -= space_pixel_width;
	}*/

	//let user draw a card from the deck
	//Author: Jay Brideau
	if (x >= 740 && x <= 1090 && y >= 240 && y <= 440
		&& state == GLUT_DOWN) {
		drawn_card = draw_and_discard_card();
		card_face = drawn_card.get_face();
		card_rules = drawn_card.human_rules;
	}

	glutPostRedisplay();
}

//timer function
//Author: Professor  Lisa Dion
void timer(int extra) {
	glutTimerFunc(60, timer, 0);
	glutPostRedisplay();
}



int graphicsPlay(int argc, char** argv) {

	init();

	glutInit(&argc, argv);          // Initialize GLUT

	glutInitDisplayMode(GLUT_RGBA);

	glutInitWindowSize((int)width, (int)height);
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	/* create the window and store the handle to it */
	wd = glutCreateWindow("Sorry!" /* title */);

	// Register callback handler for window re-paint event
	glutDisplayFunc(display);

	// Our own OpenGL initialization
	initGL();

	// register keyboard press event processing function
	// works for numbers, letters, spacebar, etc.
	glutKeyboardFunc(kbd);

	//handle clickability
	glutMouseFunc(mouse);

	// handles timer
	glutTimerFunc(0, timer, 0);

	// Enter the event-processing loop
	glutMainLoop();
	return 0;
}