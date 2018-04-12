#include <iostream>
#include "game_board.h"
#include "piece.h"
#include "graphics.hpp"
#include "card_deck.h"

using namespace std;

int wd;
int width, height;
//Graphics/GUI

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // almost black and opaque

}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	// tell OpenGL to use the whole window for drawing
	glViewport(0, 0, 1200, 900);

	// do an orthographic parallel projection with the coordinate
	// system set to first quadrant, limited by screen/window size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glFlush();  // Render now
}

void kbd(unsigned char key, int x, int y) //CHECK MORE OFTEN 
//only checks when key registers as pressed, overrides 'old' keypress data even if current
{
	//jump
	if (key == 32) {
		cout << "space key pressed!" << endl;
	}

	glutPostRedisplay();

	return;
}

void timer(int extra) {
	glutTimerFunc(60, timer, 0);
	glutPostRedisplay();
}

int main(int argc, char** argv) {

	//card deck
	card_deck deck = card_deck();
	deck.fill_deck();

	//test card deck fill
	//for (int i = 0; i < 45; i++) {
	//	card print = deck.get_card_at(i);
	//	print.print_info();
	//}
	
	//GUI

	//set window width and height
	width = 1200;
	height = 900;

	glutInit(&argc, argv);          // Initialize GLUT

	glutInitDisplayMode(GLUT_RGBA);

	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
									  /* create the window and store the handle to it */
	wd = glutCreateWindow("Sorry!" /* title */);

	// Register callback handler for window re-paint event
	glutDisplayFunc(display);

	// Our own OpenGL initialization
	initGL();

	// register keyboard press event processing function
	// works for numbers, letters, spacebar, etc.
	glutKeyboardFunc(kbd);

	// handles timer
	glutTimerFunc(0, timer, 0);

	// Enter the event-processing loop
	glutMainLoop();

    //Spaces my_space;
    //vector<Spaces> game_board;
    //for (int i = 1; i <= 60; i++){
        //bool has_piece;
        //game_board.push_back(Spaces(has_piece, i ));
    //}
    //cout << "The outside ring of the game board has " << game_board.size()<< " pieces" << endl;

	//keep window open
	cout << "Press Enter to close window" << endl;
	getchar();
	return 0;

    return 0;
}
