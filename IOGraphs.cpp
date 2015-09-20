#include "IOGraphs.h"

IOGraphs::IOGraphs() :
rpi(PORT),
settings(0, 0, 50), 
graphWindow(sf::VideoMode(DIM.x, DIM.y), "Graph", sf::Style::Default, settings),
graphView(sf::FloatRect{ 0.f, 0.f, DIM.x, DIM.y }),
graph()
{
	graphWindow.setFramerateLimit(FRAMERATE);
	graphWindow.setView(graphView);

	numUpdates = 0;
}

void IOGraphs::run() {
	while (graphWindow.isOpen()) {
		sf::Event e;
		while (graphWindow.pollEvent(e)) {
			if (e.type == sf::Event::Closed) 
				graphWindow.close();	//closes window if the x is pressed
			else if (e.type == sf::Event::KeyPressed) {		//pressing enter pauses graph (also is default key for disabling robot)
				if (e.key.code == sf::Keyboard::Return) toggleRunning();
			}
		}

		if (!graph.isRunning()) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && graphView.getCenter().x > DIM.x / 2)
				updateView(-GRAPH_SPACING * 2);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && graphView.getCenter().x < (graph.size() * 5 - DIM.x / 2))
				updateView(GRAPH_SPACING * 2);
		}
		//when graph is not paused, takes new values from external source and adds to graph lines
		else {
			//sf::Vector2f data = recvToData(rpi.recv);
			//input.addData(data.x);
			//input.addData(data.y);

			graph.update(randValue(), randValue());

			if (numUpdates > DIM.x / GRAPH_SPACING) 
				updateView(GRAPH_SPACING);

			++numUpdates;

			//so we have a list of data as well as a visual
			graph.print();
		}

		graphWindow.clear({ 20, 27, 35 });

		graph.draw(&graphWindow);

		graphWindow.display();
	}
}

void IOGraphs::updateView(int increment) {
	graphView.move(increment, 0);
	graphWindow.setView(graphView);
}

void IOGraphs::toggleRunning() {
	graph.toggleRunning();
	
	if (graph.isRunning()) {
		if (numUpdates < DIM.x / 5) {
			graphView.reset(sf::FloatRect{ 0.f, 0.f, DIM.x, DIM.y });
			graphWindow.setView(graphView);
		} else updateView((graph.size() * 5 - DIM.x / 2) - graphView.getCenter().x);
	}
}

/*
NOTE: get Neelay's updated rng method

Used for testing without robot
Generates a random value between -1 and 1

Credit: Neelay
*/
double IOGraphs::randValue() {
	static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine generator(seed);
	static std::uniform_int_distribution<int> distribution(-100, 100);
	return distribution(generator) / 100.0;
}

/*
Used for testing with robot

Credit: Neelay
*/
sf::Vector2f IOGraphs::recvToData(std::string str) {
	sf::Vector2f retval;

	std::string::size_type sz;
	retval.x = std::stod(str, &sz);
	retval.y = std::stod(str.substr(sz));

	return retval;
}