#include "Button.h"

Button::Button(sf::Vector2f pos, sf::Vector2f dim) :
pos(pos),
dim(dim),
enabled(0, 255, 0),
disabled(255, 0, 0)
{
	this->state = DISABLED;

	this->setFillColor((state == State::ENABLED) ? enabled : disabled);
	this->setPosition(pos);
	this->setSize(dim);
}

void Button::update(const sf::RenderWindow &win) {

	float mouse_x = sf::Mouse::getPosition(win).x;
	float mouse_y = sf::Mouse::getPosition(win).y;

	if (clicked(win, {mouse_x, mouse_y}) /*&& !click_to*/) {
		if (state == ENABLED) {
			state = DISABLED;
			setFillColor(disabled);
		} else if (state == DISABLED) {
			state = ENABLED;
			setFillColor(enabled);
		}
		//click_to = true;
		//t0 = std::chrono::time_point_cast<milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch());
	}


}

bool Button::clicked(const sf::RenderWindow &win, sf::Vector2f mouse_pos) const {
	if (mouse_pos.x > getPosition().x && mouse_pos.x < getPosition().x + getSize().x &&
		mouse_pos.y > getPosition().y && mouse_pos.y < getPosition().y + getSize().y &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		return true;
	}
	return false;
}
