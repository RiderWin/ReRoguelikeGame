//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include "BaseObject.h"

// Герой

// Враги
// Нипы - разговоры, квесты, стоят на месте
// Интерактивные объекты - абстрактный класс
// Статические объекты : стены, деревья
// Декоративные объекты : ковры 
// 
// Передвегаемые Интерактивные Живые - родители
// Физический или графический объект - составные части объекта

// Базовый класс для графических объектов
// Графический объект - объект, у которого есть текстура
class GraphicObject: public BaseObject, public sf::Sprite
{
protected:
	const sf::Texture& texture;
	sf::IntRect texRect;

public:
	GraphicObject(const sf::Texture& _texture);
	
	virtual void update(float elapsedTime) override;
	virtual void output() override;
	virtual void debug() override;

	void draw();

	using sf::Sprite::setPosition;
	// Для размещение по сетке тайлов
	void setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos);
	// Получить чанк, в котором находится объект
	sf::Vector2i getChunkPos();
};

