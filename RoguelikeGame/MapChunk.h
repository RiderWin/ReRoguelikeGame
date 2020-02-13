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
private:
	// ��������� ����� - ��������, �� ������� ����� ������������ �� ������
	class Road
	{
	public:
		const int height;
		const int width;
		MapChunk* chunk; // ��������� �� ���� ����
		std::vector<std::vector<GraphicObject*>> road;
		sf::Vector2i startPos; 

		Road(const sf::Vector2i& _startPos, MapChunk* _chunk);
		void generate();
		void update(float elapsedTime);
		void draw(sf::RenderWindow* window);
	};


	GraphicObject debugFrame;
public:
	const int width;
	const int height;
	bool isGenerated;
	Road road;
	sf::Vector2i position;
	std::vector<std::vector<GraphicObject*>> tiles;
	std::vector<MapChunk> nextChunks; // ������ ���������� �� ����������� �����

	MapChunk(const sf::Vector2i& _position, const sf::Vector2i& _roadStart);

	void generate();
	void clear();
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);
};

