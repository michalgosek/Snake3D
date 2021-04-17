#pragma once

#include "UserFramework.h"
#include "GameFramework.h"

class SnakeApplicationBuilder
{
public:
	SnakeApplicationBuilder();
	UserFramework *userFramework;
	GameFramework *gameFramework;
	void run();
};

