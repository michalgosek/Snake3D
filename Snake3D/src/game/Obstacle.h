#pragma once
#include "ObstacleBody.h"
#include <stdlib.h>
#include <time.h>


class Obstacle
{
private:
	ObstacleBody body; // max lenght of snake body 
	int length = 1;

public:
	Obstacle(double x, double y) {
	//	srand(time(NULL));

		body.SetXPos(x);
		body.SetYPos(y);
		body.SetZPos(8);
	}

	int GetLength();
	void SetLength(int);
	ObstacleBody GetBodyPart();
};