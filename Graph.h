#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>

class Graph {
public:
	Graph(sf::Vector2f dim);
	void addInput(double value);
	void addOutput(double value);
	void draw(sf::RenderWindow *window);
private:
	sf::Vector2f dim;
	std::vector<double> inputData;
	std::vector<double> outputData;

	void drawAxis(sf::RenderWindow *window);
};

#endif