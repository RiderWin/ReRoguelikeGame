#include "GameData.h"
#include "StandartInclude.h"

/// Global variables
const int GameData::tileSize = 32;
const int GameData::tileSizeX2 = tileSize * 2; // Для больших тайлов (например, дорога)
const int GameData::chunkWidth = 22;
const int GameData::chunkHeight = 12;
const int GameData::chunkWidthPx = chunkWidth * tileSize;
const int GameData::chunkHeightPx = chunkHeight * tileSize;

/// Textures
sf::Texture GameData::texHero;
sf::Texture GameData::texBox;
sf::Texture GameData::texDirt;
sf::Texture GameData::texDiamond;
sf::Texture GameData::texChunkFrame;

sf::Texture GameData::texRoad;
sf::Texture GameData::texRoadLeft;
sf::Texture GameData::texRoadRight;

void GameData::init()
{
	texHero.loadFromFile("resources/img/hero.png", sf::IntRect(0, 0, 96, 96));
	texBox.loadFromFile("resources/img/box.png");
	texDirt.loadFromFile("resources/img/dirt.png");
	texDiamond.loadFromFile("resources/img/diamond_block32.png");
	texChunkFrame.loadFromFile("resources/img/frame22x12.png");

	texRoad.loadFromFile("resources/img/road.png", sf::IntRect(0, 0, tileSizeX2, tileSizeX2));
	texRoadLeft.loadFromFile("resources/img/road.png", sf::IntRect(tileSizeX2, 0, tileSizeX2, tileSizeX2));
	texRoadRight.loadFromFile("resources/img/road.png", sf::IntRect(tileSizeX2 * 2, 0, tileSizeX2, tileSizeX2));

}