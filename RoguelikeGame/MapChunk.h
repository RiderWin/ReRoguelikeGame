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
		static const int width;
		static const int height;
		MapChunk* chunk; // ��������� �� ���� ����
		std::vector<std::vector<GraphicObject*>> road;
		sf::Vector2i startPos; 

		Road(MapChunk* _chunk, const sf::Vector2i& _startPos);
		void generate();
		void update(float elapsedTime);
		void draw();
	};


	GraphicObject debugFrame;
public:
	static const int width;
	static const int height;
	bool isGenerated;
	Road road;
	sf::Vector2i position;
	std::vector<std::vector<GraphicObject*>> tiles;
	std::vector<MapChunk> nextChunks; // ������ ��������� ������

	MapChunk(const sf::Vector2i& _position, const sf::Vector2i& _roadStart);

	void generate();
	void update(float elapsedTime);
	void draw();
};

