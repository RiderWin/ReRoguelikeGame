//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>


// Класс, хранящий внутренние глобальные переменные и загружаемые данные
class GameData
{
private:
	GameData();
public:
	static void init();

	/// Global variables
	static const int tileSize;
	static const int tileSizeX2;
	static const int chunkWidth;
	static const int chunkHeight;
	static const int chunkWidthPx;
	static const int chunkHeightPx;

	/// Textures
	static sf::Texture texHero;
	static sf::Texture texBox;
	static sf::Texture texDirt;
	static sf::Texture texDiamond;
	static sf::Texture texChunkFrame;

	static sf::Texture texRoad;
	static sf::Texture texRoadLeft;
	static sf::Texture texRoadRight;
};