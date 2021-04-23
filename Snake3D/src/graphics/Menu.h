#pragma once

#include "freeglut.h"

class Menu
{

private:
	static bool gameStart; 
	static void drawMenu();
public:
	static void DisplayFunc();
	static void Keyboard(unsigned char key, int x, int y);

};