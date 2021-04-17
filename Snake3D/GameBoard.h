#pragma once
#include "Snake.h"
#include "GameElement.h"
#include "Food.h"

class GameBoard
{
public:
	GameBoard();
	Snake * snake;
	Food* food;
};

