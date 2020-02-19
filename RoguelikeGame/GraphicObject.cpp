#include "GraphicObject.h"
#include "StandartInclude.h"
#include "GraphicEngine.h"

GraphicObject::GraphicObject(const sf::Texture& _texture) : texture(_texture)
{
	GraphicEngine::addObject(this);
	setTexture(texture);
}

void GraphicObject::update(float elapsedTime)
{
	// Обновление анимации
}

void GraphicObject::output()
{
	draw();
}

void GraphicObject::debug()
{
}

void GraphicObject::draw()
{
	GraphicEngine::draw(*this);
}

void GraphicObject::setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos)
{
	setPosition(_tilePos.x * GameData::tileSize, _tilePos.y * GameData::tileSize);
	move(_chunkPos.x * GameData::chunkWidth * GameData::tileSize, _chunkPos.y * GameData::chunkHeight * GameData::tileSize);
}

sf::Vector2i GraphicObject::getChunkPos()
{
	sf::Vector2i chunkPos(getPosition().x / GameData::chunkWidthPx, getPosition().y / GameData::chunkHeightPx);
	if (getPosition().x < 0) chunkPos.x--;
	if (getPosition().y < 0) chunkPos.y--;
	return chunkPos;
}