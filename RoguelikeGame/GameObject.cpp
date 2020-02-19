#include "GameObject.h"
#include "StandartInclude.h"

GameObject::GameObject(const GraphicObject& _graphic, const PhysicObject& _physic):graphic(_graphic), physic(_physic)
{
}

void GameObject::update(float elapsedTime)
{
	physic.update(elapsedTime);
	graphic.update(elapsedTime);
}

void GameObject::output()
{
	physic.output();
	graphic.output();

}

GraphicObject& GameObject::getGraphic()
{
	return graphic;
}

PhysicObject& GameObject::getPhysic()
{
	return physic;
}