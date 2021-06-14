#pragma once
class SnakeBody
{
private:
	float xPos = 0;
	float yPos = 0;
	float zPos = 8;
	char direction;
	int plane;

public:
	float GetXPos();
	float GetYPos();
	float GetZPos();
	char GetDirection();
	void SetXPos(float x);
	void SetYPos(float y);
	void SetZPos(float z);
	void SetDirection(char direct);
	void SetPlane(int p);
	int GetPlane();
};