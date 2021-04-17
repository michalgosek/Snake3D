#include "UserFramework.h"

#include <iostream>

UserFramework::UserFramework() {
	this->startMenuModule = new StartMenuModule();
	this->endMenuModule = new EndMenuModule();
}

void UserFramework::runStartApplicationMenu() {
	startMenuModule->buildGUI();
}

void UserFramework::runEndApplicationMenu() {
	endMenuModule->buildGUI();
}

