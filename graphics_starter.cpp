/*
 * GL02Primitive.cpp: Vertex, Primitive and Color
 * Draw Simple 2D colored Shapes: quad, triangle and polygon.
 */

#include <cmath>
#include <iostream>
#include <fstream>
#include <math.h>
#include "piece.h"
#include "graphics.hpp"
#include "card_deck.h"
#include "card.h"
#include "space.h"

using namespace std;

enum screen_state {menu, game_play, pause, game_over};

screen_state screen = menu;

int startmouse_x, startmouse_y;
int startwidth, startheight;
int startwd;
int startsubwd;

string gameinfor[] = {"player","no","no","no"};


// player choose color
float changecolor1 = 1;
float changecolor2 = 0.3;
float changecolor3 = 0.35;

// computer1 level
float computer1lv11 = 1;
float computer1lv12 = 0.3;
float computer1lv13 = 0.35;

float computer1lv21 = 1;
float computer1lv22 = 0.3;
float computer1lv23 = 0.35;

float computer1lv31 = 1;
float computer1lv32 = 0.3;
float computer1lv33 = 0.35;

float computer1lv41 = 1;
float computer1lv42 = 0.3;
float computer1lv43 = 0.35;

// computer2 level
float computer2lv11 = 1;
float computer2lv12 = 0.3;
float computer2lv13 = 0.35;

float computer2lv21 = 1;
float computer2lv22 = 0.3;
float computer2lv23 = 0.35;

float computer2lv31 = 1;
float computer2lv32 = 0.3;
float computer2lv33 = 0.35;

float computer2lv41 = 1;
float computer2lv42 = 0.3;
float computer2lv43 = 0.35;


// computer2 level
float computer3lv11 = 1;
float computer3lv12 = 0.3;
float computer3lv13 = 0.35;

float computer3lv21 = 1;
float computer3lv22 = 0.3;
float computer3lv23 = 0.35;

float computer3lv31 = 1;
float computer3lv32 = 0.3;
float computer3lv33 = 0.35;

float computer3lv41 = 1;
float computer3lv42 = 0.3;
float computer3lv43 = 0.35;




void startinit() {
    startwidth = 1200;
    startheight = 720;
    startmouse_x = startmouse_y = 0;
    
    init();
    
}



/* Initialize OpenGL Graphics */
void startinitGL() {
    // Set "clearing" or background color
    glClearColor(0.1f, 0.1f, 0.5f, 1.0f); // almost black and opaque
    
}

