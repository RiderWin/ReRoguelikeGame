#pragma once
#include "GameObject.h"
#include "GraphicObject.h"

class Tile
{
public:
	static int size;
};

class MapChunk
{
public:
	static int width;
	static int height;

	bool isGenerated;
	GraphicObject debugFrame;
	std::vector<std::vector<GraphicObject*>> tiles;
	sf::Vector2i position;
	// Дорога
	sf::Vector2i roadStart;

	MapChunk* nextChunk;

	MapChunk(sf::Vector2i startTile, sf::Vector2i chunkPosition);

	void generate();
	void clear();
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);

};

