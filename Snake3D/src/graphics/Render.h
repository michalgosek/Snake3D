#pragma once

#include "freeglut.h"

class Render
{
private:
	static const int WIDTH;
	static const int HEIGHT;

	void static renderPlane();
	void static renderSnake();

	void static prepareMatrixProjection();
	void static prepareModelView();

	void static enableGLCapabilities();
	void static displayFunc();

public:
	void static Run(int argc, char** argv);

	void operator=(const Render&) = delete; // not be assignable
	Render(Render&) = delete; // not clonable 
};