//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once // Стандартные подключения
#include <iostream> // for debug
#include <SFML\Graphics.hpp>
#include "GameData.h"
#include "GameConfig.h"

#define BASE_OBJ 0
#define GRAPHIC_OBJ 1
#define PHYSIC_OBJ 2
#define GAME_OBJ 3


// Для сравнения векторов
namespace sf
{
	template <typename T>
	bool operator <(const Vector2<T>& left, const Vector2<T>& right)
	{
		if (left.y == right.y) return (left.x < right.x);
		else return (left.y < right.y);
	}
}


// Базовый класс для объектов игры (GraphicObject, PhysicObject и тд)
// Имеет стандартные виртуальные функции для обновления, отрисовки, отладки и тд
class BaseObject 
{
protected:
	static int numberOfObjects;
	int id;
	int flag;
public:
	BaseObject();

	virtual void input(sf::Event event) {};
	virtual void update(float elapsedTime) {};
	virtual void draw(sf::RenderWindow* window) {};
	virtual void debug() {};

	int getId();
	int getFlag();
};

