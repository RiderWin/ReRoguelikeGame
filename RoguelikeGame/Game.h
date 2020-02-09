//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <vector>
#include "Map.h"
#include "Hero.h"

class Game
{
private:
	sf::RenderWindow window;

	Map map;
	std::vector<BaseObject*> objects;
	GameObject* gameObj;
	Hero* hero;

public:
	static sf::String title;

	Game();
	void init();
	void start();
	void input(sf::Event event);
	void update(float elapsedTime);
	void draw();

};

