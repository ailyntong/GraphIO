#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Graph {
public:
	Graph(sf::Vector2f dim, sf::Color inputColor = sf::Color::Cyan, sf::Color outputColor = sf::Color::Magenta);	//constructor
	void addInput(double value);	//from joystick
	void addOutput(double value);	//from encoder
	void draw(sf::RenderWindow *window);	//draws stuff
private:
	sf::Vector2f dim;	//dimensions of graph
	std::vector<sf::Vertex> inputData, outputData;	//data sets
	sf::Color inputColor, outputColor;	//data colors; default input=cyan, output=magenta

	void drawAxis(sf::RenderWindow *window);	//drawsAxis
};

#endif