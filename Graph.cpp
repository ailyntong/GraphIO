#include "Graph.h"

Graph::Graph(sf::Vector2f dim, sf::Color inputColor, sf::Color outputColor) :
dim(dim),
inputData(),
outputData(),
inputColor(inputColor),
outputColor(outputColor)
{

}

//need to convert from normal coordinates into computer coordinates
void Graph::addData(double input, double output) {
	int y = dim.y / 2 - (int)(input * 100);
	inputData.push_back(sf::Vertex(sf::Vector2f(inputData.size(), y), inputColor));

	int y2 = dim.y / 2 - (int)(output * 100);
	outputData.push_back(sf::Vertex(sf::Vector2f(outputData.size(), y2), outputColor));
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

	if (inputData.size() == 0 || outputData.size() == 0) return;

	//draw last bunch of data points
	int startIndex;
	if (inputData.size() < 10) startIndex = 1;
	else startIndex = inputData.size() - 9;

	for (int i = startIndex; i < inputData.size(); i++) {
		sf::Vertex segment[] = {inputData[i-1], inputData[i]};
		window->draw(segment, 2, sf::Lines);

		sf::Vertex segment2[] = { inputData[i - 1], inputData[i] };
		window->draw(segment2, 2, sf::Lines);
	}
	
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