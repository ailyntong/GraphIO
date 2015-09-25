#include "Graph.h"

Graph::Graph() :
input(sf::Color::Magenta),
output(sf::Color::Cyan)
{
	
}

void Graph::update(double inputValue, double outputValue) {
	input.addData(inputValue);
	output.addData(outputValue);
}

void Graph::draw(sf::RenderWindow *window) {
	drawAxis(window);
	input.draw(window);
	output.draw(window);
}

/*
Draws the x-axis
*/
void Graph::drawAxis(sf::RenderWindow *window) {
	sf::Vertex x_axis[] = {
		sf::Vertex(sf::Vector2f(0, GRAPH_DIM.y / 2), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(output.size() * 5, GRAPH_DIM.y / 2), sf::Color{ 50, 55, 125 })
	};
	window->draw(x_axis, 2, sf::Lines);
}

/*
Pauses/unpauses graphs
Moves view back to the most recent data when resuming
*/
void Graph::toggleRunning() {
	input.toggleRunning();
	output.toggleRunning();
}