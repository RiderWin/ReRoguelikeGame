#pragma once
#include <stack>
#include <map>
#include "GameObject.h"
#include "MapChunk.h"

// Для сравнения векторов
namespace sf
{
	template <typename T>
	bool operator <(const Vector2<T>& left, const Vector2<T>& right)
	{
		if (left.y == right.y) return (left.x < right.x);
		else return (left.y < right.y);
	}
}

class Map
{
private:
	int width;
	int height;
	std::map<sf::Vector2i, MapChunk> map;

public:
	Map();

	void generate();
	void clear();
	void update(float elapsedTime);
	void draw(sf::RenderWindow* window);
	void debug();
};

