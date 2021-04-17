#include "SnakeApplicationBuilder.h"
#include <iostream>

SnakeApplicationBuilder::SnakeApplicationBuilder() {
	this->userFramework = new  UserFramework();
	this->gameFramework = new  GameFramework();

}

void SnakeApplicationBuilder::run() {
	userFramework->runStartApplicationMenu();
}