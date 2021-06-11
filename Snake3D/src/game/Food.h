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
	Food(double x, double y) {
		body.SetXPos(x);
		body.SetYPos(y);
		body.SetZPos(19);
	}

	int GetLength();
	void SetLength(int);
	FoodBody GetBodyPart();
};