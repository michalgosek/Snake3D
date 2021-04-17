#pragma once
#include "MouseAndKeyboardInteractionEngine.h"

class MenuModule{
public:
	MouseAndKeyboardInteractionEngine interactionEngine;
	virtual void buildGUI() = 0;
};

