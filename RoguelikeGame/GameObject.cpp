#include "GameObject.h"

GameObject::GameObject(const GraphicObject& _graphic, const PhysicObject& _physic):graphic(_graphic), physic(_physic)
{
	flag = GAME_OBJ;
}

void GameObject::update(float elapsedTime)
{
	physic.update(elapsedTime);
	graphic.update(elapsedTime);
	
}

void GameObject::draw(sf::RenderWindow* window)
{
	graphic.draw(window);
}

GraphicObject& GameObject::getGraphic()
{
	return graphic;
}

PhysicObject& GameObject::getPhysic()
{
	return physic;
}