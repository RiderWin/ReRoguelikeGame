//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include "BaseObject.h"


// Базовый класс для графических объектов
// Графический объект - объект, у которого есть текстура,
// но нет физического тела
class GraphicObject: public BaseObject, public sf::Sprite
{
protected:
	const sf::Texture& texture;
	sf::IntRect texRect;

public:
	GraphicObject(const sf::Texture& _texture);
	
	virtual void draw(sf::RenderWindow* window) override;
	virtual void debug() override;

	using sf::Sprite::setPosition;
	// Для размещение по сетке тайлов
	void setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos);
};

