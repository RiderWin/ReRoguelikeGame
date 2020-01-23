#include "Game.h"

sf::Vector2u Game::resolution = sf::Vector2u(800, 450);
sf::String Game::title = "RoguelikeGame";


Game::Game()
{
	window.create(sf::VideoMode(resolution.x, resolution.y), title);
	init();
}

void Game::init()
{
	graphObj = new GraphicObject("resources/img/hero.png", sf::IntRect(0, 96, 96, 96));
	graphObj->setPosition(400, 200);

	physObj = new PhysicObject();

	hero = new Hero();
	hero->getGraphic().setPosition(200, 200);

	objects.push_back(graphObj);
	objects.push_back(physObj);
	objects.push_back(hero);

	
}//govna kusok

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
		draw();
	}
}

void Game::input(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		window.close();

	for (int i = 0; i != objects.size(); i++)
	{
		objects[i]->input(event);
	}
}

void Game::update(float elapsedTime)
{
	for (int i = 0; i != objects.size(); i++)
	{
		objects[i]->update(elapsedTime);
	}
}

void Game::draw()
{
	window.clear();

	for (int i = 0; i != objects.size(); i++)
	{
		objects[i]->draw(&window);
	}

	window.display();
}

// Добавление объектов в словарь по их айдишникам
// Animation class
// AnimationManager class
// Объект главного перса с передвижением
// TileMap