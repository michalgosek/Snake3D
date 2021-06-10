#pragma once
class SnakeBody
{
private:
	float xPos;
	float yPos;
	float zPos;
	char direction;

public:
	float GetXPos();
	float GetYPos();
	float GetZPos();
	char GetDirection();
	void SetXPos(float x);
	void SetYPos(float y);
	void SetZPos(float z);
	void SetDirection(char direct);
};