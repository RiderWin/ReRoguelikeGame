//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>


// �����, �������� ���������� ���������� ���������� � ����������� ������
class GameData
{
private:
	GameData();
public:
	static void init();

	/// Global variables
	static const int tileSize;
	static const int tileSizeX3;
	static const int chunkWidth;
	static const int chunkHeight;
	static const int chunkWidthPx;
	static const int chunkHeightPx;
	static const int roadWidth;
	static const int roadHeight;

	/// Textures
	static sf::Texture texHero;
	static sf::Texture texBox;
	static sf::Texture texDirt;
	static sf::Texture texGrass;
	static sf::Texture texDiamond;
	static sf::Texture texChunkFrame;

	static sf::Texture texRoad;
	static sf::Texture texRoadLeft;
	static sf::Texture texRoadRight;
};