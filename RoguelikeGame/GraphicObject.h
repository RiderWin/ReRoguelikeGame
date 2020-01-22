#pragma once
#include <SFML\Graphics.hpp>

class GraphicObject: public sf::Sprite
{
private:
	sf::Texture& texture;
	sf::IntRect texRect;

public:
	GraphicObject(const std::string& image, const sf::IntRect& _texRect);
	
	void debug();
};

