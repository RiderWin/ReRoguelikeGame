#include "MapChunk.h"

MapChunk::MapChunk(sf::Vector2i _position, sf::Vector2i _roadStart) : 
	width(GameData::chunkWidth), 
	height(GameData::chunkHeight), 
	debugFrame(GameData::texChunkFrame)
{

	position = _position;
	roadStart = _roadStart;
	isGenerated = false;
	tiles = std::vector<std::vector<GraphicObject*>>(height, std::vector<GraphicObject*>(width));
	debugFrame.setPosition(position, sf::Vector2i(0, 0));
}

void MapChunk::generate()
{
	/*for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			tiles[i][j] = new GraphicObject(GameData::texDiamond);
			tiles[i][j]->setPosition(j * Tile::size, i * Tile::size);
			tiles[i][j]->move(position.x * width * Tile::size, position.y * height * Tile::size);
		}
	}*/

	if (!isGenerated)
	{
		// 1�� ���� - ���������� ������ � �������� ������� �����
		int roadHeight = height / 2;
		int roadWidth = width / 2;
		std::vector<std::vector<int>>road = std::vector<std::vector<int>>(roadHeight, std::vector<int>(roadWidth));
		sf::Vector2i cell = roadStart; // ������� ������ ������
		road[cell.y][cell.x] = 1;

		// ������ ��������� ����� ������
		sf::Vector2i tile = cell * 2;
		for (int i = tile.y; i <= tile.y + 1; i++)
		{
			for (int j = tile.x; j <= tile.x + 1; j++)
			{
				tiles[i][j] = new GraphicObject(GameData::texDiamond);
				tiles[i][j]->setPosition(position, sf::Vector2i(j, i));
			}
		}

		std::vector<sf::Vector2i> oldCells; // ���������� ������
		while (true)
		{
			std::vector<sf::Vector2i> freeDirs; // ������, �������� �����������, � ������� ����� �����
			// ��������� ���� �� ������ ��������� ������
			if (cell.x > 0 && cell.x < roadWidth - 1) // ���� ��� �� ����� ����� ��� ������ ����
			{
				// ����
				if (cell.y < roadHeight - 2 && road[cell.y + 2][cell.x] == 0 && // �� ������
					road[cell.y + 1][cell.x - 1] == 0 && road[cell.y + 1][cell.x + 1] == 0 && // �� �����
					road[cell.y + 2][cell.x - 1] == 0 && road[cell.y + 2][cell.x + 1] == 0) // ����
					freeDirs.push_back(sf::Vector2i(0, 1));
				// �����
				if ((cell.y > 1 && road[cell.y - 2][cell.x] == 0 && // �� ������
					road[cell.y - 1][cell.x - 1] == 0 && road[cell.y - 1][cell.x + 1] == 0 && // �� �����
					road[cell.y - 2][cell.x - 1] == 0 && road[cell.y - 2][cell.x + 1] == 0) || // ����
					(cell.y == 1 && roadStart.y != 0)) // ����� � �����
					freeDirs.push_back(sf::Vector2i(0, -1));
			}
			if (cell.y > 0 && cell.y < roadHeight - 1) // ���� ��� �� ����� ������� ��� ������ ����
			{
				// �����
				if ((cell.x > 1 && road[cell.y][cell.x - 2] == 0 && // �� ������
					road[cell.y - 1][cell.x - 1] == 0 && road[cell.y + 1][cell.x - 1] == 0 && // �� �����
					road[cell.y - 1][cell.x - 2] == 0 && road[cell.y + 1][cell.x - 2] == 0) || // ����
					(cell.x == 1 && roadStart.x != 0)) // ����� � �����
					freeDirs.push_back(sf::Vector2i(-1, 0));
				// ������
				if ((cell.x < roadWidth - 2 && road[cell.y][cell.x + 2] == 0 && // �� ������
					road[cell.y - 1][cell.x + 1] == 0 && road[cell.y + 1][cell.x + 1] == 0 && // �� �����
					road[cell.y - 1][cell.x + 2] == 0 && road[cell.y + 1][cell.x + 2] == 0) || // ����
					(cell.x == roadWidth - 2 && roadStart.x != roadWidth - 1)) // ����� � �����
					freeDirs.push_back(sf::Vector2i(1, 0));
			}


			if (freeDirs.size() != 0) // ���� ������ ��������� ������ ����, �� ��� � ����� �� ���
			{
				oldCells.push_back(cell);
				sf::Vector2i dir = freeDirs[rand() % freeDirs.size()]; // �������� ����� �����������
				cell += dir;
				road[cell.y][cell.x] = 1;

				tile = cell * 2;
				// ������ ����� ������
				for (int i = tile.y; i <= tile.y + 1; i++)
				{
					for (int j = tile.x; j <= tile.x + 1; j++)
					{
						tiles[i][j] = new GraphicObject(GameData::texDiamond);
						tiles[i][j]->setPosition(position, sf::Vector2i(j, i));
					}
				}

				// ���� ��� ������ ��������� � ����, �� ����������� ���������
				if (cell.y == 0) // �����
				{
					nextChunk = new MapChunk(sf::Vector2i(position.x, position.y - 1), sf::Vector2i(cell.x, roadHeight - 1));
					isGenerated = true;
					break;
				}
				else if (cell.x == 0) // �����
				{
					nextChunk = new MapChunk(sf::Vector2i(position.x - 1, position.y), sf::Vector2i(roadWidth - 1, cell.y));
					isGenerated = true;
					break;
				}
				else if (cell.x == roadWidth - 1) // ������
				{
					nextChunk = new MapChunk(sf::Vector2i(position.x + 1, position.y), sf::Vector2i(0, cell.y));
					isGenerated = true;
					break;
				}
			}
			else if (oldCells.size() != 0) // ���� ��������� ������ ���, �� ����� ����� ���������� ������ � ������� ����� �� ��
			{
				int index = rand() % oldCells.size();
				cell = oldCells[index];
				oldCells.erase(oldCells.begin() + index);
				continue;
			}
			else // ���� ������ ��������� �� ������� �� ����� ���������
			{
				isGenerated = true;
				break;
			}
		}

		if (GameConfig::isDebug)
		{
			for (int i = 0; i < roadHeight; i++)
			{
				for (int j = 0; j < roadWidth; j++)
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
}

void MapChunk::clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tiles[i][j] != nullptr)
			{
				delete tiles[i][j];
				tiles[i][j] = nullptr;
			}
		}
	}
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
	if (GameConfig::isDebug)
		debugFrame.draw(window);
}