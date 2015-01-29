#include "IOGraphs.h"


int main() {
	IOGraphs graphs({ 1000, 500 }, 2);
	graphs.run();

	/*sf::RenderWindow win(sf::VideoMode(1000, 500), "Scroller");
	win.setFramerateLimit(15);
	Scroller scroller{ { 100, 100 }, { 300, 30 }, 0, 1000, 100 };

	while (win.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e)) {
			if (e.type == sf::Event::Closed) win.close();
		}
		win.clear();

		scroller.update(win);
		scroller.draw(&win);

		win.display();
	}*/

	std::cin.ignore();

	return 0;
}