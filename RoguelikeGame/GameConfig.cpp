#include "GameConfig.h"
#include "StandartInclude.h"

bool GameConfig::isDebug = true;
sf::String GameConfig::title = "Trees";
sf::Vector2u GameConfig::resolution;

void GameConfig::init()
{
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	resolution = sf::Vector2u(videoMode.width, videoMode.height);
}
