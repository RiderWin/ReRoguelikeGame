//-----ReSpace-Engine-----
//	
//	����� ������ ���� ���-�� ������... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>

// �����, �������� ������� ��������� ����
class GameConfig
{
private:
	GameConfig();
public:
	static bool isDebug;
	static sf::String title;
	static sf::Vector2u resolution;

	static void init();
};

