//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include "BaseObject.h"


// ������� ����� ��� ���������� ��������
// ���������� ������ - ������, � �������� ���� ���������� ����,
// �� ��� ��������
class PhysicObject: public BaseObject, sf::Sprite
{
protected:

public:


	using sf::Sprite::setPosition;
	// ��� ���������� �� ����� ������
	void setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos);

};

