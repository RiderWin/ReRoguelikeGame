#include "Game.h"

sf::Vector2u Game::resolution = sf::Vector2u(32 * 16, 32 * 9);// (1366, 768);
sf::String Game::title = "RoguelikeGame";


// Какие нужны параметры
// разрешение монитора ( 1366 x 768 )
// размер тайла ( 32 x 32 )
// размер карты ( 16 x 9 )
// 
// 
// 
// 

Game::Game()
{
	window.create(sf::VideoMode(32 * 16, 32 * 9), title, sf::Style::Default);
	window.setSize(sf::Vector2u(800, 450));

	sf::View& view = *new sf::View(sf::FloatRect(0, 0, 32 * 16, 32 * 9));
	//view.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	window.setView(view);

	init();
}

void Game::init()
{
	//graphObj = new GraphicObject("resources/img/hero.png", sf::IntRect(0, 96, 96, 96));
	//graphObj->setPosition(400, 200);

	//physObj = new PhysicObject();

	hero = new Hero();
	//hero->getGraphic().setPosition(200, 200);

	//objects.push_back(graphObj);
	//objects.push_back(physObj);
	objects.push_back(hero);
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

	for (int i = 0; i != objects.size(); i++)
	{
		objects[i]->input(event);
	}
}

void Game::update(float elapsedTime)
{
	window.setView(sf::View(sf::FloatRect(hero->getGraphic().getPosition().x, hero->getGraphic().getPosition().y, 32*16, 32*9)));
	
	
	//map.fun(hero->getGraphic().getGlobalBounds());
	for (int i = 0; i != objects.size(); i++)
	{
		objects[i]->update(elapsedTime);
	}
}

void Game::draw()
{
	window.clear();

	if (map.generate())
	{
		sf::Clock clock;
		while (clock.getElapsedTime().asSeconds() < 0.15)
		{
		}
		//std::cout << "HOP" << std::endl;
	}
	//else
	//{
	//	map.clear();
	//}

	map.draw(&window);
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