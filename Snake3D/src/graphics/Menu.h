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
	static void DisplayFunc();
	static void loadToFile();
	static void prepareMatrixProjection();
	static void Keyboard(unsigned char key, int x, int y);

};