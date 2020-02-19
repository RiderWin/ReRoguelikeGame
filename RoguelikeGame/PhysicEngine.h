#pragma once
#include <vector>
#include "PhysicObject.h"

class PhysicEngine
{
private:
	PhysicEngine();
	static sf::RenderWindow* window;

public:
	static void collision(const PhysicObject& obj);
};