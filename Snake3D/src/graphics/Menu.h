#pragma once

#include "freeglut.h"
#include "../game/Snake.h"
#include "Render.h"

#include<iostream>
#include<fstream>

class Menu
{

private:
	//static bool gameStart; 
	static void drawMenu();
	static void drawQuitMenu();

public:
	static bool gameStart;
	static bool gameBreak;
	static bool gameLoad;
	static void DisplayFunc();
	static void loadToFile();
	static void loadFromFile();
	static void setGameLoad(bool);
	static bool returnGameLoad();
	static int returnLengthFile();
	static float* returnxPosFile();
	static float* returnyPosFile();
	static float* returnzPosFile();
	static char* returnDirectionFile();
	static int returnPointsFile();
	static float returnxAngleFile();
	static float returnyAngleFile();
	static float returnzAngleFile();
	static void prepareMatrixProjection();
	static void Keyboard(unsigned char key, int x, int y);
};