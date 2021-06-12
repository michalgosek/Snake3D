#pragma once

#include "freeglut.h"
#include "../game/Snake.h"

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
	static void Keyboard(unsigned char key, int x, int y);

};