#include "GameData.h"

sf::Texture& GameData::texHero = *new sf::Texture();
sf::Texture& GameData::texBox = *new sf::Texture();

void GameData::init()
{
	texHero.loadFromFile("resources/img/hero.png", sf::IntRect(0, 0, 96, 96));
	texBox.loadFromFile("resources/img/box.png");
}