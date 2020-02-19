//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include "Hero.h"

class Game
{
private:
	sf::RenderWindow window;
	
	std::vector<BaseObject*> objects;
	GameObject* gameObj;
	Hero* hero;

public:
	Game();
	void init();
	void start();
	void input(sf::Event event);
	void update(float elapsedTime);
	void output();

};

