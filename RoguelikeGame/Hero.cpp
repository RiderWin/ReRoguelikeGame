#include "Hero.h"

Hero::Hero() :GameObject(GraphicObject("resources/img/hero.png", sf::IntRect(0, 192, 96, 96)), PhysicObject())
{
	speed = 40;
}

void Hero::input(sf::Event event)
{
	
}

void Hero::update(float elapsedTime)
{
	// Moving
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = 1;
	}

	graphic.move(velocity * speed * elapsedTime);
	velocity.x = 0;
	velocity.y = 0;
}