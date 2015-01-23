#include "Graph.h"

Graph::Graph(sf::Vector2f dim, sf::Color inputColor, sf::Color outputColor) :
dim(dim),
inputData(),
outputData(),
inputColor(inputColor),
outputColor(outputColor)
{

}

void Graph::addInput(double value) {
	inputData.push_back(sf::Vertex(sf::Vector2f(inputData.size(), value)));
}

void Graph::addOutput(double value) {
	outputData.push_back(sf::Vertex(sf::Vector2f(outputData.size(), value)));
}

//draws everything
void Graph::draw(sf::RenderWindow *window) {
	drawAxis(window);

	//color testing
	sf::Vertex input[] =
	{
		sf::Vertex(sf::Vector2f(0, 100), inputColor),
		sf::Vertex(sf::Vector2f(dim.x, 100), inputColor)
	};
	window->draw(input, 2, sf::Lines);
	sf::Vertex output[] =
	{
		sf::Vertex(sf::Vector2f(0, 400), outputColor),
		sf::Vertex(sf::Vector2f(dim.x, 400), outputColor)
	};
	window->draw(output, 2, sf::Lines);
	
}

//draws x axis
void Graph::drawAxis(sf::RenderWindow *window) {
	sf::Vertex x_axis[] =
	{
		sf::Vertex(sf::Vector2f(0, dim.y/2), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(dim.x, dim.y/2), sf::Color{ 50, 55, 125 })
	};
	window->draw(x_axis, 2, sf::Lines);
}