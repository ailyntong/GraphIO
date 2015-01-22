#include "Graph.h"

Graph::Graph(sf::Vector2f dim) : 
dim(dim),
inputData(),
outputData(),
inputColor(sf::Color::Cyan),
outputColor(sf::Color::Magenta)
{

}

void Graph::addInput(double value) {
	inputData.push_back(value);
}

void Graph::addOutput(double value) {
	outputData.push_back(value);
}

//draws everything
void Graph::draw(sf::RenderWindow *window) {
	drawAxis(window);

	//color testing
	sf::Vertex input[] =
	{
		sf::Vertex(sf::Vector2f(0, 100), inputColor),
		sf::Vertex(sf::Vector2f(1000, 100), inputColor)
	};
	window->draw(input, 2, sf::Lines);
	sf::Vertex output[] =
	{
		sf::Vertex(sf::Vector2f(0, 400), outputColor),
		sf::Vertex(sf::Vector2f(1000, 400), outputColor)
	};
	window->draw(output, 2, sf::Lines);
	
}

//draws x axis
void Graph::drawAxis(sf::RenderWindow *window) {
	sf::Vertex x_axis[] =
	{
		sf::Vertex(sf::Vector2f(0, 250), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(1000, 250), sf::Color{ 50, 55, 125 })
	};
	window->draw(x_axis, 2, sf::Lines);
}