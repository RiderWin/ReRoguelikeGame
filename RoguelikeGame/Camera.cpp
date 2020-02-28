#include "Camera.h"
#include "StandartInclude.h"
#include "GraphicEngine.h"

int Camera::width = 24 * GameData::tileSize;
int Camera::height = 13.5 * GameData::tileSize;
float Camera::scale = 1;
sf::View Camera::view;

void Camera::init()
{
	view = sf::View(sf::FloatRect(0, 0, width * scale, height * scale));
	//view.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	GraphicEngine::setView(view);
}

void Camera::input(sf::Event event)
{
	if (event.type == sf::Event::MouseWheelScrolled)
	{
		scale -= event.mouseWheelScroll.delta / 10;
		if (scale < 0.2) scale = 0.2;
	}
}

void Camera::update(const sf::Vector2f& _target)
{
	view = sf::View(sf::FloatRect(
		_target.x - width / 2 * scale,
		_target.y - height / 2 * scale,
		width * scale, height * scale));
	GraphicEngine::setView(view);
}
