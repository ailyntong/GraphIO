#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>

class Graph {
public:
	Graph(sf::Vector2f dim, sf::Color color);	//constructor
	void addData(double input);	//adds an input
	void draw(sf::RenderWindow *window);	//draws stuff

	inline int getDataSize() { return data.size(); };
	inline sf::Vector2f getDimensions() { return dim; };
	inline double getLastData() { return data[data.size() - 1].position.y; };	//returns last value that was added

	inline void toggleRunning() { running = !running; };
	inline bool isRunning() { return running; };
private:
	sf::Vector2f dim;	//dimensions of graph
	std::vector<sf::Vertex> data;	//data sets
	sf::Color color;	//data colors; default input=cyan, output=magenta

	void drawAxis(sf::RenderWindow *window);	//drawsAxis

	bool running;
};

#endif