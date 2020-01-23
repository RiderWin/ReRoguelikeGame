#pragma once
#include "GameObject.h"
#include "Hero.h"
#include <vector>

class Game
{
private:
	sf::RenderWindow window;

	std::vector<BaseObject*> objects;
	GraphicObject* graphObj;
	PhysicObject* physObj;
	GameObject* gameObj;
	Hero* hero;

public:
	static sf::Vector2u resolution;
	static sf::String title;

	Game();
	void init();
	void start();
	void input(sf::Event event);
	void update(float elapsedTime);
	void draw();

};

