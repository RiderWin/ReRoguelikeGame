#pragma once
#include "BaseObject.h"

class GraphicObject: public BaseObject, public sf::Sprite
{
private:
	sf::Texture& texture;
	sf::IntRect texRect;

public:
	GraphicObject(const std::string& image, const sf::IntRect& _texRect);
	
	void debug() override;
};

