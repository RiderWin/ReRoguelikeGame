#include "Game.h"
#include "StandartInclude.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"
#include "Camera.h"
#include "SceneManager.h"


int Game::forestScene;
int Game::mindScene;

Game::Game()
{
	Camera::init();
	forestScene = SceneManager::addScene(Scene());
	SceneManager::changeScene(forestScene);
	init();
}

void Game::init()
{
	hero = new Hero();
	hero->getGraphic().setPosition(GameData::chunkWidthPx / 2, GameData::chunkHeightPx / 2);

	objects.emplace_back(hero);
}

void Game::start()
{
	sf::Clock clock;
	while (GameConfig::window.isOpen())
	{
		float elapsedTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event;
		while (GameConfig::window.pollEvent(event))
		{
			input(event);
		}

		update(elapsedTime);
		output();
	}
}

void Game::input(sf::Event event)
{
	GameConfig::input(event);
	Camera::input(event);
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->input(event);
	}
}

void Game::update(float elapsedTime)
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->update(elapsedTime);
	}
	Camera::update(hero->getGraphic().getPosition());
}

void Game::output()
{
	GameConfig::window.clear();
	SceneManager::getScene().draw();
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->output();
	}
	GameConfig::window.display();
}