#ifndef IOGRAPHS_H
#define IOGRAPHS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <random>
#include <chrono>
#include <functional>

#include "Win_UDP_Listener.h"
#include "Constants.h"
#include "JoystickView.h"
#include "Graph.h"

class IOGraphs {
public:
	IOGraphs();

	void run();

private:
	const std::string PORT = "4950";
	const int FRAMERATE = 75;
	const int GRAPH_SPACING = 5;

	int numUpdates;

	Win_UDP_Listener rpi;
	
	sf::ContextSettings graphSettings, joySettings;

	JoystickView joy;
	sf::RenderWindow joystickWindow;

	sf::View graphView;
	sf::RenderWindow graphWindow;
	Graph graph;

	void updateView(int increment);
	void toggleRunning();

	double randValue();
	sf::Vector2f recvToData(std::string str);

};

#endif