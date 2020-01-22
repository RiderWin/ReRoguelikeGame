#include "GraphicObject.h"

GraphicObject::GraphicObject(const std::string& _image, const sf::IntRect& _texRect): texture(*new sf::Texture())
{
	texture.loadFromFile(_image);
	setTexture(texture);
	texRect = _texRect;
	setTextureRect(texRect);
}

void GraphicObject::debug()
{

}

