#include "Graph.h"

Graph::Graph(sf::Vector2f dim, sf::Color inputColor, sf::Color outputColor) :
dim(dim),
inputData(),
outputData(),
inputColor(inputColor),
outputColor(outputColor)
{
	on = true;
}

//need to convert from normal coordinates into computer coordinates
void Graph::addData(double input, double output) {
	int y = dim.y / 2 - (int)(input * 100);
	inputData.push_back(sf::Vertex(sf::Vector2f(inputData.size()*5, y), inputColor));

	int y2 = dim.y / 2 - (int)(output * 100);
	outputData.push_back(sf::Vertex(sf::Vector2f(outputData.size()*5, y2), outputColor));
}

//draws everything
void Graph::draw(sf::RenderWindow *window) {
	drawAxis(window);

	if (inputData.size() == 0 || outputData.size() == 0) return;

	for (int i = 1; i < inputData.size(); i++) {
		sf::Vertex segment[] = { inputData[i - 1], inputData[i] };
		window->draw(segment, 2, sf::Lines);

		sf::Vertex segment2[] = { outputData[i - 1], outputData[i] };
		window->draw(segment2, 2, sf::Lines);
	}
	
}

//draws x axis
void Graph::drawAxis(sf::RenderWindow *window) {
	sf::Vertex x_axis[] =
	{
		sf::Vertex(sf::Vector2f(0, dim.y/2), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(inputData.size()*5, dim.y/2), sf::Color{ 50, 55, 125 })
	};
	window->draw(x_axis, 2, sf::Lines);
}