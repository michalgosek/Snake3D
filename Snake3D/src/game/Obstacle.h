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
	Obstacle() {
	//	srand(time(NULL));

		body.SetXPos(-6 + (rand() % 12));
		body.SetYPos(-2.5 + (rand() % 12));
		body.SetZPos(19);
	}

	int GetLength();
	void SetLength(int);
	ObstacleBody GetBodyPart();
};