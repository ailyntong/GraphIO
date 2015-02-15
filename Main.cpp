#include "IOGraphs.h"
#include "Win_UDP_Listener.h"

#include <iostream>
#include <string>
#include <array>
#include <fstream>

/*
Main
*/
int main() {
	IOGraphs graphs({ 1000, 500 }, 2);
	graphs.run();

	/*sf::RenderWindow win(sf::VideoMode(200, 200), "Graph");

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(10);
	text.setStyle(sf::Text::Regular);
	text.setColor(sf::Color::White);
	text.setString("Hello World");

	while (win.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e)) {
			if (e.type == sf::Event::Closed) win.close();	//closes window if the x is pressed
		}

		win.clear();
		win.draw(text);
		win.display();
	}*/

	/*std::ofstream ofs;
	ofs.open("test.txt");
	ofs << "hello";
	ofs.close();*/

	/*
	Win_UDP_Listener rpi("4950");
	std::cout << "heree" << std::endl;
	while (true) 
		std::cout << rpi.recv() << std::endl;
		*/
/*	std::string orbits("-1 0.5 1");
	std::string::size_type sz, sz2;
	std::cout << "orbits: " << orbits << std::endl;
	std::cout << std::stod(orbits, &sz);
	std::cout << "   sz: " << sz << std::endl;

	std::cout << std::stod(orbits.substr(sz), &sz2);
	std::cout << "   sz2: " << sz2 << std::endl;

	std::cout << std::stod(orbits.substr(sz + sz2)) << std::endl;*/

	std::cin.ignore();
	return 0;
}