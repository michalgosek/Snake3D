#pragma once
#include <GL/glut.h>

class Render
{
private:
	static GLint   w;
	static GLint   h;

	static void enableGLCapabilities();
	static void resize(int w, int h);
public:
	static void InitGL(int argc, char** argv);
};