void text(const char *text, int length, int x , int y){
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0,800,0,600,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    for (int i = 0; i < length; i ++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
        
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
    
}
/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void startdisplay() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, startwidth, startheight);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, startwidth, startheight, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    //DRAW: base of the game board
    //AUTHOR: Jay Brideau
    //16 spaces around the edge
    glColor3f(1, .3, .35);
    string textholle;
    textholle = "Wellcome to Sorry Game!!";
    text(textholle.data(), textholle.size(), 250, 550);
    
    string level1 = "lv1";
    string level2 = "lv2";
    string level3 = "lv3";
    string level4 = "lv4";
    
    
    
    glBegin(GL_QUADS);
    glColor3f(1, .3, .35);
    glVertex2i(150, 300);
    glVertex2i(250, 300);
    glVertex2i(250, 350);
    glVertex2i(150, 350);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    string textcomputer2;
    textcomputer2 = "Computer";
    glRasterPos2i(152,330);
    for(int i = 0; i < textcomputer2.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, textcomputer2[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer2lv11,computer2lv12,computer2lv13);
    glVertex2i(300 , 325);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 300 + 20 * cos(i * M_PI / 180.0),
                   325 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(285,330);
    for(int i = 0; i < level1.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level1[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer2lv21,computer2lv22,computer2lv23);
    glVertex2i(350 , 325);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 350 + 20 * cos(i * M_PI / 180.0),
                   325 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(335,330);
    for(int i = 0; i < level2.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level2[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer2lv31,computer2lv32,computer2lv33);
    glVertex2i(400 , 325);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 400 + 20 * cos(i * M_PI / 180.0),
                   325 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(385,330);
    for(int i = 0; i < level3.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level3[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer2lv41,computer2lv42,computer2lv43);
    glVertex2i(450 , 325);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 450 + 20 * cos(i * M_PI / 180.0),
                   325 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(435,330);
    for(int i = 0; i < level4.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level4[i]);
    }
    
    
    glBegin(GL_QUADS);
    glColor3f(1, .3, .35);
    glVertex2i(150, 450);
    glVertex2i(250, 450);
    glVertex2i(250, 400);
    glVertex2i(150, 400);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    string textcomputer3;
    textcomputer3 = "Computer";
    glRasterPos2i(152,430);
    for(int i = 0; i < textcomputer3.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, textcomputer3[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer3lv11,computer3lv12,computer3lv13);
    glVertex2i(300 , 425);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 300 + 20 * cos(i * M_PI / 180.0),
                   425 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(285,430);
    for(int i = 0; i < level1.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level1[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer3lv21,computer3lv22,computer3lv23);
    glVertex2i(350 , 425);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 350 + 20 * cos(i * M_PI / 180.0),
                   425 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(335,430);
    for(int i = 0; i < level2.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level2[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer3lv31,computer3lv32,computer3lv33);
    glVertex2i(400 , 425);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 400 + 20 * cos(i * M_PI / 180.0),
                   425 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(385,430);
    for(int i = 0; i < level3.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level3[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer3lv41,computer3lv42,computer3lv43);
    glVertex2i(450 , 425);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 450 + 20 * cos(i * M_PI / 180.0),
                   425 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(435,430);
    for(int i = 0; i < level4.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level4[i]);
    }
    
    
    glBegin(GL_QUADS);
    glColor3f(1, .3, .35);
    glVertex2i(150, 200);
    glVertex2i(250, 200);
    glVertex2i(250, 250);
    glVertex2i(150, 250);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    string textcomputer1;
    textcomputer1 = "Computer";
    glRasterPos2i(152,230);
    for(int i = 0; i < textcomputer1.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, textcomputer1[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer1lv11,computer1lv12,computer1lv13);
    glVertex2i(300 , 225);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 300 + 20 * cos(i * M_PI / 180.0),
                   225 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(285,230);
    for(int i = 0; i < level1.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level1[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer1lv21,computer1lv22,computer1lv23);
    glVertex2i(350 , 225);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 350 + 20 * cos(i * M_PI / 180.0),
                   225 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(335,230);
    for(int i = 0; i < level2.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level2[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer1lv31,computer1lv32,computer1lv33);
    glVertex2i(400 , 225);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 400 + 20 * cos(i * M_PI / 180.0),
                   225 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(385,230);
    for(int i = 0; i < level3.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level3[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(computer1lv41,computer1lv42,computer1lv43);
    glVertex2i(450 , 225);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 450 + 20 * cos(i * M_PI / 180.0),
                   225 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(435,230);
    for(int i = 0; i < level4.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level4[i]);
    }
    
    //player buttom
    
    
    glBegin(GL_QUADS);
    glColor3f(changecolor1,changecolor2,changecolor3);
    glVertex2i(150, 100);
    glVertex2i(250, 100);
    glVertex2i(250, 150);
    glVertex2i(150, 150);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    string textplayer;
    textplayer = "Player";
    glRasterPos2i(175,125);
    for(int i = 0; i < textplayer.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, textplayer[i]);
    }
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);
    glVertex2i(300 , 125);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 300 + 20 * cos(i * M_PI / 180.0),
                   125 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 0);
    glVertex2i(350 , 125);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 350 + 20 * cos(i * M_PI / 180.0),
                   125 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 1, 0);
    glVertex2i(400 , 125);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 400 + 20 * cos(i * M_PI / 180.0),
                   125 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 1);
    glVertex2i(450 , 125);
    for (int i = 0; i <= 360; ++i) {
        glVertex2i( 450 + 20 * cos(i * M_PI / 180.0),
                   125 + 20 * sin(i * M_PI / 180.0));
    }
    glEnd();
    //introduction
    glBegin(GL_QUADS);
    glColor3f(1, .3, .35);
    glVertex2i(450, 25);
    glVertex2i(575, 25);
    glVertex2i(575, 65);
    glVertex2i(450, 65);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    string textintro;
    textintro = "Introduction";
    glRasterPos2i(450,50);
    for(int i = 0; i < textintro.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, textintro[i]);
    }
    
    //start
    glBegin(GL_QUADS);
    glColor3f(1, .3, .35);
    glVertex2i(250, 500);
    glVertex2i(350, 500);
    glVertex2i(350, 550);
    glVertex2i(250, 550);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    string textbegin;
    textbegin = "Begin";
    glRasterPos2i(260,530);
    for(int i = 0; i < textbegin.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, textbegin[i]);
    }
    
    switch(screen) {
        case game_play:
            display();
            break;
    }
    


    
    glFlush();  // Render now
}

void displayintroduction() {
    
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, startwidth/2, startheight/2);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, startwidth/2, startheight/2, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    
    glBegin(GL_QUADS);
    glColor3f(1, .3, .35);
    glVertex2i(125, 250);
    glVertex2i(175, 250);
    glVertex2i(175, 275);
    glVertex2i(125, 275);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    string textbegin;
    textbegin = "Close";
    glRasterPos2i(140, 265);
    for(int i = 0; i < textbegin.length(); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, textbegin[i]);
    }
    
    
    
    glFlush();
  
    
}

