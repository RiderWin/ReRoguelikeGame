#include "Scene.h"

Scene::Scene()
{
	sf::Vector2i startChunkPos = sf::Vector2i(0, 0);
	startChunk = new SceneChunk(startChunkPos, sf::Vector2i(1, 1));

	chunks.emplace(startChunkPos, startChunk);
	chunks.at(startChunkPos)->generate();

	//curChunkPos = sf::Vector2i(1, 1); // „тобы сработало условие...
	setCurrentChunk(startChunkPos);
}


void Scene::update(float elapsedTime)
{
	// ќбновл€ем текущий чанк, и все чанки вокруг, если они существуют
	sf::Vector2i chunkPos;
	for (int i = curChunkPos.y - 1; i <= curChunkPos.y + 1; i++)
	{
		for (int j = curChunkPos.x - 1; j <= curChunkPos.x + 1; j++)
		{
			chunkPos.x = j;
			chunkPos.y = i;
			if (chunks.count(chunkPos) > 0)
			{
				chunks.at(chunkPos)->update(elapsedTime);
			}
		}
	}
}

void Scene::draw()
{
	// –исуем текущий чанк, и все чанки вокруг, если они существуют
	sf::Vector2i chunkPos;
	for (int i = curChunkPos.y - 1; i <= curChunkPos.y + 1; i++)
	{
		for (int j = curChunkPos.x - 1; j <= curChunkPos.x + 1; j++)
		{
			chunkPos.x = j;
			chunkPos.y = i;
			if (chunks.count(chunkPos) > 0)
			{
				chunks.at(chunkPos)->draw();
			}
		}
	}
}

void Scene::setCurrentChunk(sf::Vector2i _curChunkPos)
{
	if (curChunkPos != _curChunkPos)
	{
		curChunkPos = _curChunkPos;

		// ѕеребираем все следующие чанки текущего чанка
		// Ќужно перебирать все чанки вокруг до тех пор пока они все не сгенерируютс€
		for (int i = 0; i < chunks.at(curChunkPos)->nextChunks.size(); i++)
		{
			SceneChunk& nextChunk = chunks.at(curChunkPos)->nextChunks[i];

			// ≈сли мы впервые натыкаемс€ на этот чанк, то добавл€ем его в карту и генерируем его
			map.emplace(nextChunk.position, &nextChunk);
			if (!nextChunk.isGenerated)
			{
				nextChunk.generate();
			}
		}
	}
}