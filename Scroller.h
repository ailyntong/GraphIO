#pragma once
#ifndef SCROLLER_H
#define SCROLLER_H

#include <SFML\Graphics.hpp>
#include <iostream>

class Scroller {
private:
	sf::RectangleShape scroll_rect;
	sf::RectangleShape bounding_rect;

	float lower_bound;
	float upper_bound;
	float output;
	float output_range;
	float scroll_range;
	float width_padding;
	float width_padding_scale = .009;

	sf::Vector2f pos;
	sf::Vector2f dim;

	float x_velocity;

	sf::Vector2f scroller_scale;
public:
	Scroller(const sf::Vector2f &pos, const sf::Vector2f &dim, float lower_bound, float upper_bound, float range);
	~Scroller();

	void update(const sf::Window &window);
	void draw(sf::RenderWindow *window);

	bool isClicked(const sf::Window &window) const;

	float getOutput() const { return output; }

};

#endif