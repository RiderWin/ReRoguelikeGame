#include "Game.h"

sf::Vector2u Game::resolution = sf::Vector2u(800, 450);
sf::String Game::title = "RoguelikeGame";


Game::Game()
{
	window.create(sf::VideoMode(resolution.x, resolution.y), title);
	init();
}

void Game::init()//
{
	character = new GameObject(GraphicObject("resources/img/hero.png", sf::IntRect(0, 192, 96, 96)), PhysicObject());
	character->getGraphic().setPosition(200, 200);

	objects.push_back(character);
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
		draw();
	}
}

bool isMove = false;

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
		if (objects[i]->getFlag() == GAME_OBJ)
			window.draw(static_cast<GameObject*>(objects[i])->getGraphic());
		else if (objects[i]->getFlag() == GRAPHIC_OBJ)
			window.draw(*static_cast<GraphicObject*>(objects[i]));
	}

	window.display();
}

// Добавление объектов в словарь по их айдишникам
// Animation class
// AnimationManager class
// Объект главного перса с передвижением
// TileMap