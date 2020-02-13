#include "Map.h"
#include <stack>

Map::Map()
{
	width = 1;
	height = 1;

	//sf::Vector2i chunk(0, 0);
	//index = 0;
	//map.emplace_back(MapChunk(chunk, sf::Vector2i(5, 5)));
	//positions.emplace_back(chunk);
	////map.emplace(chunk, new MapChunk(chunk, sf::Vector2i(5, 5)));
	////map.at(chunk).generate();
	//
	//// Нужно написать свой класс словаря(map) и двумерного вектора

	//Map::setCurrentChunk(sf::Vector2i(0, 0));
}

void Map::generate()
{

	/*for (int i = 0; i < 35; i++)
	{
		MapChunk* nextChunk = map.at(chunk).nextChunk;
		chunk = nextChunk->position;
		map.emplace(std::pair<sf::Vector2i, MapChunk>(chunk, *nextChunk));
		map.at(chunk).generate();
	}
	std::cout << map.size() << std::endl;*/

}

void Map::clear()
{
	/*for (auto& item : map)
	{
		item.second.clear();
	}*/
}

void Map::update(float elapsedTime)
{

}

void Map::draw(sf::RenderWindow* window)
{
	/*for (int i = curChunk.y - 1; i <= curChunk.y + 1; i++)
	{
		for (int j = curChunk.x - 1; j <= curChunk.x + 1; j++)
		{
			auto chunk = std::find(positions.begin(), positions.end(), sf::Vector2i(j,i));
			if (chunk != positions.end())
			{
				auto index = chunk - positions.begin();
				map[index].draw(window);
			}
		}
	}*/
}

void Map::setCurrentChunk(sf::Vector2i _curChunk)
{
	//curChunk = _curChunk;

	//// Перебираем все следующие чанки и добавляем их в карту
	//for (int i = 0; i < map.at(curChunk).nextChunks.size(); i++)
	//{
	//	MapChunk& nextChunk = map.at(curChunk).nextChunks[i];
	//	if (!nextChunk.isGenerated)
	//	{
	//		map.emplace(std::pair<sf::Vector2i, MapChunk>(nextChunk.position, nextChunk));
	//		nextChunk.generate();
	//		// Почему-то следующий чанк не генерируется, возможно он не добавляется в вектор в Road
	//	}
	//}

	//// Генерируем все чанки вокруг текущего
	//for (int i = curChunk.y - 1; i <= curChunk.y + 1; i++)
	//{
	//	for (int j = curChunk.x - 1; j <= curChunk.x + 1; j++)
	//	{
	//		sf::Vector2i chunk(j, i);
	//		if (map.count(chunk) > 0)
	//			map.at(chunk).generate();
	//	}
	//}
}