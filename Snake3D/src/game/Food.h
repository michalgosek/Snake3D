#pragma once
#include "FoodBody.h"
#include <stdlib.h>
#include <time.h>


class Food
{
private:
	FoodBody body; // max lenght of snake body 
	int length = 1;

public:
	Food() {
		srand(time(NULL));

		body.SetXPos(-6 + (rand() % 12));
		body.SetYPos(-2.5 + (rand() % 12));
		body.SetZPos(19);
	}

	int GetLength();
	void SetLength(int);
	FoodBody GetBodyPart();
};