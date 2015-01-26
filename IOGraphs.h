#ifndef IOGRAPHS_H
#define IOGRAHPS_H

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
#include <array>
#include <iostream>

#include "Graph.h"

class IOGraphs {
public:
	IOGraphs(sf::Vector2f dim, int numGraphs);
	virtual ~IOGraphs();
	void run();
	inline void toggleOnOff() { isOn = !isOn; };
	inline bool getOnOff() { return isOn; };
private:
	sf::ContextSettings settings;
	sf::RenderWindow win1, win2;
	sf::View view;
	Graph graph1;
	Graph graph2;

	int numUpdates;
	bool isOn;
	sf::Vector2f dim;

	double randValue();
};

#endif