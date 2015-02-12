#include "Graph.h"

/*
Constructor
*/
Graph::Graph(sf::Vector2f dim, sf::Color color) :
dim(dim),
data(),
color(color)
{
	running = true;
}

/*
Takes input, converts from cartesian coords to computer coords, and adds to data
*/
void Graph::addData(double input) {
	int y = dim.y / 2 - std::round(input * 100);

	data.push_back(Point(data.size() * 5, y));
}

/*
Draws all data onto RenderWindow
*/
void Graph::draw(sf::RenderWindow *window) {
	if (data.size() == 0) return;

	drawAxis(window);

	//draws the graph by connecting lines between the vertices (data points)
	for (int i = 1; i < data.size(); i++) {
		sf::Vertex s[] = {
		sf::Vertex(sf::Vector2f(data[i - 1].x, data[i - 1].y + dim.y/2), color),
		sf::Vertex(sf::Vector2f(data[i].x, data[i].y + dim.y/2), color)
		};
		window->draw(s, 2, sf::Lines);
	}
}

/*
Draws the x-axis
*/
void Graph::drawAxis(sf::RenderWindow *window) {
	sf::Vertex x_axis[] = {
		sf::Vertex(sf::Vector2f(0, dim.y/2), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(data.size()*5, dim.y/2), sf::Color{ 50, 55, 125 })
	};
	window->draw(x_axis, 2, sf::Lines);
}