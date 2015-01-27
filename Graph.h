#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <chrono>
#include <functional>
#include <iostream>

class Graph {
public:
	Graph(sf::Vector2f dim, sf::Color inputColor = sf::Color::Cyan, sf::Color outputColor = sf::Color::Magenta);	//constructor
	void addData(double input, double output);
	void draw(sf::RenderWindow *window);	//draws stuff
	inline int getDataSize() { return inputData.size(); };
	inline sf::Vector2f getDimensions() { return dim; };
	inline double getLastInput() { return inputData[inputData.size() - 1].position.y; };
	inline double getLastOutput() { return outputData[outputData.size() - 1].position.y; };
	bool on;
private:
	sf::Vector2f dim;	//dimensions of graph
	std::vector<sf::Vertex> inputData, outputData;	//data sets
	sf::Color inputColor, outputColor;	//data colors; default input=cyan, output=magenta

	void drawAxis(sf::RenderWindow *window);	//drawsAxis
};

#endif