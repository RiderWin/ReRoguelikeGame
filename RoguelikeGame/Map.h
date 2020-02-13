//-----ReSpace-Engine-----
//	
//	«десь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <vector>
#include "GameObject.h"
#include "MapChunk.h"


//  ласс карты
//  арта - набор чанков, из которых строитс€ игрова€ карта
class Map
{
private:
	int width;
	int height;
	std::vector<sf::Vector2i> positions; // ѕозиции чанков
	std::vector<MapChunk> map; // чанки
		//std::map<sf::Vector2i, MapChunk&&> map;
	sf::Vector2i curChunk; // чанк, в котором находитс€ главный герой

public:
	Map();

	void generate();
	void clear();
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);
	void debug();
	void setCurrentChunk(sf::Vector2i _curChunk);
};

