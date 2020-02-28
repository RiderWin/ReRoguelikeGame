#pragma once
#include <vector>
#include "GraphicObject.h"

class GraphicEngine
{
private:
	GraphicEngine();
	static sf::RenderWindow* window;
	static std::vector<GraphicObject*> objects;

	static void addObject(GraphicObject* obj);
public:
	static void draw(const GraphicObject& obj);
	static void setWindow(sf::RenderWindow* _window);
	static void setView(sf::View& view);

	friend class GraphicObject;
};