void startkbd(unsigned char key, int x, int y) {
    
    glutPostRedisplay();
    
    return;
}

void starttimer(int extra) {
    glutTimerFunc(60, starttimer, 0);
    glutPostRedisplay();
}

void intromouse(int button, int state, int x, int y) {
    if (x >= 125 && x <= 175 && y >= 250
        && y <= 275) {
        glutDestroyWindow(startsubwd);
    }
}

void startmouse(int button, int state, int x, int y) {
    if (screen == game_play) {
        mouse(button, state, x, y);
    } else {
    
    if (x >= 250 && x <= 350 && y >= 500
        && y <= 550) {
        int countcomputernum = 0;
        for (int i = 1; i<4;i++){
            if (gameinfor[i] != "no"){
                countcomputernum +=1;
            }
        }
        
        if (gameinfor[0] == "player" || countcomputernum == 0){
            
            cout << "cant start game!!" <<endl;
            
        }else {
            
            cout << "Player :" << gameinfor[0] <<endl;
            cout << "Computer1 :" << gameinfor[1] <<endl;
            cout << "Computer2 :" << gameinfor[2] <<endl;
            cout << "Computer3 :" << gameinfor[3] <<endl;
            
            screen = game_play;
            
            
            
//            init();
//        
//            glutInitDisplayMode(GLUT_RGBA);
//        
//            glutInitWindowSize((int)width, (int)height);
//            glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
//        /* create the window and store the handle to it */
//            wd = glutCreateWindow("Sorry Game!" /* title */);
//        
//        // Register callback handler for window re-paint event
//            glutDisplayFunc(display);
//        
//        // Our own OpenGL initialization
//            initGL();
//        
//        // register keyboard press event processing function
//        // works for numbers, letters, spacebar, etc.
//            glutKeyboardFunc(kbd);
//        
//        // handles timer
//            glutTimerFunc(0, timer, 0);
//        
//        //clickable button
//            glutMouseFunc(mouse);
//        
//        // Enter the event-processing loop
//            glutMainLoop();
        }
        
    }
    
    if (x >= 450 && x <= 575 && y >= 25
        && y <= 65) {
        
        startinit();
        
        glutInitDisplayMode(GLUT_RGBA);
        
        glutInitWindowSize((int)startwidth/2, (int)startheight/2);
        glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
        /* create the window and store the handle to it */
        startsubwd = glutCreateWindow("Introduction!" /* title */);
        
        // Register callback handler for window re-paint event
        glutDisplayFunc(displayintroduction);
        
        // Our own OpenGL initialization
        startinitGL();
        
        // register keyboard press event processing function
        // works for numbers, letters, spacebar, etc.
        glutKeyboardFunc(startkbd);
        
        // handles timer
        glutTimerFunc(0, starttimer, 0);
        
        //clickable button
        glutMouseFunc(intromouse);
        
        // Enter the event-processing loop
        glutMainLoop();
    
    }
    
    if (x >= 285 && x <= 315 && y >= 110
        && y <= 140){
        
        gameinfor[0] = "red";
        changecolor1 = 1;
        changecolor2 = 0;
        changecolor3 = 0;
        
    }
    
    if (x >= 335 && x <= 365 && y >= 110
        && y <= 140){
        
        gameinfor[0] = "yellow";
        changecolor1 = 1;
        changecolor2 = 1;
        changecolor3 = 0;

    }
    
    if (x >= 385 && x <= 415 && y >= 110
        && y <= 140){
        
        gameinfor[0] = "green";
        changecolor1 = 0;
        changecolor2 = 1;
        changecolor3 = 0;
        
    }
    
    if (x >= 435 && x <= 465 && y >= 110
        && y <= 140){
        
        gameinfor[0] = "blue";
        changecolor1 = 0;
        changecolor2 = 0;
        changecolor3 = 1;
        
    }
    
    if (x >= 285 && x <= 315 && y >= 210
        && y <= 240){
        
        gameinfor[1] = "lv1";
        computer1lv11 = 1;
        computer1lv12 = 0;
        computer1lv13 = 0;
        
        computer1lv21 = 1;
        computer1lv22 = 0.3;
        computer1lv23 = 0.35;
        
        computer1lv31 = 1;
        computer1lv32 = 0.3;
        computer1lv33 = 0.35;
        
        computer1lv41 = 1;
        computer1lv42 = 0.3;
        computer1lv43 = 0.35;
        
        
    }
    
    if (x >= 335 && x <= 365 && y >= 210
        && y <= 240){
        
        gameinfor[1] = "lv2";
        computer1lv11 = 1;
        computer1lv12 = 0.3;
        computer1lv13 = 0.35;
        
        computer1lv21 = 1;
        computer1lv22 = 0;
        computer1lv23 = 0;
        
        computer1lv31 = 1;
        computer1lv32 = 0.3;
        computer1lv33 = 0.35;
        
        computer1lv41 = 1;
        computer1lv42 = 0.3;
        computer1lv43 = 0.35;
        
    }
    
    if (x >= 385 && x <= 415 && y >= 210
        && y <= 240){
        
        gameinfor[1] = "lv3";
        computer1lv11 = 1;
        computer1lv12 = 0.3;
        computer1lv13 = 0.35;
        
        computer1lv21 = 1;
        computer1lv22 = 0.3;
        computer1lv23 = 0.35;
        
        computer1lv31 = 1;
        computer1lv32 = 0;
        computer1lv33 = 0;
        
        computer1lv41 = 1;
        computer1lv42 = 0.3;
        computer1lv43 = 0.35;
        
    }
    
    if (x >= 435 && x <= 465 && y >= 210
        && y <= 240){
        
        gameinfor[1] = "lv4";
        computer1lv11 = 1;
        computer1lv12 = 0.3;
        computer1lv13 = 0.35;
        
        computer1lv21 = 1;
        computer1lv22 = 0.3;
        computer1lv23 = 0.35;
        
        computer1lv31 = 1;
        computer1lv32 = 0.3;
        computer1lv33 = 0.35;
        
        computer1lv41 = 1;
        computer1lv42 = 0;
        computer1lv43 = 0;
    }
    
    if (x >= 285 && x <= 315 && y >= 310
        && y <= 340){
        
        gameinfor[2] = "lv1";
        computer2lv11 = 1;
        computer2lv12 = 0;
        computer2lv13 = 0;
        
        computer2lv21 = 1;
        computer2lv22 = 0.3;
        computer2lv23 = 0.35;
        
        computer2lv31 = 1;
        computer2lv32 = 0.3;
        computer2lv33 = 0.35;
        
        computer2lv41 = 1;
        computer2lv42 = 0.3;
        computer2lv43 = 0.35;
        
    }
    
    if (x >= 335 && x <= 365 && y >= 310
        && y <= 340){
        
        gameinfor[2] = "lv2";
        computer2lv11 = 1;
        computer2lv12 = 0.3;
        computer2lv13 = 0.35;
        
        computer2lv21 = 1;
        computer2lv22 = 0;
        computer2lv23 = 0;
        
        computer2lv31 = 1;
        computer2lv32 = 0.3;
        computer2lv33 = 0.35;
        
        computer2lv41 = 1;
        computer2lv42 = 0.3;
        computer2lv43 = 0.35;
        
    }
    
    if (x >= 385 && x <= 415 && y >= 310
        && y <= 340){
        
        gameinfor[2] = "lv3";
        computer2lv11 = 1;
        computer2lv12 = 0.3;
        computer2lv13 = 0.35;
        
        computer2lv21 = 1;
        computer2lv22 = 0.3;
        computer2lv23 = 0.35;
        
        computer2lv31 = 1;
        computer2lv32 = 0;
        computer2lv33 = 0;
        
        computer2lv41 = 1;
        computer2lv42 = 0.3;
        computer2lv43 = 0.35;
        
    }
    
    if (x >= 435 && x <= 465 && y >= 310
        && y <= 340){
        
        gameinfor[2] = "lv4";
        computer2lv11 = 1;
        computer2lv12 = 0.3;
        computer2lv13 = 0.35;
        
        computer2lv21 = 1;
        computer2lv22 = 0.3;
        computer2lv23 = 0.35;
        
        computer2lv31 = 1;
        computer2lv32 = 0.3;
        computer2lv33 = 0.35;
        
        computer2lv41 = 1;
        computer2lv42 = 0;
        computer2lv43 = 0;
        
    }
    
    if (x >= 285 && x <= 315 && y >= 410
        && y <= 440){
        
        gameinfor[3] = "lv1";
        computer3lv11 = 1;
        computer3lv12 = 0;
        computer3lv13 = 0;
        
        computer3lv21 = 1;
        computer3lv22 = 0.3;
        computer3lv23 = 0.35;
        
        computer3lv31 = 1;
        computer3lv32 = 0.3;
        computer3lv33 = 0.35;
        
        computer3lv41 = 1;
        computer3lv42 = 0.3;
        computer3lv43 = 0.35;
        
    }
    
    if (x >= 335 && x <= 365 && y >= 410
        && y <= 440){
        
        gameinfor[3] = "lv2";
        computer3lv11 = 1;
        computer3lv12 = 0.3;
        computer3lv13 = 0.35;
        
        computer3lv21 = 1;
        computer3lv22 = 0;
        computer3lv23 = 0;
        
        computer3lv31 = 1;
        computer3lv32 = 0.3;
        computer3lv33 = 0.35;
        
        computer3lv41 = 1;
        computer3lv42 = 0.3;
        computer3lv43 = 0.35;
    }
    
    if (x >= 385 && x <= 415 && y >= 410
        && y <= 440){
        
        gameinfor[3] = "lv3";
        computer3lv11 = 1;
        computer3lv12 = 0.3;
        computer3lv13 = 0.35;
        
        computer3lv21 = 1;
        computer3lv22 = 0.3;
        computer3lv23 = 0.35;
        
        computer3lv31 = 1;
        computer3lv32 = 0;
        computer3lv33 = 0;
        
        computer3lv41 = 1;
        computer3lv42 = 0.3;
        computer3lv43 = 0.35;
        
    }
    
    if (x >= 435 && x <= 465 && y >= 410
        && y <= 440){
        
        gameinfor[3] = "lv4";
        computer3lv11 = 1;
        computer3lv12 = 0.3;
        computer3lv13 = 0.35;
        
        computer3lv21 = 1;
        computer3lv22 = 0.3;
        computer3lv23 = 0.35;
        
        computer3lv31 = 1;
        computer3lv32 = 0.3;
        computer3lv33 = 0.35;
        
        computer3lv41 = 1;
        computer3lv42 = 0;
        computer3lv43 = 0;
    }
        
    }
    
    
}

int start(int argc, char** argv) {
    
    startinit();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)startwidth, (int)startheight);
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
   startwd = glutCreateWindow("Sorry!" /* title */);
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(startdisplay);
    
    // Our own OpenGL initialization
    startinitGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(startkbd);
    
    // handles timer
    glutTimerFunc(0, starttimer, 0);
    
    //clickable button
    glutMouseFunc(startmouse);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
