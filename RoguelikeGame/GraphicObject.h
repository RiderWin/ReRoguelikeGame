//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include "BaseObject.h"

// �����

// �����
// ���� - ���������, ������, ����� �� �����
// ������������� ������� - ����������� �����
// ����������� ������� : �����, �������
// ������������ ������� : ����� 
// 
// ������������� ������������� ����� - ��������
// ���������� ��� ����������� ������ - ��������� ����� �������

// ������� ����� ��� ����������� ��������
// ����������� ������ - ������, � �������� ���� ��������
class GraphicObject: public BaseObject, public sf::Sprite
{
protected:
	const sf::Texture& texture;
	sf::IntRect texRect;

public:
	GraphicObject(const sf::Texture& _texture);
	
	virtual void update(float elapsedTime) override;
	virtual void output() override;
	virtual void debug() override;

	void draw();

	using sf::Sprite::setPosition;
	// ��� ���������� �� ����� ������
	void setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos);
	// �������� ����, � ������� ��������� ������
	sf::Vector2i getChunkPos();
};

