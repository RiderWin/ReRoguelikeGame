#include "GameData.h"
#include "StandartInclude.h"

/// Global variables
const int GameData::tileSize = 32;
const int GameData::tileSizeX3 = tileSize * 3; // Для больших тайлов (например, дорога)
const int GameData::chunkWidth = 33;
const int GameData::chunkHeight = 12;
const int GameData::chunkWidthPx = chunkWidth * tileSize;
const int GameData::chunkHeightPx = chunkHeight * tileSize;
const int GameData::roadWidth = chunkWidth / 3;
const int GameData::roadHeight = chunkHeight / 3;

/// Textures
sf::Texture GameData::texHero;
sf::Texture GameData::texBox;
sf::Texture GameData::texDirt;
sf::Texture GameData::texGrass;
sf::Texture GameData::texDiamond;
sf::Texture GameData::texChunkFrame;

sf::Texture GameData::texRoad;
sf::Texture GameData::texRoadLeft;
sf::Texture GameData::texRoadRight;

void GameData::init()
{
	texHero.loadFromFile("resources/img/hero.png", sf::IntRect(0, 0, 48, 64));
	texBox.loadFromFile("resources/img/box.png");
	texDirt.loadFromFile("resources/img/dirt96.png");
	texGrass.loadFromFile("resources/img/grass.png");
	texDiamond.loadFromFile("resources/img/diamond_block32.png");
	texChunkFrame.loadFromFile("resources/img/frame33x18.png");

	texRoad.loadFromFile("resources/img/road.png", sf::IntRect(0, 0, tileSizeX3, tileSizeX3));
	texRoadLeft.loadFromFile("resources/img/road.png", sf::IntRect(tileSizeX3, 0, tileSizeX3, tileSizeX3));
	texRoadRight.loadFromFile("resources/img/road.png", sf::IntRect(tileSizeX3 * 2, 0, tileSizeX3, tileSizeX3));

}