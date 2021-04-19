#include "Snake.h"

GLint Snake::GetSize() {
	return this->size;
}

GLint Snake::GetX() {
	return this->x;
}

GLint Snake::GetZ() {
	return this->z;
}

GLint Snake::GetBodyPos(int i, int j) {
	return bodyPos[i][j];
}