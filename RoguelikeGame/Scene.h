//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <map>
#include "SceneChunk.h"

class Scene
{
protected:
	std::map<sf::Vector2i, SceneChunk*> chunks; // <������� �����, ��������� �� ��� ����>
	sf::Vector2i curChunkPos; // ����, ������������ �������� ������������ � �������� �����
	SceneChunk* startChunk; // ��������� ����

public:
	Scene();
	void update(float elapsedTime);
	void draw();
	void setCurrentChunk(sf::Vector2i _curChunkPos);
};

