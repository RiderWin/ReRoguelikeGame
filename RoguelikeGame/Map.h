//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <vector>
#include "GameObject.h"
#include "MapChunk.h"


// ����� �����
// ����� - ����� ������, �� ������� �������� ������� �����
class Map
{
private:
	int width;
	int height;
	std::vector<sf::Vector2i> positions; // ������� ������
	std::vector<MapChunk> map; // �����
		//std::map<sf::Vector2i, MapChunk&&> map;
	sf::Vector2i curChunk; // ����, � ������� ��������� ������� �����

public:
	Map();

	void generate();
	void clear();
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);
	void debug();
	void setCurrentChunk(sf::Vector2i _curChunk);
};

