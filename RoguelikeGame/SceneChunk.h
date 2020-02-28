//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
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
	//std::vector<Object*> objects; // � ������� ������� �������
	std::vector<SceneChunk> nextChunks; // ������ ��������� ������

	SceneChunk(const sf::Vector2i& _position);
	virtual void generate() = 0;
	void update(float elapsedTime);
	void draw();
};

