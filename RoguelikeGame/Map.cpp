#include "Map.h"

Map::Map()
{
	width = 16;
	height = 9;
	map = std::vector<std::vector<GraphicObject>>(height, std::vector<GraphicObject>(width, GraphicObject(GameData::texBox)));
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[i][j].setPosition(50 * i, 50 * j);
		}
	}
}

void Map::fun(sf::FloatRect point)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j].getGlobalBounds().intersects(point))
			{
				map[i][j].setColor(sf::Color::Red);
			}
			else
			{
				map[i][j].setColor(sf::Color::White);
			}
		}
	}
}

void Map::update(float elapsedTime)
{
	
}

void Map::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[i][j].draw(window);
		}
	}
}