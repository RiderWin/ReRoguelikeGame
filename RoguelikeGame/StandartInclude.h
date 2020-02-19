#pragma once // Стандартные подключения
#include <iostream> // for debug
#include "GameData.h"
#include "GameConfig.h"


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