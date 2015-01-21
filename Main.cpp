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
	win.setFramerateLimit(20);
	sf::RenderWindow win2(sf::VideoMode(1000, 500), "Curvy");
	win2.setFramerateLimit(20);

	sf::View view{ sf::FloatRect{ 0.f, 0.f, 1000, 500 } };
	view.zoom(1);
	win.setView(view);
	win2.setView(view);

	Graph graph({ 1000, 500 });
	Button button({ 0, 0 }, { 100, 100 });

	Graph graph2({ 1000, 500 });
	Button button2({ 0, 0 }, { 100, 100 });

	while (win.isOpen() && win2.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e)) {
		if (e.type = sf::Event::Closed)
			win.close();
		}
		while (win2.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				win2.close();
		}

		win.clear();
		win2.clear();
		
		graph.draw(&win);
		button.update(win);
		win.draw(button);


		graph2.draw(&win2);
		button2.update(win2);
		win2.draw(button2);


		win.display();
		win2.display();
	}


	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	return 0;
}

double randValue() {
	unsigned seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(-100, 100);
	auto dice = std::bind(distribution, generator);

	return dice() / 100;
}