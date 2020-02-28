#include "Scene.h"

Scene::Scene()
{
	sf::Vector2i startChunkPos = sf::Vector2i(0, 0);
	startChunk = new SceneChunk(startChunkPos, sf::Vector2i(1, 1));

	chunks.emplace(startChunkPos, startChunk);
	chunks.at(startChunkPos)->generate();

	//curChunkPos = sf::Vector2i(1, 1); // ����� ��������� �������...
	setCurrentChunk(startChunkPos);
}


void Scene::update(float elapsedTime)
{
	// ��������� ������� ����, � ��� ����� ������, ���� ��� ����������
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
	// ������ ������� ����, � ��� ����� ������, ���� ��� ����������
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

		// ���������� ��� ��������� ����� �������� �����
		// ����� ���������� ��� ����� ������ �� ��� ��� ���� ��� ��� �� �������������
		for (int i = 0; i < chunks.at(curChunkPos)->nextChunks.size(); i++)
		{
			SceneChunk& nextChunk = chunks.at(curChunkPos)->nextChunks[i];

			// ���� �� ������� ���������� �� ���� ����, �� ��������� ��� � ����� � ���������� ���
			map.emplace(nextChunk.position, &nextChunk);
			if (!nextChunk.isGenerated)
			{
				nextChunk.generate();
			}
		}
	}
}