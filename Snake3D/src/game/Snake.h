#pragma once
#include "SnakeBody.h"

class Snake
{
private:
	SnakeBody body[400]; // max lenght of snake body 
	int length = 1;

public:
	Snake() {
		body[0].SetXPos(10);
		body[1].SetXPos(9);

		for (int i = 0; i <= length; i++) {
			body[i].SetYPos(10);
			body[i].SetZPos(19);
		}
	}

	int GetLength();
	void SetLength(int);
	SnakeBody GetBodyPart(int);
};