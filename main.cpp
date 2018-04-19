#include <iostream>
#include "game_board.h"
#include "piece.h"
#include "graphics.hpp"
#include "card_deck.h"

using namespace std;

int width, height;
int wd;

void init() {
	width = 1200;
	height = 660;

}

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.1f, 0.1f, 0.5f, 1.0f); // almost black and opaque

}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
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

	//DRAW: base of the game board
	//AUTHOR: Jay Brideau
	//16 spaces around the edge
	int space_pixel_width = 40;
	glBegin(GL_QUADS);
	glColor3f(1, .3, .35);
	glVertex2i(15, 15);
	glVertex2i((16 * space_pixel_width), 15);
	glVertex2i((16 * space_pixel_width), (16 * space_pixel_width));
	glVertex2i(15, (16 * space_pixel_width));
	glEnd();

	glFlush();  // Render now
}

void kbd(unsigned char key, int x, int y) {

	glutPostRedisplay();

	return;
}

void timer(int extra) {
	glutTimerFunc(60, timer, 0);
	glutPostRedisplay();
}



int main(int argc, char** argv) {

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

	// handles timer
	glutTimerFunc(0, timer, 0);

	// Enter the event-processing loop
	glutMainLoop();
	return 0;
}
