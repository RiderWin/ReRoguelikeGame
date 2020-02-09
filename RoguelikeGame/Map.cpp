#include "Map.h"
#include <stack>

Map::Map()
{
	width = 1;
	height = 1;
}

void Map::generate()
{
	sf::Vector2i chunk(0, 0);
	sf::Vector2i startPos(5, 5);
	map.emplace(std::pair<sf::Vector2i, MapChunk>(chunk, MapChunk(chunk, startPos)));
	map.at(chunk).generate();

	for (int i = 0; i < 35; i++)
	{	
		MapChunk* nextChunk = map.at(chunk).nextChunk;
		chunk = nextChunk->position;
		map.emplace(std::pair<sf::Vector2i, MapChunk>(chunk, *nextChunk));
		map.at(chunk).generate();

		//std::cout << "Start position :  x = " << startPos.x << " y = " << startPos.y << std::endl;
		//std::cout << "Chunk position :  x = " << chunk.x << " y = " << chunk.y << std::endl;
	}
	std::cout << map.size() << std::endl;

}

void Map::clear()
{
	for (auto& item : map)
	{
		item.second.clear();
	}
}

void Map::update(float elapsedTime)
{

}

void Map::draw(sf::RenderWindow* window)
{
	for (auto& item : map)
	{
		item.second.draw(window);
	}
}