//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include "BaseObject.h"


// ������� ����� ��� ���������� ��������
// ���������� ������ - ������, � �������� ���� ���������� ����
class PhysicObject: public BaseObject, sf::Transformable
{
protected:

public:



	using sf::Transformable::setPosition;
	// ��� ���������� �� ����� ������
	void setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos);

};

