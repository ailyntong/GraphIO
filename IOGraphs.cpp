#include "IOGraphs.h"

IOGraphs::IOGraphs(sf::Vector2f dim) :
settings(),
dim(dim),
win1(sf::VideoMode(dim.x, dim.y), "Linear"),
win2(sf::VideoMode(dim.x, dim.y), "Curvy"),
view( sf::FloatRect{ 0.f, 0.f, dim.x, dim.y } ),
graph1(dim),
graph2(dim)
{
	settings.antialiasingLevel = 10;
	
	numUpdates = 0;
	on = true;
}