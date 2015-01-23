#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <chrono>
class Button : public sf::RectangleShape {	//a button is a rectangle
private:
	using milliseconds = std::chrono::milliseconds;	//shortcut
	sf::Color enabled, disabled;	//default enabled is green, disabled is red
	sf::Vector2f pos, dim;
	enum State { ENABLED, DISABLED } state;

	const milliseconds to_time = (milliseconds)500;		//for timer
	std::chrono::system_clock::time_point t0;
	bool click_to = false;

public:
	Button(sf::Vector2f pos, sf::Vector2f dim);

	void update(const sf::RenderWindow &win);
	bool clicked(const sf::RenderWindow &win, sf::Vector2f mouse_pos) const;

	inline State getState() const { return state; }
	inline void setState(State state) { this->state = state; }
	/*friend std::ostream& operator<<(std::ostream &os, Button &button) {
		return os << button.pos.x << ", " << button.pos.y;
	}*/
};

#endif