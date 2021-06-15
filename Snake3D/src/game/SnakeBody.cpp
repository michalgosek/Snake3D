#include "SnakeBody.h"

 
void SnakeBody::SetZPos(float z) {
	zPos = z;
}


void SnakeBody::SetYPos(float y) {
	yPos = y;
}

void SnakeBody::SetXPos(float x) {
	xPos = x;
}

void SnakeBody::SetDirection(char direct)
{
	direction = direct;
}


float SnakeBody::GetZPos() {
	return zPos;
}

float SnakeBody::GetYPos() {
	return yPos;
}

float SnakeBody::GetXPos() {
	return xPos;
}

char SnakeBody::GetDirection()
{
	return direction;
}
