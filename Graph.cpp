#include "Graph.h"

//Constructor
Graph::Graph() :
settings(0, 0, 50),
font(),
win(sf::VideoMode(DIM.x, DIM.y), "Graph", sf::Style::Default, settings),
view(sf::FloatRect{ 0.f, 0.f, DIM.x, DIM.y }),
input(sf::Color::Magenta),
output(sf::Color::Cyan),
rpi{"4950"}
{
	win.setFramerateLimit(FRAMERATE);	//how many times a second the window updates
	win.setView(view);

	font.loadFromFile("C:/Windows/Fonts/arial.ttf");	//font used for numbers
	
	numUpdates = 0;	//number of times the window has updated; while paused numUpdates does not increment
}

/*
Contains the while loop that does everything, including drawing and scrolling
*/
void Graph::run() {
	while (win.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e)) {
			if (e.type == sf::Event::Closed) win.close();	//closes window if the x is pressed
			else if (e.type == sf::Event::KeyPressed) {		//pressing enter pauses graph (also is default key for disabling robot)
				if (e.key.code == sf::Keyboard::Return) toggleRunning();
			}
		}

		//scrolling only when graph is paused
		if (!isRunning()) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && view.getCenter().x > DIM.x / 2)
				updateView(-10);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && view.getCenter().x < (input.size() * 5 - DIM.x / 2))
				updateView(10);
		}
		//when graph is not paused, takes new values from external source and adds to graph lines
		else {
			//sf::Vector2f data = recvToData(rpi.recv);
			//input.addData(data.x);
			//input.addData(data.y);

			input.addData(randValue());
			output.addData(randValue());

			if (numUpdates > DIM.x / 5) updateView(5);
			++numUpdates;

			//so we have a list of data as well as a visual
			std::cout << "Input: " << input.getLast()/100 << "      Output: " << output.getLast()/100 << std::endl;
		}

		//standard SFML clear-draw-display sequence
		win.clear({ 20, 27, 35 });

		drawAxis();

		input.draw(&win);
		output.draw(&win);

		win.display();
	}
}

/*
Draws the x-axis
*/
void Graph::drawAxis() {
	sf::Vertex x_axis[] = {
		sf::Vertex(sf::Vector2f(0, DIM.y / 2), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(output.size() * 5, DIM.y / 2), sf::Color{ 50, 55, 125 })
	};
	win.draw(x_axis, 2, sf::Lines);
}

/*
Moves view a certain increment for scrolling
*/
void Graph::updateView(int increment) {
	view.move(increment, 0);
	win.setView(view);
}

/*
Pauses/unpauses graphs
Moves view back to the most recent data when resuming
*/
void Graph::toggleRunning() {
	input.toggleRunning();
	output.toggleRunning();

	if (isRunning()) {
		if (numUpdates < DIM.x / 5) {
			view.reset(sf::FloatRect{ 0.f, 0.f, DIM.x, DIM.y });
			win.setView(view);
		}
		else updateView((input.size() * 5 - DIM.x / 2) - view.getCenter().x);
	}
}

/*
Used for testing without robot
Generates a random value between -1 and 1

Credits to Neelay for making this method
*/
double Graph::randValue() {
	//unsigned seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::default_random_engine generator(seed);
	static std::uniform_int_distribution<int> distribution(-100, 100);
	return distribution(generator) / 100.0;
}

/*
Used for testing with robot
Takes a string of values, and parses into
*/
sf::Vector2f Graph::recvToData(std::string str) {
	sf::Vector2f retval;

	std::string::size_type sz;
	retval.x = std::stod(str, &sz);
	retval.y = std::stod(str.substr(sz));

	return retval;
}