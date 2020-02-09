//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <map>
#include "GameObject.h"
#include "MapChunk.h"


// Класс карты
// Карта - набор чанков, из которых строится игровая карта
class Map
{
private:
	int width;
	int height;
	std::map<sf::Vector2i, MapChunk> map;

public:
	Map();

	void generate();
	void clear();
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);
	void debug();
};

