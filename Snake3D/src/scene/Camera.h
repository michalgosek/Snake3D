#pragma once
#include <GL/glut.h>

class Camera
{
private:
	GLfloat view_rotx;
	GLfloat view_roty;
	GLfloat view_rotz;
public:
	void ManipulateViewAngle();

	Camera(GLfloat view_rotx, GLfloat view_roty, GLfloat view_rotz) {
		this->view_rotx = view_rotx;
		this->view_roty = view_roty;
		this->view_rotz = view_rotz;
	}
};

