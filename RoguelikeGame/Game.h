#pragma once
#include "GameObject.h"
#include <iostream>

class Game
{
private:
	sf::RenderWindow window;

	GameObject* gobj;

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

