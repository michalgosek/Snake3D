#pragma once
#include <GL/glut.h>

class Snake
{
private:
	GLint   size = 0;
	GLint   x;
	GLint   z;
	GLint   bodyPos[2][100] = { {} };

public:
	GLint GetSize();
	GLint GetX();
	GLint GetZ(); 
	GLint GetBodyPos(int i, int j);

	Snake(GLint x, GLint y) {
		this->x = x;
		this ->z = y;
	}
};

