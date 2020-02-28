#include "Map.h"
#include "StandartInclude.h"
#include <stack>


std::map<sf::Vector2i, MapChunk*> Map::map;
sf::Vector2i Map::curChunkPos;
MapChunk* Map::startChunk;

void Map::create()
{
	curChunkPos = sf::Vector2i(0, 0);
	startChunk = new MapChunk(curChunkPos, sf::Vector2i(1, 1));

	map.emplace(curChunkPos, startChunk);
	map.at(curChunkPos)->generate();

	curChunkPos = sf::Vector2i(1, 1); // Чтобы сработало условие...
	setCurrentChunk(curChunkPos);
}

void Map::update(float elapsedTime)
{

}

void Map::draw()
{
	// Рисуем текущий чанк, и все чанки вокруг, если они существуют
	sf::Vector2i chunkPos;
	for (int i = curChunkPos.y - 1; i <= curChunkPos.y + 1; i++)
	{
		for (int j = curChunkPos.x - 1; j <= curChunkPos.x + 1; j++)
		{
			chunkPos.x = j;
			chunkPos.y = i;
			if (map.count(chunkPos) > 0)
			{
				map.at(chunkPos)->draw();
			}
		}
	}
}

void Map::setCurrentChunk(sf::Vector2i _curChunkPos)
{
	if (curChunkPos != _curChunkPos)
	{
		curChunkPos = _curChunkPos;

		// Перебираем все следующие чанки текущего чанка
		for (int i = 0; i < map.at(curChunkPos)->nextChunks.size(); i++)
		{
			MapChunk& nextChunk = map.at(curChunkPos)->nextChunks[i];

			// Если мы впервые натыкаемся на этот чанк, то добавляем его в карту и генерируем его
			map.emplace(nextChunk.position, &nextChunk);
			if (!nextChunk.isGenerated)
			{
				nextChunk.generate();
			}
		}
	}
}
