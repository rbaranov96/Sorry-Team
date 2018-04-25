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

using namespace std;

//initialize various global variables
int width, height;
int wd;
card_deck discard_deck;
card_deck draw_deck;
card drawn_card = card(one);
int space_pixel_width = 45;

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
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i(0, 0);
	glVertex2i((1 * space_pixel_width), 0);
	glVertex2i((1 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i(0, (1 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i(space_pixel_width, 0);
	glVertex2i((2 * space_pixel_width), 0);
	glVertex2i((2 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i(space_pixel_width, (1 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((2 * space_pixel_width), 0);
	glVertex2i((3 * space_pixel_width), 0);
	glVertex2i((3 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((3 * space_pixel_width), 0);
	glVertex2i((4 * space_pixel_width), 0);
	glVertex2i((4 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 0
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((4 * space_pixel_width), 0);
	glVertex2i((5 * space_pixel_width), 0);
	glVertex2i((5 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 1
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((5 * space_pixel_width), 0);
	glVertex2i((6 * space_pixel_width), 0);
	glVertex2i((6 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 2
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((6 * space_pixel_width), 0);
	glVertex2i((7 * space_pixel_width), 0);
	glVertex2i((7 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 3
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((7 * space_pixel_width), 0);
	glVertex2i((8 * space_pixel_width), 0);
	glVertex2i((8 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 4
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((8 * space_pixel_width), 0);
	glVertex2i((9 * space_pixel_width), 0);
	glVertex2i((9 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 5
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((9 * space_pixel_width), 0);
	glVertex2i((10 * space_pixel_width), 0);
	glVertex2i((10 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 6
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((10 * space_pixel_width), 0);
	glVertex2i((11 * space_pixel_width), 0);
	glVertex2i((11 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 7
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((11 * space_pixel_width), 0);
	glVertex2i((12 * space_pixel_width), 0);
	glVertex2i((12 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 8
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((12 * space_pixel_width), 0);
	glVertex2i((13 * space_pixel_width), 0);
	glVertex2i((13 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 9
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((13 * space_pixel_width), 0);
	glVertex2i((14 * space_pixel_width), 0);
	glVertex2i((14 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 10
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((14 * space_pixel_width), 0);
	glVertex2i((15 * space_pixel_width), 0);
	glVertex2i((15 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//space no: 11
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), 0);
	glVertex2i((16 * space_pixel_width), 0);
	glVertex2i((16 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (1 * space_pixel_width));
	glEnd();
	//right side of game board
	//space no: 12
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (2 * space_pixel_width));
	glEnd();
	//space no: 13
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//space no: 14
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (4 * space_pixel_width));
	glEnd();
	//space no: 15
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (5 * space_pixel_width));
	glEnd();
	//space no: 16
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (6 * space_pixel_width));
	glEnd();
	//space no: 17
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (7 * space_pixel_width));
	glEnd();
	//space no: 18
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (8 * space_pixel_width));
	glEnd();
	//space no: 19
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (9 * space_pixel_width));
	glEnd();
	//space no: 20
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (10 * space_pixel_width));
	glEnd();
	//space no: 21
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (11 * space_pixel_width));
	glEnd();
	//space no: 22
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (12 * space_pixel_width));
	glEnd();
	//space no: 23
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (13 * space_pixel_width));
	glEnd();
	//space no: 24
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//space no: 25
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((15 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (15 * space_pixel_width));
	glEnd();
	//space no: 26
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((15 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((16 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//bottom row of game board
	//space no: 27
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((14 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 28
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((13 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 29
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((12 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 30
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((11 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 31
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((10 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 32
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((9 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 33
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((8 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((9 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 34
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((7 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((8 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 35
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((6 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((7 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 36
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((5 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 37
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((4 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 38
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((3 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 39
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((2 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 40
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((1 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//space no: 41
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (16 * space_pixel_width));
	glEnd();
	//left side of board game
	//space no: 42
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (15 * space_pixel_width));
	glEnd();
	//space no: 43
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//space no: 44
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (13 * space_pixel_width));
	glEnd();
	//space no: 45
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (12 * space_pixel_width));
	glEnd();
	//space no: 46
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (11 * space_pixel_width));
	glEnd();
	//space no: 47
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (10 * space_pixel_width));
	glEnd();
	//space no: 48
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (9 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (9 * space_pixel_width));
	glEnd();
	//space no: 49
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (8 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (8 * space_pixel_width));
	glEnd();
	//space no: 50
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (7 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (7 * space_pixel_width));
	glEnd();
	//space no: 51
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (6 * space_pixel_width));
	glEnd();
	//space no: 52
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (5 * space_pixel_width));
	glEnd();
	//space no: 53
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (4 * space_pixel_width));
	glEnd();
	//space no: 54
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((0 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//space no: 55
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i((0 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((0 * space_pixel_width), (2 * space_pixel_width));
	glEnd();
	//draw red home stretch
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 0.9, 0.9);
	glVertex2i((2 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (1 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (2 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 0.8, 0.8);
	glVertex2i((2 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 0.7, 0.7);
	glVertex2i((2 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (4 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 0.6, 0.6);
	glVertex2i((2 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (4 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (5 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 0.5, 0.5);
	glVertex2i((2 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (5 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (6 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (6 * space_pixel_width));
	glEnd();
	//blue home run
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 1);
	glVertex2i((14 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((15 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 1);
	glVertex2i((13 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 1);
	glVertex2i((12 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 1);
	glVertex2i((11 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((12 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 1);
	glVertex2i((10 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (2 * space_pixel_width));
	glVertex2i((11 * space_pixel_width), (3 * space_pixel_width));
	glVertex2i((10 * space_pixel_width), (3 * space_pixel_width));
	glEnd();
	//yellow home run
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.9);
	glVertex2i((13 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (15 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (15 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.8);
	glVertex2i((13 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.7);
	glVertex2i((13 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (13 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.6);
	glVertex2i((13 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (12 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (12 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0.5);
	glVertex2i((13 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (10 * space_pixel_width));
	glVertex2i((14 * space_pixel_width), (11 * space_pixel_width));
	glVertex2i((13 * space_pixel_width), (11 * space_pixel_width));
	glEnd();
	//green home run
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.8, 1, 0.8);
	glVertex2i((1 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((1 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.7, 1, 0.7);
	glVertex2i((2 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((2 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.6, 1, 0.6);
	glVertex2i((3 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((3 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.5, 1, 0.5);
	glVertex2i((4 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((4 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//space no: 
	glBegin(GL_QUADS);
	glColor3f(0.4, 1, 0.4);
	glVertex2i((5 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (13 * space_pixel_width));
	glVertex2i((6 * space_pixel_width), (14 * space_pixel_width));
	glVertex2i((5 * space_pixel_width), (14 * space_pixel_width));
	glEnd();
	//draw home and start spaces
	//Red home
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.4, 0.4);
	glVertex2i(2 * space_pixel_width + (space_pixel_width / 2), 6 * space_pixel_width + 55);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(2 * space_pixel_width + (space_pixel_width / 2) + 55 * cos(i * M_PI / 180.0),
			6 * space_pixel_width + 55 + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
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
	glVertex2i(10 * space_pixel_width + (space_pixel_width / 2) - 55, 2 * space_pixel_width + (space_pixel_width / 2));
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
	glVertex2i(13 * space_pixel_width + (space_pixel_width / 2), 10 * space_pixel_width - 55);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(13 * space_pixel_width + (space_pixel_width / 2) + 55 * cos(i * M_PI / 180.0),
			10 * space_pixel_width - 55 + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//yellow start
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 0.5);
	glVertex2i(11 * space_pixel_width + (space_pixel_width / 2), 15 * space_pixel_width - 55);
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(11 * space_pixel_width + (space_pixel_width / 2) + 55 * cos(i * M_PI / 180.0),
			15 * space_pixel_width - 55 + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//green home
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 1, 0.4);
	glVertex2i(6 * space_pixel_width + (space_pixel_width / 2) + 55, 13 * space_pixel_width + (space_pixel_width / 2));
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(6 * space_pixel_width + 55 + 55 * cos(i * M_PI / 180.0),
			13 * space_pixel_width + (space_pixel_width / 2) + 55 * sin(i * M_PI / 180.0));
	}
	glEnd();
	//green start
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 1, 0.4);
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
	//draw blue pieces
	blue1.draw(blue1_x, blue1_y);
	blue2.draw(blue2_x, blue2_y);
	blue3.draw(blue3_x, blue3_y);
	blue4.draw(blue4_x, blue4_y);
	//draw yellow pieces
	yellow1.draw(yellow1_x, yellow1_y);
	yellow2.draw(yellow2_x, yellow2_y);
	yellow3.draw(yellow3_x, yellow3_y);
	yellow4.draw(yellow4_x, yellow4_y);
	//draw green pieces
	green1.draw(green1_x, green1_y);
	green2.draw(green2_x, green2_y);
	green3.draw(green3_x, green3_y);
	green4.draw(green4_x, green4_y);

	glFlush();  // Render now
}

// hande keyboard input
void kbd(unsigned char key, int x, int y) {

	glutPostRedisplay();

	return;
}

//move method
void move_piece(int &x, int &y, piece p, card c) {
	if (c.startable) {
		if (p.get_fill().red == 1 && p.get_fill().green == 0) {
			x = 4 * space_pixel_width + (space_pixel_width / 2);
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
	if (
		//piece red1
		x >= red1_x - (space_pixel_width/2) && x <= red1_x + space_pixel_width/2 
		&& y >= red1_y - (space_pixel_width/2) && y <= red1_y + space_pixel_width/2 
		&& state == GLUT_DOWN
		) {	
		move_piece(red1_x, red1_y, red1, drawn_card);
	}
	else if (
		//piece red2
		x >= red2_x - (space_pixel_width / 2) && x <= red2_x + space_pixel_width / 2
		&& y >= red2_y - (space_pixel_width / 2) && y <= red2_y + space_pixel_width / 2
		&& state == GLUT_DOWN
		) {
		move_piece(red2_x, red2_y, red2, drawn_card);
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