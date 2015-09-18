#ifndef GRAPHLINE_H
#define GRAPHLINE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Constants.h"
#include "Point.h"

class GraphLine {
public:
	GraphLine(sf::Color color);
	void addData(double input);
	void draw(sf::RenderWindow *window);

	//various getters and setters
	inline int size() { return data.size(); };
	inline double getLast() { return data[data.size() - 1].y; };

	inline void toggleRunning() { running = !running; };
	inline bool isRunning() { return running; };

private:
	sf::Color color;	//color of graph line

	std::vector<Point> data;	//data taken from external source

	bool running;	//for pause/unpause
};

#endif