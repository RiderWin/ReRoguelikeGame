#include "GraphicObject.h"

GraphicObject::GraphicObject(const sf::Texture& _texture): texture(_texture)
{
	flag = GRAPHIC_OBJ;
	setTexture(texture);
}

void GraphicObject::draw(sf::RenderWindow* window)
{
	window->draw(*this);
	debug();
}

void GraphicObject::debug()
{
	//std::cout << "ID = " << id << " : height = "<< getGlobalBounds().height << " top = " << getGlobalBounds().top << std::endl;

	//std::cout << "ID = " << id << " : &texture " << &texture << std::endl;
}