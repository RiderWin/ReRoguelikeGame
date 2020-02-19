#include "Game.h"
#include "StandartInclude.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"
#include "Map.h"


Game::Game()
{
	window.create(sf::VideoMode(GameData::chunkWidthPx, GameData::chunkHeightPx), GameConfig::title, sf::Style::Default);
	GraphicEngine::setWindow(&window);

	// For camera in GraphicEngine
	//sf::View& view = *new sf::View(sf::FloatRect(11 * Tile::size, 6 * Tile::size, 22 * Tile::size, 12 * Tile::size));
	//view.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	//window.setView(view);
	Map::create();
	init();
}

void Game::init()
{
	hero = new Hero();
	hero->getGraphic().setPosition(GameData::chunkWidthPx/2, GameData::chunkHeightPx/2);
	
	objects.emplace_back(hero);
}

void Game::start()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		float elapsedTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			input(event);
		}

		update(elapsedTime);
		output();
	}
}

void Game::input(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		window.close();
	else if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Num1:
			window.setSize(sf::Vector2u(32*16, 32*9));
			break;
		case sf::Keyboard::Num2:
			window.setSize(sf::Vector2u(800, 450));
			break;
		case sf::Keyboard::Num3:
			window.setSize(sf::Vector2u(1366, 768));
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->input(event);
	}
}

void Game::update(float elapsedTime)
{
	window.setView(sf::View(sf::FloatRect(
		hero->getGraphic().getPosition().x - GameData::chunkWidthPx/2*5,
		hero->getGraphic().getPosition().y - GameData::chunkHeightPx/2*5,
		GameData::chunkWidthPx*5, GameData::chunkHeightPx*5)));

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->update(elapsedTime);
	}
}

void Game::output()
{
	window.clear();
	Map::draw();
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->output();
	}
	window.display();
}