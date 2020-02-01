#include "GameConfig.h"

sf::Vector2u GameConfig::resolution;

void GameConfig::init()
{
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	resolution = sf::Vector2u(videoMode.width, videoMode.height);
}
