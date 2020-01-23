#pragma once
#include "GameObject.h"

class Hero: public GameObject
{
private:
	int health;
	sf::Vector2f velocity;
	float speed;
	
public:
	Hero();
	void input(sf::Event event) override;
	void update(float elapsedTime) override;
};

