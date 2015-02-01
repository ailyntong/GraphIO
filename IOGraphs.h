#ifndef IOGRAPHS_H
#define IOGRAHPS_H

#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif

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
	void run();

private:
	sf::ContextSettings settings;	//so lines look smooth

	/*
	A window is the thing that pops up;
	however, a window contains the entire "world," as it were.
	The view allows you to see part of that world,
	but each update the entire world is being drawn.
	*/
	sf::RenderWindow win;
	sf::View view;

	Graph input, output;	//joystick(s) and encoder(s). More can be added

	int numUpdates;
	sf::Vector2f dim;

	inline bool isRunning() { return (input.isRunning() && output.isRunning()); };
	void toggleRunning();

	void updateView(int increment);

	double randValue();		//used for testing without robot
	double recvToData(std::string str);		//used for testing with robot
};

#endif