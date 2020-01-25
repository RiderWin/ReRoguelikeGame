#pragma once
#include "BaseObject.h"

class GraphicObject: public BaseObject, public sf::Sprite
{
private:
	const sf::Texture& texture;
	sf::IntRect texRect;

public:
	GraphicObject(const sf::Texture& _texture);
	
	virtual void draw(sf::RenderWindow* window) override;
	virtual void debug() override;
};

