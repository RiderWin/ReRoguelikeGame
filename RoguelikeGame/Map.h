//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <map>
#include "GameObject.h"
#include "MapChunk.h"


// ����� �����
// ����� - ����� ������, �� ������� �������� ������� �����
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

