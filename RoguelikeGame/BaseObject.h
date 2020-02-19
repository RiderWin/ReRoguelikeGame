//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <SFML\Graphics.hpp>

// Базовый класс для всех игровых объектов
// Имеет стандартные виртуальные методы для работы со своим состоянием
class BaseObject 
{
protected:
	static int numberOfObjects;
	int id;
public:
	// Инициализация состояния
	BaseObject();

	// Обрабатывает входные события 
	virtual void input(sf::Event event) {};
	// Обновляет состояние объекта
	virtual void update(float elapsedTime) {};
	// Выводит какой-либо результат
	virtual void output() {};
	// Функция для отладки объекта
	virtual void debug() {};

	int getId();
};

