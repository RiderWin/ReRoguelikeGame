//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>

// Класс игровой камеры
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

