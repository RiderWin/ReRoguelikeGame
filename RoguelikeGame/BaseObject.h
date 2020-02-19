//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>

// ������� ����� ��� ���� ������� ��������
// ����� ����������� ����������� ������ ��� ������ �� ����� ����������
class BaseObject 
{
protected:
	static int numberOfObjects;
	int id;
public:
	// ������������� ���������
	BaseObject();

	// ������������ ������� ������� 
	virtual void input(sf::Event event) {};
	// ��������� ��������� �������
	virtual void update(float elapsedTime) {};
	// ������� �����-���� ���������
	virtual void output() {};
	// ������� ��� ������� �������
	virtual void debug() {};

	int getId();
};

