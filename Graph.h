#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>

class Graph {
public:
	Graph(sf::Vector2f dim, sf::Color color);
	void addData(double input);
	void draw(sf::RenderWindow *window);

	//various getters and setters
	inline int size() { return data.size(); };
	inline double getLast() { return data[data.size() - 1].position.y; };

	inline void toggleRunning() { running = !running; };
	inline bool isRunning() { return running; };

private:
	sf::Vector2f dim;	//should be the same as the RenderWindow it is drawing into
	sf::Color color;	//color of graph line

	std::vector<sf::Vertex> data;	//data taken from external source

	void drawAxis(sf::RenderWindow *window);

	bool running;	//for pause/unpause
};

#endif