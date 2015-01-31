#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>

class Graph {
public:
	Graph(sf::Vector2f dim, sf::Color color);
	void addData(double input);
	void draw(sf::RenderWindow *window);

	inline int size() { return data.size(); };
	inline sf::Vector2f getDimensions() { return dim; };
	inline double getLast() { return data[data.size() - 1].position.y; };

	inline void toggleRunning() { running = !running; };
	inline bool isRunning() { return running; };
private:
	sf::Vector2f dim;
	std::vector<sf::Vertex> data;
	sf::Color color;

	void drawAxis(sf::RenderWindow *window);

	bool running;
};

#endif