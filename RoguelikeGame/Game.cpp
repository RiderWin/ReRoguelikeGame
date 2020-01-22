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
	gobj = new GameObject(GraphicObject("resources/img/hero.png", sf::IntRect(0, 192, 96, 96)), PhysicObject());
	gobj->getGraphic().setPosition(200, 200);
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

	/*sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 2. kychka-pc.ru");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/
}

bool isMove = false;

void Game::input(sf::Event event)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			isMove = true;
		}
	}
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			isMove = false;
		}
	}
}

void Game::update(float elapsedTime)
{
	if (isMove)
	{
		std::cout << elapsedTime << std::endl;
		sf::Vector2f pos = gobj->getGraphic().getPosition();
		gobj->getGraphic().setPosition(pos.x + elapsedTime*10, pos.y);
	}
}

void Game::draw()
{
	window.clear();

	window.draw(gobj->getGraphic());

	window.display();
}

// Animation class
// AnimationManager class
// Объект главного перса с передвижением
// TileMap