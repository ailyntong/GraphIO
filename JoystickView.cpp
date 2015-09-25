#include "JoystickView.h"

JoystickView::JoystickView() :
base(JOY_RADIUS),
dot(DOT_RADIUS),
position(0, 0)
{
	base.setFillColor({ 20, 27, 35 });
}

void JoystickView::update(double x, double y) {
	position.x = x;
	position.y = y;


	dot.setPosition(position.x * 2 + JOY_RADIUS, -position.y * 2 + JOY_RADIUS);
}

void JoystickView::draw(sf::RenderWindow *window) {
	window->draw(base);
	window->draw(dot);
}