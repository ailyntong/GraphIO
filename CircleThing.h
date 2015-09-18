#ifndef CIRCLETHING_H
#define CIRCLETHING_H

#include <SFML/Graphics.hpp>

#include "Constants.h"

class CircleThing {
public:
	CircleThing();

	void draw(sf::RenderWindow *window);

private:
	sf::CircleShape base, dot;
};

#endif