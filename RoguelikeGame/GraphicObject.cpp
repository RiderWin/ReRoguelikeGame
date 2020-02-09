#include "GraphicObject.h"


GraphicObject::GraphicObject(const sf::Texture& _texture): texture(_texture)
{
	flag = GRAPHIC_OBJ;
	setTexture(texture);
}

void GraphicObject::draw(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GraphicObject::debug()
{
}

void GraphicObject::setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos)
{
	setPosition(_tilePos.x * GameData::tileSize, _tilePos.y * GameData::tileSize);
	move(_chunkPos.x * GameData::chunkWidth * GameData::tileSize, _chunkPos.y * GameData::chunkHeight * GameData::tileSize);
}