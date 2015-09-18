#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include <functional>
#include <array>
#include <iostream>

#include "Constants.h"
#include "GraphLine.h"
#include "Win_UDP_Listener.h"

class Graph {
public:
	Graph();
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

	Win_UDP_Listener rpi;
	
	GraphLine input, output;	//joystick(s) and encoder(s). More can be added

	void drawAxis();;

	inline bool isRunning() { return (input.isRunning() && output.isRunning()); };
	void toggleRunning();

	void updateView(int increment);

	double randValue();		//used for testing without robot
	sf::Vector2f recvToData(std::string str);		//used for testing with robot

};

#endif