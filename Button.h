#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <chrono>
class Button : public sf::RectangleShape {
private:
	using milliseconds = std::chrono::milliseconds;
	sf::Color enabled, disabled;
	sf::Vector2f pos, dim;
	enum State { ENABLED, DISABLED } state;

	//const milliseconds to_time = (milliseconds)300;
	//std::chrono::time_point<milliseconds> t0;
	//bool click_to = false;
public:
	Button(sf::Vector2f pos, sf::Vector2f dim);

	void update(const sf::RenderWindow &win);
	bool clicked(const sf::RenderWindow &win, sf::Vector2f mouse_pos) const;

	inline State getState() const { return state; }
	inline void setState(State state) { this->state = state; }
};

#endif