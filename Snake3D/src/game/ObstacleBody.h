#pragma once
#include "ObstacleBody.h"

class ObstacleBody
{
private:
	float xPos;
	float yPos;
	float zPos;

public:
	float GetXPos();
	float GetYPos();
	float GetZPos();
	void SetXPos(float x);
	void SetYPos(float y);
	void SetZPos(float z);
};