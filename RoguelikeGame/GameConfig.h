#pragma once
#include <SFML\Graphics.hpp>

class GameConfig
{
private:
	GameConfig();
public:
	static void init();
	static sf::Vector2u resolution;
};

