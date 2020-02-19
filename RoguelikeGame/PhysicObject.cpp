#include "PhysicObject.h"
#include "StandartInclude.h"
#include "PhysicEngine.h"

void PhysicObject::setPosition(sf::Vector2i _chunkPos, sf::Vector2i _tilePos)
{
	setPosition(_tilePos.x * GameData::tileSize, _tilePos.y * GameData::tileSize);
	move(_chunkPos.x * GameData::chunkWidth * GameData::tileSize, _chunkPos.y * GameData::chunkHeight * GameData::tileSize);
}