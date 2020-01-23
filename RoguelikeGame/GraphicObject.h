#pragma once
#include "BaseObject.h"

class GraphicObject: public BaseObject, public sf::Sprite
{
private:
	sf::Texture& texture;
	sf::IntRect texRect;

public:
	GraphicObject(const std::string& image, const sf::IntRect& _texRect);
	
	virtual void debug() override;
	virtual void draw(sf::RenderWindow* window) override;
};

