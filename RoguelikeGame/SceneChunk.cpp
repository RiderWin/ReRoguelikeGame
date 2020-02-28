#include "SceneChunk.h"
#include "StandartInclude.h"

const int SceneChunk::width = GameData::chunkWidth;
const int SceneChunk::height = GameData::chunkHeight;

SceneChunk::SceneChunk(const sf::Vector2i& _position):
	debugFrame(GameData::texChunkFrame)
{

}

void SceneChunk::update(float elapsedTime)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tiles[i][j] != nullptr)
				tiles[i][j]->update(elapsedTime);
		}
	}
}

void SceneChunk::draw()
{

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tiles[i][j] != nullptr)
				tiles[i][j]->draw();
		}
	}
	if (GameConfig::isDebug)
		debugFrame.draw();
}