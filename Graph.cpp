#include "Graph.h"

Graph::Graph(sf::Vector2f dim, sf::Color color) :
dim(dim),
data(),
color(color)
{
	running = true;
}

void Graph::addData(double input) {
	int y = dim.y / 2 - (int)(input * 100);
	data.push_back(sf::Vertex(sf::Vector2f(data.size() * 5, y), color));
}

//draws everything
void Graph::draw(sf::RenderWindow *window) {
	drawAxis(window);

	if (data.size() == 0) return;

	for (int i = 1; i < data.size(); i++) {
		sf::Vertex segment[] = { data[i - 1], data[i] };
		window->draw(segment, 2, sf::Lines);
	}
	
}

//draws x axis
void Graph::drawAxis(sf::RenderWindow *window) {
	sf::Vertex x_axis[] =
	{
		sf::Vertex(sf::Vector2f(0, dim.y/2), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(data.size()*5, dim.y/2), sf::Color{ 50, 55, 125 })
	};
	window->draw(x_axis, 2, sf::Lines);
}