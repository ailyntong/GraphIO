#ifndef JOYSTICKVIEW_H
#define JOYSTICKVIEW_H

#include <SFML/Graphics.hpp>

#include "Constants.h"

class JoystickView {
public:
	JoystickView();

	void draw(sf::RenderWindow *window);

private:
	const float BASE_RADIUS = 100;
	const float DOT_RADIUS = 5;
	
	sf::CircleShape base, dot;
};

#endif