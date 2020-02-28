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
	std::vector<BaseObject*> objects;
	GameObject* gameObj;
	Hero* hero;

public:
	static int forestScene;
	static int mindScene;

	Game();
	void init();
	void start();
	void input(sf::Event event);
	void update(float elapsedTime);
	void output();

};

