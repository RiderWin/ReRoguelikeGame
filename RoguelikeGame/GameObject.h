//-----ReSpace-Engine-----
//	
//	«десь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include "GraphicObject.h"
#include "PhysicObject.h"


// Ѕазовый класс дл€ игровых объектов
// »гровой объект - объект, объедин€ющий графический и физический объекты
class GameObject: public BaseObject
{
protected:
	GraphicObject graphic;
	PhysicObject physic;

public:
	GameObject(const GraphicObject& _graphic, const PhysicObject& _physic);
	
	virtual void update(float elapsedTime) override;
	virtual void draw(sf::RenderWindow* window) override;

	GraphicObject& getGraphic();
	PhysicObject& getPhysic();
};

