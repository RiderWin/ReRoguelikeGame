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
	// Window
	static sf::RenderWindow window;
	static sf::String title;
	static int windowStyle;
	static sf::Vector2u resolution;

	static void init();
	static void input(sf::Event event);
};

