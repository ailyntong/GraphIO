#include "GraphLine.h"

/*
Constructor
*/
GraphLine::GraphLine(sf::Color color) :
data(),
color(color)
{
	running = true;
}

/*
Takes input, converts from cartesian coords to computer coords, and adds to data
*/
void GraphLine::addData(double input) {
	int y = GRAPH_DIM.y / 2 - std::round(input * 100);

	data.push_back(Point(data.size() * 5, y));
}

/*
Draws all data onto RenderWindow
*/
void GraphLine::draw(sf::RenderWindow *window) {
	if (data.size() == 0) return;

	//drawAxis(window);

	//draws the graph by connecting lines between the vertices (data points)
	for (int i = 1; i < data.size(); i++) {
		sf::Vertex s[] = {
			sf::Vertex(sf::Vector2f(data[i - 1].x, data[i - 1].y + GRAPH_DIM.y / 2), color),
			sf::Vertex(sf::Vector2f(data[i].x, data[i].y + GRAPH_DIM.y / 2), color)
		};
		window->draw(s, 2, sf::Lines);
	}
}