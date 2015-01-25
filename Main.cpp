#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC


#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include <functional>
#include <iostream>

#include "Button.h"
#include "Graph.h"

double randValue();

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;

	sf::RenderWindow win(sf::VideoMode(1000, 500), "Linear");
	win.setFramerateLimit(100);
	sf::RenderWindow win2(sf::VideoMode(1000, 500), "Curvy");
	win2.setFramerateLimit(100);

	sf::View view{ sf::FloatRect{ 0.f, 0.f, 1000, 500 } };
	view.zoom(1);
	win.setView(view);
	win2.setView(view);

	//creates/initialises objects
	Graph graph({ 1000, 500 });
	//Button button({ 0, 0 }, { 100, 100 });
	Graph graph2({ 1000, 500 });
	//Button button2({ 0, 0 }, { 100, 100 });

	int count = 0;

	//clicking Linear(win) does not close windows while clicking Curvy(win2) does
	while (win.isOpen() && win2.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e)) {
			if (e.type = sf::Event::Closed) {
				win.close();
				win2.close();
			}
		}
		while (win2.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				win2.close();
				win.close();
			}
		}

		win.clear({ 20, 27, 35 });	//clears into nice blue-grayish background color
		win2.clear({ 20, 27, 35 });

		/*button.update(win);
		win.draw(button);
		button2.update(win2);
		win2.draw(button2);*/

		graph.addData(randValue()+0.5, randValue());
		graph2.addData(randValue()-0.5, randValue());

		if (count > 200) {
			view.move(5, 0);
			win.setView(view);
			win2.setView(view);
		}
		
		graph.draw(&win);
		graph2.draw(&win2);

		win.display();
		win2.display();

		++count;
	}

	return 0;
}

//generates a random value between -1 and 1, supposed to simulate joysticks
double randValue() {
	unsigned seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(-100, 100);
	auto dice = std::bind(distribution, generator);

	return dice() / 100.0;
}