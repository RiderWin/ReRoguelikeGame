//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>

// ����� ������� ������
class Camera
{
private:
	Camera();
	static int width;
	static int height;
	static float scale;
	static sf::View view;

public:
	static void init();
	static void input(sf::Event event);
	static void update(const sf::Vector2f& _target);
};

