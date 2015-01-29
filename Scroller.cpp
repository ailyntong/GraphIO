//made by Neelay

#include "Scroller.h"

Scroller::Scroller(const sf::Vector2f &pos, const sf::Vector2f &bounding_dim, float lower_bound, float upper_bound, float range) :
pos{ std::move(pos) },
dim{ bounding_dim },
lower_bound{ lower_bound },
upper_bound{ upper_bound },
output_range{ upper_bound - lower_bound },
scroller_scale{ range / (upper_bound - lower_bound), 0.9f } {
	bounding_rect.setFillColor(sf::Color::Green);
	bounding_rect.setPosition(pos);
	bounding_rect.setSize({ dim.x, dim.y });
	width_padding = bounding_rect.getSize().x * width_padding_scale;
	scroll_rect.setFillColor(sf::Color::White);
	scroll_rect.setSize({ dim.x * scroller_scale.x, dim.y*scroller_scale.y });
	scroll_rect.setPosition({ pos.x + (dim.x - scroll_rect.getSize().x) / 2, pos.y + (dim.y - scroll_rect.getSize().y) / 2 });

	scroll_range = ((bounding_rect.getPosition().x + bounding_rect.getSize().x) - width_padding - (scroll_rect.getSize().x / 2)) -
		(bounding_rect.getPosition().x + width_padding + (scroll_rect.getSize().x / 2));
	std::cout << "scroll_range: " << scroll_range << std::endl;
}


Scroller::~Scroller() {

}

void Scroller::update(const sf::Window &window) {
	static float curr_mouse_x = sf::Mouse::getPosition(window).x;
	static float prev_mouse_x = sf::Mouse::getPosition(window).x;

	static bool click_held = false;

	curr_mouse_x = sf::Mouse::getPosition(window).x;
	x_velocity = curr_mouse_x - prev_mouse_x;

	float scroll_pos = scroll_rect.getPosition().x;
	if (isClicked(window))
		click_held = true;

	if (click_held) {
		if (x_velocity < 0) {
			if (scroll_rect.getPosition().x + x_velocity > bounding_rect.getPosition().x + width_padding) {
				scroll_rect.move(x_velocity, 0);
			} else {
				scroll_rect.move(-(scroll_rect.getPosition().x - (bounding_rect.getPosition().x + width_padding)), 0);
			}
		}
		if (x_velocity > 0) {
			if (scroll_rect.getPosition().x + scroll_rect.getSize().x + x_velocity < bounding_rect.getPosition().x + bounding_rect.getSize().x - width_padding) {
				scroll_rect.move(x_velocity, 0);
			} else {
				scroll_rect.move(bounding_rect.getPosition().x + bounding_rect.getSize().x - scroll_rect.getPosition().x - scroll_rect.getSize().x - width_padding, 0);
			}
		}
	}

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		click_held = false;
	}

	prev_mouse_x = curr_mouse_x;

	output = (((scroll_rect.getPosition().x + scroll_rect.getSize().x / 2) - (bounding_rect.getPosition().x + width_padding + scroll_rect.getSize().x / 2)) / scroll_range)*output_range;
	std::cout << "output: " << output << std::endl;
}

void Scroller::draw(sf::RenderWindow *window) {
	window->draw(bounding_rect);
	window->draw(scroll_rect);
}

bool Scroller::isClicked(const sf::Window &window) const {
	//std::cout << sf::Mouse::getPosition(window).x << std::endl;
	if (sf::Mouse::getPosition(window).x >= scroll_rect.getPosition().x &&
		sf::Mouse::getPosition(window).x <= scroll_rect.getPosition().x + scroll_rect.getSize().x &&
		sf::Mouse::getPosition(window).y >= scroll_rect.getPosition().y &&
		sf::Mouse::getPosition(window).y <= scroll_rect.getPosition().y + scroll_rect.getSize().y &&
		sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		//std::cout << "clicked" << std::endl;
		return true;
	}
	return false;
}