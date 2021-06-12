#pragma once
#include "SnakeBody.h"
#include "../graphics/Menu.h"
#include "freeglut.h"


#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#include <fstream>
#include <string>

static class Snake
{
private:
	static SnakeBody *body; // max lenght of snake body 
	static int length;
public:
	static bool load;
	static void initSnakeBody();
	static int GetLength();
	static void SetLength(int);
	static void Control_System();
	static void specialKeys(int key, int x, int y);
	static SnakeBody GetBodyPart(int);
};