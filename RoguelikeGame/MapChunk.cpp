#include "MapChunk.h"


// Road
MapChunk::Road::Road(const sf::Vector2i& _startPos, MapChunk* _chunk) :
	width(GameData::chunkWidth / 2),
	height(GameData::chunkHeight / 2)
{
	chunk = _chunk;
	startPos = _startPos;
	std::cout << "Road() =  " << this << std::endl;
	road = std::vector<std::vector<GraphicObject*>>(height, std::vector<GraphicObject*>(width));
}

void MapChunk::Road::generate()
{
	sf::Vector2i tile = startPos; // ������� ���� ������

	// ������ ��������� ���� ������
	std::cout << "generate() =  " << this << std::endl;
	road[tile.y][tile.x] = new GraphicObject(GameData::texRoad);
	road[tile.y][tile.x]->setPosition(chunk->position, tile * 2);

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
				freeDirs.push_back(sf::Vector2i(0, 1));
			// �����
			if ((tile.y > 1 && road[tile.y - 2][tile.x] == 0 && // �� ������
				road[tile.y - 1][tile.x - 1] == 0 && road[tile.y - 1][tile.x + 1] == 0 && // �� �����
				road[tile.y - 2][tile.x - 1] == 0 && road[tile.y - 2][tile.x + 1] == 0) || // ����
				(tile.y == 1 && startPos.y != 0)) // ����� � �����
				freeDirs.push_back(sf::Vector2i(0, -1));
		}
		if (tile.y > 0 && tile.y < height - 1) // ���� ��� �� ����� ������� ��� ������ ����
		{
			// �����
			if ((tile.x > 1 && road[tile.y][tile.x - 2] == 0 && // �� ������
				road[tile.y - 1][tile.x - 1] == 0 && road[tile.y + 1][tile.x - 1] == 0 && // �� �����
				road[tile.y - 1][tile.x - 2] == 0 && road[tile.y + 1][tile.x - 2] == 0) || // ����
				(tile.x == 1 && startPos.x != 0)) // ����� � �����
				freeDirs.push_back(sf::Vector2i(-1, 0));
			// ������
			if ((tile.x < width - 2 && road[tile.y][tile.x + 2] == 0 && // �� ������
				road[tile.y - 1][tile.x + 1] == 0 && road[tile.y + 1][tile.x + 1] == 0 && // �� �����
				road[tile.y - 1][tile.x + 2] == 0 && road[tile.y + 1][tile.x + 2] == 0) || // ����
				(tile.x == width - 2 && startPos.x != width - 1)) // ����� � �����
				freeDirs.push_back(sf::Vector2i(1, 0));
		}


		if (freeDirs.size() != 0) // ���� ������ ���� ��������� �����, �� ��� � ������ �� ���
		{
			oldTiles.push_back(tile);
			sf::Vector2i dir = freeDirs[rand() % freeDirs.size()]; // �������� ����� �����������
			tile += dir;

			// ������ ���� ������
			road[tile.y][tile.x] = new GraphicObject(GameData::texRoad);
			road[tile.y][tile.x]->setPosition(chunk->position, tile * 2);


			// ���� ��� ������ ��������� � ����, �� ����������� ���������
			if (tile.y == 0) // �����
			{
				chunk->nextChunks.push_back(MapChunk(chunk->position + dir, sf::Vector2i(tile.x, height - 1)));
				chunk->isGenerated = true;
				break;
			}
			else if (tile.x == 0) // �����
			{
				chunk->nextChunks.push_back(MapChunk(chunk->position + dir, sf::Vector2i(width - 1, tile.y)));
				chunk->isGenerated = true;
				break;
			}
			else if (tile.x == width - 1) // ������
			{
				chunk->nextChunks.push_back(MapChunk(chunk->position + dir, sf::Vector2i(0, tile.y)));
				chunk->isGenerated = true;
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

void MapChunk::Road::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (road[i][j] != nullptr)
				road[i][j]->draw(window);
		}
	}
}


// MapChunk
MapChunk::MapChunk(const sf::Vector2i& _position, const sf::Vector2i& _roadStart) :
	width(GameData::chunkWidth),
	height(GameData::chunkHeight),
	debugFrame(GameData::texChunkFrame),
	road(_roadStart, this)
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
		//nextChunk = new MapChunk(position += road.nextDir, road.nextPos);
		//isGenerated = true;
		isGenerated;
		for (int i = 0; i < nextChunks.size(); i++)
		{
			std::cout << nextChunks[i].position.x;
		}
	}
}

void MapChunk::clear()
{
	//for (int i = 0; i < height; i++)
	//{
	//	for (int j = 0; j < width; j++)
	//	{
	//		if (tiles[i][j] != nullptr)
	//		{
	//			delete tiles[i][j];
	//			tiles[i][j] = nullptr;
	//		}
	//	}
	//}
}

void MapChunk::update(float elapsedTime)
{

}

void MapChunk::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tiles[i][j] != nullptr)
				tiles[i][j]->draw(window);
		}
	}
	road.draw(window);
	if (GameConfig::isDebug)
		debugFrame.draw(window);
}