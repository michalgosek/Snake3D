#pragma once

#include "freeglut.h"
#include "../graphics/Menu.h"

class Render
{
private:
	static const int WIDTH;
	static const int HEIGHT;
	static int POS_X;
	static int POS_Y;
 
	void static renderPlane();
	void static renderSnake();

	void static initializeCallbacks();

	void static prepareMatrixProjection();
	void static prepareModelView();
	void static reshapeFunc(int, int);
	void static enableGLCapabilities();

public:
	void static Run(int argc, char** argv);
	void static DrawGameBoard();

	void operator=(const Render&) = delete; // not be assignable
	Render(Render&) = delete; // not clonable 
};