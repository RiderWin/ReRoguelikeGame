#pragma once
#include <SFML\Graphics.hpp>

class GameData
{
private:
	GameData();
public:
	static void init();
	static sf::Texture& texHero;
	static sf::Texture& texBox;
};

