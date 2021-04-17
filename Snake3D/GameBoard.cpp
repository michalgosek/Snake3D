#include "GameBoard.h"

GameBoard::GameBoard() {
	this->snake = new Snake();
	this->food = new Food();
}