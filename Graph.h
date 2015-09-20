#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Constants.h"
#include "GraphLine.h"
#include "Win_UDP_Listener.h"

class Graph {
public:
	Graph();

	void update(double inputValue, double outputValue);
	void draw(sf::RenderWindow *window);
	
	void toggleRunning();

	inline bool isRunning() { return (input.isRunning() && output.isRunning()); }
	inline int size() { return input.size(); }

	inline void print() { std::cout << "Input: " << input.getLast() / 100 << "      Output: " << output.getLast() / 100 << std::endl; }

private:
	GraphLine input, output;

	void drawAxis(sf::RenderWindow *window);

};

#endif