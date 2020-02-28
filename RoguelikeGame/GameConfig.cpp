#include "GameConfig.h"
#include "StandartInclude.h"
#include "GraphicEngine.h"


bool GameConfig::isDebug = true;
// Window
sf::RenderWindow GameConfig::window;
sf::String GameConfig::title = "Trees";
int GameConfig::windowStyle = sf::Style::Default;
sf::Vector2u GameConfig::resolution;


void GameConfig::init()
{
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	//resolution = sf::Vector2u(videoMode.width, videoMode.height);
	resolution = sf::Vector2u(800, 450);

	window.create(sf::VideoMode(resolution.x, resolution.y), title, windowStyle);
	GraphicEngine::setWindow(&window);
}

void GameConfig::input(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		window.close();
	else if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Num1:
			window.setSize(sf::Vector2u(1600, 900));
			break;
		case sf::Keyboard::Num2:
			window.setSize(sf::Vector2u(800, 450));
			break;
		case sf::Keyboard::Num3:
			window.setSize(sf::Vector2u(1366, 768));
			break;
		case sf::Keyboard::F11:
			if (windowStyle != sf::Style::Fullscreen)
				windowStyle = sf::Style::Fullscreen;
			else
				windowStyle = sf::Style::Default;
			window.create(sf::VideoMode(resolution.x, resolution.y), title, windowStyle);
			break;
		default:
			break;
		}
	}
}