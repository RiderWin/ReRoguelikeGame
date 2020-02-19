//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include "GraphicObject.h"
#include "PhysicObject.h"


// ������� ����� ��� ������� ��������
// ������� ������ - ������, ������������ ����������� � ���������� �������
class GameObject: public BaseObject
{
protected:
	GraphicObject graphic;
	PhysicObject physic;

public:
	GameObject(const GraphicObject& _graphic, const PhysicObject& _physic);
	
	virtual void update(float elapsedTime) override;
	virtual void output() override;

	GraphicObject& getGraphic();
	PhysicObject& getPhysic();
};

