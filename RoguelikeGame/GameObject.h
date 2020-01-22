#pragma once
#include "GraphicObject.h"
#include "PhysicObject.h"

class GameObject
{
private:
	GraphicObject graphic;
	PhysicObject physic;

public:
	GameObject(const GraphicObject& _graphic, const PhysicObject& _physic);
	
	void update();

	GraphicObject& getGraphic();
	PhysicObject& getPhysic();
};

