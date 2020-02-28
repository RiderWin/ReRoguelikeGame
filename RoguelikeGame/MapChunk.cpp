#include "MapChunk.h"
#include "StandartInclude.h"
#include "Map.h"

// Road
const int MapChunk::Road::width = GameData::roadWidth;
const int MapChunk::Road::height = GameData::roadHeight;

MapChunk::Road::Road(MapChunk* _chunk, const sf::Vector2i& _startPos)
{
	chunk = _chunk;
	startPos = _startPos;
	road = std::vector<std::vector<GraphicObject*>>(height, std::vector<GraphicObject*>(width));
}

void MapChunk::Road::generate()
{
	sf::Vector2i tile = startPos; // ������� ���� ������

	// ������ ��������� ���� ������
	road[tile.y][tile.x] = new GraphicObject(GameData::texDirt);
	road[tile.y][tile.x]->setPosition(chunk->position, tile * 3);

	std::vector<sf::Vector2i> oldTiles; // ���������� �����
	while (true)
	{
		std::vector<sf::Vector2i> freeDirs; // ������, �������� �����������, � ������� ����� �����
		// ��������� ���� �� ������ ��������� �����
		if (tile.x > 0 && tile.x < width - 1) // ���� ��� �� ����� ����� ��� ������ ����
		{
			// ����
			if (tile.y < height - 2 && road[tile.y + 2][tile.x] == 0 && // �� ������
				road[tile.y + 1][tile.x - 1] == 0 && road[tile.y + 1][tile.x + 1] == 0 && // �� �����
				road[tile.y + 2][tile.x - 1] == 0 && road[tile.y + 2][tile.x + 1] == 0) // ����
				freeDirs.emplace_back(0, 1);
			// �����
			if ((tile.y > 1 && road[tile.y - 2][tile.x] == 0 && // �� ������
				road[tile.y - 1][tile.x - 1] == 0 && road[tile.y - 1][tile.x + 1] == 0 && // �� �����
				road[tile.y - 2][tile.x - 1] == 0 && road[tile.y - 2][tile.x + 1] == 0) || // ����
				(tile.y == 1 && startPos.y != 0)) // ����� � �����
				freeDirs.emplace_back(0, -1);
		}
		if (tile.y > 0 && tile.y < height - 1) // ���� ��� �� ����� ������� ��� ������ ����
		{
			// �����
			if ((tile.x > 1 && road[tile.y][tile.x - 2] == 0 && // �� ������
				road[tile.y - 1][tile.x - 1] == 0 && road[tile.y + 1][tile.x - 1] == 0 && // �� �����
				road[tile.y - 1][tile.x - 2] == 0 && road[tile.y + 1][tile.x - 2] == 0) || // ����
				(tile.x == 1 && startPos.x != 0)) // ����� � �����
				freeDirs.emplace_back(-1, 0);
			// ������
			if ((tile.x < width - 2 && road[tile.y][tile.x + 2] == 0 && // �� ������
				road[tile.y - 1][tile.x + 1] == 0 && road[tile.y + 1][tile.x + 1] == 0 && // �� �����
				road[tile.y - 1][tile.x + 2] == 0 && road[tile.y + 1][tile.x + 2] == 0) || // ����
				(tile.x == width - 2 && startPos.x != width - 1)) // ����� � �����
				freeDirs.emplace_back(1, 0);
		}


		if (freeDirs.size() != 0) // ���� ������ ���� ��������� �����, �� ��� � ������ �� ���
		{
			oldTiles.emplace_back(tile);
			sf::Vector2i dir = freeDirs[rand() % freeDirs.size()]; // �������� ����� �����������
			tile += dir;

			// ������ ���� ������
			road[tile.y][tile.x] = new GraphicObject(GameData::texDirt);
			road[tile.y][tile.x]->setPosition(chunk->position, tile * 3);


			// ���� ��� ������ ��������� � ����, �� ����������� ���������
			if (tile.y == 0) // �����
			{
				chunk->nextChunks.emplace_back(chunk->position + dir, sf::Vector2i(tile.x, height - 1));
				break;
			}
			else if (tile.x == 0) // �����
			{
				chunk->nextChunks.emplace_back(chunk->position + dir, sf::Vector2i(width - 1, tile.y));
				break;
			}
			else if (tile.x == width - 1) // ������
			{
				chunk->nextChunks.emplace_back(chunk->position + dir, sf::Vector2i(0, tile.y));
				break;
			}
		}
		else if (oldTiles.size() != 0) // ���� ��������� ������ ���, �� ����� ����� ���������� ������ � ������� ����� �� ��
		{
			int index = rand() % oldTiles.size();
			tile = oldTiles[index];
			oldTiles.erase(oldTiles.begin() + index);
			continue;
		}
		else // ���� ������ ��������� �� ������� �� ����� ���������
		{
			break;
		}
	}

	if (GameConfig::isDebug)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (road[i][j])
					std::cout << char(219);
				else
					std::cout << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

}

void MapChunk::Road::draw()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (road[i][j] != nullptr)
				road[i][j]->draw();
		}
	}
}


// MapChunk
const int MapChunk::width = GameData::chunkWidth;
const int MapChunk::height = GameData::chunkHeight;

MapChunk::MapChunk(const sf::Vector2i& _position, const sf::Vector2i& _roadStart) :
	debugFrame(GameData::texChunkFrame),
	road(this, _roadStart)
{
	position = _position;
	tiles = std::vector<std::vector<GraphicObject*>>(height, std::vector<GraphicObject*>(width));
	debugFrame.setPosition(position, sf::Vector2i(0, 0));
	isGenerated = false;
}

void MapChunk::generate()
{
	if (!isGenerated)
	{
		road.generate();

		// ��������� ����� ������ ����� ����� ���������
		/*for (int i = position.y - 1; i <= position.y + 1; i++)
		{
			for (int j = position.x - 1; j <= position.x + 1; j++)
			{
				if(Map::)
			}
		}*/



		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				tiles[i][j] = new GraphicObject(GameData::texGrass);
				tiles[i][j]->setPosition(position, sf::Vector2i(j, i));
			}
		}
		isGenerated = true;
	}
}

void MapChunk::update(float elapsedTime)
{

}

void MapChunk::draw()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tiles[i][j] != nullptr)
				tiles[i][j]->draw();
		}
	}
	road.draw();
	if (GameConfig::isDebug)
		debugFrame.draw();
}