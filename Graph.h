#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <chrono>
#include <functional>
#include <iostream>

class Graph {
public:
	Graph(sf::Vector2f dim, sf::Color inputColor = sf::Color::Cyan, sf::Color outputColor = sf::Color::Magenta);	//constructor
	void addData(double input, double output);	//adds an input and output 
	void draw(sf::RenderWindow *window);	//draws stuff
	inline int getDataSize() { return inputData.size(); };
	inline sf::Vector2f getDimensions() { return dim; };
	inline double getLastInput() { return inputData[inputData.size() - 1].position.y; };	//returns last value that was added
	inline double getLastOutput() { return outputData[outputData.size() - 1].position.y; };	//returns last value that was added

	bool running;
	inline void toggleRunning() { 
		running = !running; 
		std::cout << running << std::endl;
	};
private:
	sf::Vector2f dim;	//dimensions of graph
	std::vector<sf::Vertex> inputData, outputData;	//data sets
	sf::Color inputColor, outputColor;	//data colors; default input=cyan, output=magenta

	void drawAxis(sf::RenderWindow *window);	//drawsAxis
};

#endif