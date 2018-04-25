#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "graphics.h"

using namespace std;

int gameboardwidth, gameboardheight;
int gameboardwd;
int space_pixel_width = 45;

int test_piece_x = (4 * space_pixel_width + (space_pixel_width/2));
int test_piece_y = space_pixel_width / 2;

//TEST CLICKABILITY
int gameboardmouse_x, gameboardmouse_y;

void gameboardinit() {
    gameboardwidth = 1200;
    gameboardheight = 720;
    gameboardmouse_x = gameboardmouse_y = 0;
}

/* Initialize OpenGL Graphics */
void gameboardinitGL() {
    // Set "clearing" or background color
    glClearColor(0.1f, 0.1f, 0.5f, 1.0f); // almost black and opaque
    
}

void draw_gameboard() {
    //DRAW: base of the game board
    //AUTHOR: Jay Brideau
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
    
    //draw the card decks
    //Author: Jay Brideau
    //Discard deck
//    if (discard_deck.deck.size() != 0) {
//        glBegin(GL_QUADS);
//        glColor3f(0, 1, 0);
//        glVertex2i(740, 20);
//        glVertex2i(1090, 20);
//        glVertex2i(1090, 220);
//        glVertex2i(740, 220);
//        glEnd();
//    }
    
    //Draw deck
    glBegin(GL_QUADS);
    glColor3f(0, 1, 1);
    glVertex2i(740, 240);
    glVertex2i(940, 240);
    glVertex2i(940, 590);
    glVertex2i(740, 590);
    glEnd();
    
    //test circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);
    glVertex2i(test_piece_x, test_piece_y);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( test_piece_x + 20 * cos(i * M_PI / 180.0),
                   test_piece_y + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void gameboarddisplay() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, gameboardwidth, gameboardheight);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, gameboardwidth, gameboardheight, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    //draw the game board gui
    draw_gameboard();
    
    glFlush();  // Render now
}

void gameboardkbd(unsigned char key, int x, int y) {
    
    glutPostRedisplay();
    
    return;
}

//TEST CLICKABILITY
void gameboardmouse(int button, int state, int x, int y) {
    if (
        x >= test_piece_x - (space_pixel_width/2) && x <= test_piece_x + space_pixel_width/2 
        && y >= test_piece_y - (space_pixel_width/2) && y <= test_piece_y + space_pixel_width/2 
        && (test_piece_x + space_pixel_width / 2) < 15 * space_pixel_width 
        && (test_piece_y - space_pixel_width/2) == 0
        ) {	
        test_piece_x += space_pixel_width;
        init();
    }
    else if (
             (x >= test_piece_x - (space_pixel_width / 2)) && (x <= test_piece_x + (space_pixel_width / 2)) 	
             && (y >= test_piece_y - (space_pixel_width / 2)) && (y <= test_piece_y + (space_pixel_width / 2)) 
             && (test_piece_y + space_pixel_width / 2) < 15 * space_pixel_width 
             && (test_piece_x + space_pixel_width/2) >= 15 * space_pixel_width
             ) {
        test_piece_y += space_pixel_width;
        init();
    }
    else if (
             (x >= test_piece_x - (space_pixel_width / 2)) && (x <= test_piece_x + (space_pixel_width / 2))
             && (y >= test_piece_y - (space_pixel_width / 2)) && (y <= test_piece_y + (space_pixel_width / 2))
             && (test_piece_y + (space_pixel_width/2) >= 15 * space_pixel_width)
             && (test_piece_x -(space_pixel_width/2) > 0)
             ) {
        
        test_piece_x -= space_pixel_width;
        init();
    }
    
    
    if (x >= 740 && x <= 944 && y >= 240 && y <= 590) {
        
    }
    
    glutPostRedisplay();
}

void gameboardtimer(int extra) {
    glutTimerFunc(60, gameboardtimer, 0);
    glutPostRedisplay();
}



int gameboard(int argc, char** argv) {
    
    gameboardinit();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)gameboardwidth, (int)gameboardheight);
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    gameboardwd = glutCreateWindow("Sorry!" /* title */);
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(gameboarddisplay);
    
    // Our own OpenGL initialization
    gameboardinitGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(gameboardkbd);
    
    //handle clickability
    glutMouseFunc(gameboardmouse);
    
    // handles timer
    glutTimerFunc(0, gameboardtimer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
