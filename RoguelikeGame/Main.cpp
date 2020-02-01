#include "Game.h"


int main()
{
	srand(time(0));
	GameData::init();
	GameConfig::init();
	Game game;
	game.start();

	return 0;
}