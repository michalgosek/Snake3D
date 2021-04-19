#pragma once
#include "Camera.h"

class Scene
{
private: 
	static void initLighting();
	static void renderPlane();
	static void renderSnake();
	
public:
	static void Render();

	Scene(Scene &other) = delete;
	void operator=(const Scene&) = delete; 
};

