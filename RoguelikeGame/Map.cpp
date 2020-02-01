#include "Map.h"

Map::Map()
{
	width = 16;
	height = 9;
	cell = sf::Vector2i(8, 8);
	map = std::vector<std::vector<GraphicObject*>>(height, std::vector<GraphicObject*>(width));
}

bool Map::generate()
{
	oldCells.push(cell);
	std::vector<sf::Vector2i> freeCells;

	// ЭТО НА БУДУЩЕЕ !!!
	// Чанк существует условно и не содрежит в себе тайлы
	// Все тайлы хранятся здесь
	// Чанки это как просто ориентировочная сетка
	// А карта это как тайлы расставленные в этой сетке

	if (cell.y == 0)
	{
		//cell.y = height - 1;
		return false;
	}
	if (cell.x == 0)
	{
		//cell.x = width - 1;
		return false;
	}
	if (cell.x == width - 1)
	{
		//cell.x = 0;
		return false;
	}

	while (true)
	{
		// Вниз
		if (cell.y < height - 2 && map[cell.y + 2][cell.x] == nullptr)
			freeCells.push_back(sf::Vector2i(cell.x, cell.y + 2));
		// Вверх
		if (cell.y >= 2 && map[cell.y - 2][cell.x] == nullptr)
			freeCells.push_back(sf::Vector2i(cell.x, cell.y - 2));
		// Вправо
		if (cell.x < width - 2 && map[cell.y][cell.x + 2] == nullptr)
			freeCells.push_back(sf::Vector2i(cell.x + 2, cell.y));
		// Влево
		if (cell.x >= 2 && map[cell.y][cell.x - 2] == nullptr)
			freeCells.push_back(sf::Vector2i(cell.x - 2, cell.y));

		if (freeCells.size() == 0)
		{
			if (oldCells.size() == 0) return false;
			else
			{
				cell = oldCells.top();
				oldCells.pop();
				continue;
			}
		}
		else break;
	}

	sf::Vector2i newCell = freeCells[rand() % freeCells.size()];;
	sf::Vector2i newCell2 = cell + (newCell - cell) / 2;

	cell = newCell;
	map[cell.y][cell.x] = new GraphicObject(GameData::texDiamond);
	map[cell.y][cell.x]->setScale(2, 2);
	map[cell.y][cell.x]->setPosition(32 * cell.x, 32 * cell.y);

	map[newCell2.y][newCell2.x] = new GraphicObject(GameData::texDiamond);
	map[newCell2.y][newCell2.x]->setScale(2, 2);
	map[newCell2.y][newCell2.x]->setPosition(32 * newCell2.x, 32 * newCell2.y);
	return true;

	/*for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == nullptr)
			{
				map[i][j] = new GraphicObject(GameData::texDirt);
				map[i][j]->setScale(3.125, 3.125);
				map[i][j]->setPosition(50 * j, 50 * i);
			}
		}
	}*/
}

void Map::clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != nullptr)
			{
				delete map[i][j];
				map[i][j] = nullptr;
			}
		}
	}
}

void Map::fun(sf::FloatRect point)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j]->getGlobalBounds().intersects(point))
			{
				map[i][j]->setColor(sf::Color::Red);
			}
			else
			{
				map[i][j]->setColor(sf::Color::White);
			}
		}
	}
}

void Map::update(float elapsedTime)
{

}

void Map::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != nullptr)
				map[i][j]->draw(window);
		}
	}
}