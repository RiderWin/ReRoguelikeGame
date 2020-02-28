//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include "ChunkLayer.h"

class SceneChunk
{
private:
	GraphicObject debugFrame;
public:
	static const int width;
	static const int height;
	bool isGenerated;
	sf::Vector2i position;
	//std::vector<Object*> objects; // В будующе игровые объекты
	std::vector<SceneChunk> nextChunks; // Массив следующих чанков

	SceneChunk(const sf::Vector2i& _position);
	virtual void generate() = 0;
	void update(float elapsedTime);
	void draw();
};

