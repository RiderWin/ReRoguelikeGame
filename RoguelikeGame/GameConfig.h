//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>

// Класс, хранящий внешние параметры игры
class GameConfig
{
private:
	GameConfig();
public:
	static bool isDebug;
	// Window
	static sf::RenderWindow window;
	static sf::String title;
	static int windowStyle;
	static sf::Vector2u resolution;

	static void init();
	static void input(sf::Event event);
};

