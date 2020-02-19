//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <map>
#include "MapChunk.h"


// Класс карты
// Карта - набор чанков, из которых строится игровая карта
class Map
{
private:
	Map();
	static std::map<sf::Vector2i, MapChunk*> map; // Позиция чанка, указатель на сам чанк
	static sf::Vector2i curChunkPos; // Чанк, относительно которого генерируется и рисуется карта
	static MapChunk* startChunk; // Стартовый чанк

public:
	static void create();
	static void update(float elapsedTime);
	static void draw();
	static void debug();
	static void setCurrentChunk(sf::Vector2i _curChunkPos);
};

