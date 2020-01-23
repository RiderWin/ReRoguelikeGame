#pragma once
#include "GraphicObject.h"
#include "PhysicObject.h"

class GameObject: public BaseObject
{
private:
	GraphicObject graphic;
	PhysicObject physic;

public:
	GameObject(const GraphicObject& _graphic, const PhysicObject& _physic);
	
	virtual void update(float elapsedTime) override;
	virtual void draw(sf::RenderWindow* window) override;

	GraphicObject& getGraphic();
	PhysicObject& getPhysic();
};

