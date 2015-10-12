#include "JoystickView.h"

JoystickView::JoystickView() :
base(JOY_RADIUS),
dot(DOT_RADIUS),
position(0, 0)
{
	base.setFillColor({ 20, 27, 35 });
}

void JoystickView::update(double x, double y) {
	//std::cout << x << "   " << y << std::endl;
	
	position.x = x;
	position.y = y;

	//dot.setPosition(x * 100, y * 100);
	//std::cout << dot.getPosition().x << "   " << dot.getPosition().y << std::endl;
}

void JoystickView::draw(sf::RenderWindow *window) {
	window->draw(base);
	window->draw(dot);
}