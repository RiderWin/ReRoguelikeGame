#pragma once
#include "GraphicObject.h"

class Map
{
private:
	int width;
	int height;
	std::vector<std::vector<GraphicObject>> map;

public:
	Map();

	void fun(sf::FloatRect point);
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);
	void debug();
};

