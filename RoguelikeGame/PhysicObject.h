//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include "BaseObject.h"


// Базовый класс для физических объектов
// Физический объект - объект, у которого есть физическое тело,
// но нет текстуры
class PhysicObject: public BaseObject, sf::Sprite
{
protected:

public:


	using sf::Sprite::setPosition;
	// Для размещение по сетке тайлов
	void setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos);

};

