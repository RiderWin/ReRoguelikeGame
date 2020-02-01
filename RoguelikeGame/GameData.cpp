#include "GameData.h"

/// Textures
sf::Texture GameData::texHero = *new sf::Texture();
sf::Texture GameData::texBox = *new sf::Texture();
sf::Texture GameData::texDirt = *new sf::Texture();
sf::Texture GameData::texDiamond = *new sf::Texture();


void GameData::init()
{
	texHero.loadFromFile("resources/img/hero.png", sf::IntRect(0, 0, 96, 96));
	texBox.loadFromFile("resources/img/box.png");
	texDirt.loadFromFile("resources/img/dirt.png");
	texDiamond.loadFromFile("resources/img/diamond_block.png");
}