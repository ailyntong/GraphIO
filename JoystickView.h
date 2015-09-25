#ifndef JOYSTICKVIEW_H
#define JOYSTICKVIEW_H

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Point.h"

class JoystickView {
public:
	JoystickView();

	void update(double x, double y);

	void draw(sf::RenderWindow *window);

private:
	const float DOT_RADIUS = 5;
	
	sf::CircleShape base, dot;

	Point position;
};

#endif