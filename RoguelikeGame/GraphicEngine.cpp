#include "GraphicEngine.h"

sf::RenderWindow* GraphicEngine::window = nullptr;
std::vector<GraphicObject*> GraphicEngine::objects;

void GraphicEngine::addObject(GraphicObject* obj)
{
	objects.push_back(obj);
}

void GraphicEngine::draw(const GraphicObject& obj)
{
	window->draw(obj);
}

void GraphicEngine::setWindow(sf::RenderWindow* _window)
{
	window = _window;
}

void GraphicEngine::setView(sf::View& view)
{
	window->setView(view);
}