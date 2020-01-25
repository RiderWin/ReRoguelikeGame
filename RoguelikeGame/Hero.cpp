#include "Hero.h"

Hero::Hero() :GameObject(GraphicObject(GameData::texHero), PhysicObject())
{
	health = 0;
	speed = 200;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		graphic.rotate(-10 * elapsedTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		graphic.rotate(10 * elapsedTime);
	}

	graphic.move(velocity * speed * elapsedTime);
	velocity.x = 0;
	velocity.y = 0;
}