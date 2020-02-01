#pragma once
#include <SFML\Graphics.hpp>

class GameData
{
private:
	GameData();
public:
	static void init();

	/// 

	/// Textures
	static sf::Texture texHero;
	static sf::Texture texBox;
	static sf::Texture texDirt;
	static sf::Texture texDiamond;
};

