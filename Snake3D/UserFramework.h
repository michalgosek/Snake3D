#pragma once
#include "StartMenuModule.h"
#include "EndMenuModule.h"

class UserFramework{
public:
	UserFramework();
	StartMenuModule * startMenuModule;
	EndMenuModule * endMenuModule;

	void runStartApplicationMenu();
	void runEndApplicationMenu();
};

