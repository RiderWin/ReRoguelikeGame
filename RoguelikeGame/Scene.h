//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <map>
#include "SceneChunk.h"

class Scene
{
protected:
	std::map<sf::Vector2i, SceneChunk*> chunks; // <Позиция чанка, указатель на сам чанк>
	sf::Vector2i curChunkPos; // Чанк, относительно которого генерируется и рисуется карта
	SceneChunk* startChunk; // Стартовый чанк

public:
	Scene();
	void update(float elapsedTime);
	void draw();
	void setCurrentChunk(sf::Vector2i _curChunkPos);
};

