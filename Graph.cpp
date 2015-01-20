#include "Graph.h"

Graph::Graph(sf::Vector2f dim) : 
dim(dim),
inputData(),
outputData()
{

}

void Graph::addInput(double value) {
	inputData.push_back(value);
}

void Graph::addOutput(double value) {
	outputData.push_back(value);
}

void Graph::draw(sf::RenderWindow *window) {
	drawAxis(window);

	//draw most recent bunch of datapoints
	
}

void Graph::drawAxis(sf::RenderWindow *window) {
	sf::Vertex x_axis[] =
	{
		sf::Vertex(sf::Vector2f(0, 250), sf::Color::Blue),
		sf::Vertex(sf::Vector2f(1000, 250))
	};
	window->draw(x_axis, 2, sf::Lines);
}