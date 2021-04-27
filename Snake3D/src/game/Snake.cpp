#include "Snake.h"

void Snake::SetLength(int l) {
	length = l;
}

int Snake::GetLength() {
	return length;
}

SnakeBody Snake::GetBodyPart(int index) {
	return body[index];
}