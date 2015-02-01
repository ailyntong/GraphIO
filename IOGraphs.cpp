#include "IOGraphs.h"

//Constructor
IOGraphs::IOGraphs(sf::Vector2f dim, int numGraphs) :
settings(0, 0, 25),
dim(dim),
win(sf::VideoMode(dim.x, dim.y), "Graph", sf::Style::Default, settings),
view( sf::FloatRect{ 0.f, 0.f, dim.x, dim.y } ),
input(dim, sf::Color::Magenta),
output(dim, sf::Color::Cyan)
{
	win.setFramerateLimit(25);	//how many times a second the window updates
	view.zoom(1);
	win.setView(view);
	
	numUpdates = 0;	//number of times the window has updated
}

/*
Contains the while loop that does everything, including drawing and scrolling
*/
void IOGraphs::run() {
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && view.getCenter().x > dim.x/2)
				updateView(-5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && view.getCenter().x < (input.size()*5 - dim.x/2))
				updateView(5);
		}
		//when graph is not paused, takes new values from external source and adds to graph lines
		else {
			input.addData(randValue());
			output.addData(randValue() - 0.5);

			if (numUpdates > dim.x/5) updateView(5);
			++numUpdates;

			//so we have a list of data as well as a visual
			std::cout << "Input: " << input.getLast() << "      Output: " << output.getLast() << std::endl;
		}

		//standard SFML clear-draw-display sequence
		win.clear({ 20, 27, 35 });

		input.draw(&win);
		output.draw(&win);

		win.display();
	}
}

/*
Used for testing without robot
Generates a random value between -1 and 1

Credits to Neelay for making this method
*/
double IOGraphs::randValue() {
	unsigned seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(-100, 100);
	auto dice = std::bind(distribution, generator);

	return dice() / 100.0;
}

/*
Moves view a certain increment for scrolling
*/
void IOGraphs::updateView(int increment) {
	view.move(increment, 0);
	win.setView(view);
}

/*
Pauses/unpauses graphs
Moves view back to the most recent data when resuming
*/
void IOGraphs::toggleRunning() {
	input.toggleRunning();
	output.toggleRunning();

	if (isRunning()) {
		if (numUpdates < dim.x / 5) {
			view.reset(sf::FloatRect{ 0.f, 0.f, dim.x, dim.y });
			win.setView(view);
		}
		else updateView((input.size() * 5 - dim.x / 2) - view.getCenter().x);
	}
}