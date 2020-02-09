//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>


// Класс, хранящий изменяемые параметры игры
class GameConfig
{
private:
	GameConfig();
public:
	static bool isDebug;
	static sf::Vector2u resolution;

	static void init();
};

