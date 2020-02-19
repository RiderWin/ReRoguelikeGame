//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <map>
#include "MapChunk.h"


// ����� �����
// ����� - ����� ������, �� ������� �������� ������� �����
class Map
{
private:
	Map();
	static std::map<sf::Vector2i, MapChunk*> map; // ������� �����, ��������� �� ��� ����
	static sf::Vector2i curChunkPos; // ����, ������������ �������� ������������ � �������� �����
	static MapChunk* startChunk; // ��������� ����

public:
	static void create();
	static void update(float elapsedTime);
	static void draw();
	static void debug();
	static void setCurrentChunk(sf::Vector2i _curChunkPos);
};

