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
	sf::Vector2i tile = startPos; // Текущий тайл дороги

	// Рисуем стартовый тайл дороги
	std::cout << "generate() =  " << this << std::endl;
	road[tile.y][tile.x] = new GraphicObject(GameData::texRoad);
	road[tile.y][tile.x]->setPosition(chunk->position, tile * 2);

	std::vector<sf::Vector2i> oldTiles; // Пройденные тайлы
	while (true)
	{
		std::vector<sf::Vector2i> freeDirs; // Массив, хранящий направления, в которые можно пойти
		// Проверяем есть ли вокруг свободные тайлы
		if (tile.x > 0 && tile.x < width - 1) // если это не самый левый или правый край
		{
			// Вниз
			if (tile.y < height - 2 && road[tile.y + 2][tile.x] == 0 && // по центру
				road[tile.y + 1][tile.x - 1] == 0 && road[tile.y + 1][tile.x + 1] == 0 && // по бокам
				road[tile.y + 2][tile.x - 1] == 0 && road[tile.y + 2][tile.x + 1] == 0) // углы
				freeDirs.push_back(sf::Vector2i(0, 1));
			// Вверх
			if ((tile.y > 1 && road[tile.y - 2][tile.x] == 0 && // по центру
				road[tile.y - 1][tile.x - 1] == 0 && road[tile.y - 1][tile.x + 1] == 0 && // по бокам
				road[tile.y - 2][tile.x - 1] == 0 && road[tile.y - 2][tile.x + 1] == 0) || // углы
				(tile.y == 1 && startPos.y != 0)) // выход с чанка
				freeDirs.push_back(sf::Vector2i(0, -1));
		}
		if (tile.y > 0 && tile.y < height - 1) // если это не самый верхний или нижний край
		{
			// Влево
			if ((tile.x > 1 && road[tile.y][tile.x - 2] == 0 && // по центру
				road[tile.y - 1][tile.x - 1] == 0 && road[tile.y + 1][tile.x - 1] == 0 && // по бокам
				road[tile.y - 1][tile.x - 2] == 0 && road[tile.y + 1][tile.x - 2] == 0) || // углы
				(tile.x == 1 && startPos.x != 0)) // выход с чанка
				freeDirs.push_back(sf::Vector2i(-1, 0));
			// Вправо
			if ((tile.x < width - 2 && road[tile.y][tile.x + 2] == 0 && // по центру
				road[tile.y - 1][tile.x + 1] == 0 && road[tile.y + 1][tile.x + 1] == 0 && // по бокам
				road[tile.y - 1][tile.x + 2] == 0 && road[tile.y + 1][tile.x + 2] == 0) || // углы
				(tile.x == width - 2 && startPos.x != width - 1)) // выход с чанка
				freeDirs.push_back(sf::Vector2i(1, 0));
		}


		if (freeDirs.size() != 0) // Если вокруг есть свободные тайлы, то идём к любому из них
		{
			oldTiles.push_back(tile);
			sf::Vector2i dir = freeDirs[rand() % freeDirs.size()]; // Выбираем любое направление
			tile += dir;

			// Рисуем тайл дороги
			road[tile.y][tile.x] = new GraphicObject(GameData::texRoad);
			road[tile.y][tile.x]->setPosition(chunk->position, tile * 2);


			// Если эта клетка оказалась у края, то заканчиваем генерацию
			if (tile.y == 0) // Вверх
			{
				chunk->nextChunks.push_back(MapChunk(chunk->position + dir, sf::Vector2i(tile.x, height - 1)));
				chunk->isGenerated = true;
				break;
			}
			else if (tile.x == 0) // Влево
			{
				chunk->nextChunks.push_back(MapChunk(chunk->position + dir, sf::Vector2i(width - 1, tile.y)));
				chunk->isGenerated = true;
				break;
			}
			else if (tile.x == width - 1) // Вправо
			{
				chunk->nextChunks.push_back(MapChunk(chunk->position + dir, sf::Vector2i(0, tile.y)));
				chunk->isGenerated = true;
				break;
			}
		}
		else if (oldTiles.size() != 0) // Если свободных клеток нет, то берем любую предыдущую клекту и пробуем пойти из неё
		{
			int index = rand() % oldTiles.size();
			tile = oldTiles[index];
			oldTiles.erase(oldTiles.begin() + index);
			continue;
		}
		else // Если клетки кончились то выходим из цикла генерации
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