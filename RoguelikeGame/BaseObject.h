#pragma once
#include <SFML\Graphics.hpp>
#include <iostream> // for debug
#include "GameData.h"
#include "GameConfig.h"

#define BASE_OBJ 0
#define GRAPHIC_OBJ 1
#define PHYSIC_OBJ 2
#define GAME_OBJ 3

class BaseObject
{
protected:
	static int numberOfObjects;
	int id;
	int flag;
public:
	BaseObject();

	virtual void input(sf::Event event) {};
	virtual void update(float elapsedTime) {};
	virtual void draw(sf::RenderWindow* window) {};
	virtual void debug() {};

	int getId();
	int getFlag();
};

