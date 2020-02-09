//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <vector>
#include "GraphicObject.h"


// ����� �����
// ���� - ����� �����, ��������� �� ������(GraphicObject)
// �� ������ �������� ��� �����
class MapChunk
{
public:
	const int width;
	const int height;

	bool isGenerated;
	GraphicObject debugFrame;
	std::vector<std::vector<GraphicObject*>> tiles;
	sf::Vector2i position;
	MapChunk* nextChunk;
	// ������
	sf::Vector2i roadStart;


	MapChunk(sf::Vector2i startTile, sf::Vector2i chunkPosition);

	void generate();
	void clear();
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);

};

