#pragma once
#include <stack>
#include "GameObject.h"

class Map
{
private:
	int width;
	int height;
	std::vector<std::vector<GraphicObject*>> map;

	std::stack<sf::Vector2i> oldCells;
	sf::Vector2i cell;

public:
	Map();

	bool generate();
	void clear();
	void fun(sf::FloatRect point);
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);
	void debug();
};

