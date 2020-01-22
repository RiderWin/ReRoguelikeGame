#include "GameObject.h"

GameObject::GameObject(const GraphicObject& _graphic, const PhysicObject& _physic):graphic(_graphic), physic(_physic)
{
	
}

GraphicObject& GameObject::getGraphic()
{
	return graphic;
}

PhysicObject& GameObject::getPhysic()
{
	return physic;
}