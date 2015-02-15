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
#include "Win_UDP_Listener.h"

class IOGraphs {
public:
	IOGraphs(sf::Vector2f dim, int numGraphs);
	void run();

private:
	sf::ContextSettings settings;	//so lines look smooth
	sf::Font font;

	/*
	A window is the thing that pops up;
	however, a window contains the entire "world," as it were.
	The view allows you to see part of that world,
	but each update the entire world is being drawn.
	*/
	sf::RenderWindow win;
	sf::View view;

	int numUpdates;
	sf::Vector2f dim;

	Win_UDP_Listener rpi;
	
	Graph input, output;	//joystick(s) and encoder(s). More can be added

	void drawAxis();
	void drawGuidelines();

	void drawOnes(int edge);

	inline bool isRunning() { return (input.isRunning() && output.isRunning()); };
	void toggleRunning();

	void updateView(int increment);

	double randValue();		//used for testing without robot
	sf::Vector2f recvToData(std::string str);		//used for testing with robot

};

#endif