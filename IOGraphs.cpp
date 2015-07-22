#include "IOGraphs.h"

//Constructor
IOGraphs::IOGraphs(sf::Vector2f dim, int numGraphs) :
settings(0, 0, 50),
font(),
dim(dim),
win(sf::VideoMode(dim.x, dim.y), "Graph", sf::Style::Default, settings),
view( sf::FloatRect{ 0.f, 0.f, dim.x, dim.y } ),
input(dim, sf::Color::Magenta),
output(dim, sf::Color::Cyan),
rpi{"4950"}
{
	win.setFramerateLimit(75);	//how many times a second the window updates
	view.zoom(1);
	win.setView(view);

	font.loadFromFile("C:/Windows/Fonts/arial.ttf");	//font used for numbers
	
	numUpdates = 0;	//number of times the window has updated; while paused numUpdates does not increment
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
				updateView(-10);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && view.getCenter().x < (input.size()*5 - dim.x/2))
				updateView(10);
		}
		//when graph is not paused, takes new values from external source and adds to graph lines
		else {
			//sf::Vector2f data = recvToData(rpi.recv);
			//input.addData(data.x);
			//input.addData(data.y);

			input.addData(randValue());
			output.addData(randValue());

			if (numUpdates > dim.x/5) updateView(5);
			++numUpdates;

			//so we have a list of data as well as a visual
			std::cout << "Input: " << input.getLast()/100 << "      Output: " << output.getLast()/100 << std::endl;
		}

		//standard SFML clear-draw-display sequence
		win.clear({ 20, 27, 35 });

		drawAxis();
		drawGuidelines();
		drawOnes(view.getCenter().x - dim.x/2);

		input.draw(&win);
		output.draw(&win);

		win.display();
	}
}

/*
Draws the x-axis
*/
void IOGraphs::drawAxis() {
	sf::Vertex x_axis[] = {
		sf::Vertex(sf::Vector2f(0, dim.y / 2), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(output.size() * 5, dim.y / 2), sf::Color{ 50, 55, 125 })
	};
	win.draw(x_axis, 2, sf::Lines);
}

/*
Draws guidelines at -1 and 1
*/
void IOGraphs::drawGuidelines() {
	sf::Vertex guide1[] = {
		sf::Vertex(sf::Vector2f(0, dim.y / 2 - 100), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(output.size() * 5, dim.y / 2 - 100), sf::Color{50, 55, 125})
	};
	win.draw(guide1, 2, sf::Lines);

	sf::Vertex guide2[] = {
		sf::Vertex(sf::Vector2f(0, dim.y / 2 + 100), sf::Color{ 50, 55, 125 }),
		sf::Vertex(sf::Vector2f(output.size() * 5, dim.y / 2 + 100), sf::Color{ 50, 55, 125 })
	};
	win.draw(guide2, 2, sf::Lines);
}

/*
Draws -1 and 1 for y-axis
*/
void IOGraphs::drawOnes(int edge) {
	sf::Text ones;
	ones.setFont(font);
	ones.setCharacterSize(14);
	ones.setStyle(sf::Text::Regular);
	ones.setColor(sf::Color::White);

	ones.setString("1");
	ones.setPosition(edge, dim.y / 2 - 100);
	win.draw(ones);
	
	ones.setString("-1");
	ones.setPosition(edge, dim.y / 2 + 100);
	win.draw(ones);
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

/*
Used for testing without robot
Generates a random value between -1 and 1

Credits to Neelay for making this method
*/
double IOGraphs::randValue() {
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
sf::Vector2f IOGraphs::recvToData(std::string str) {
	sf::Vector2f retval;

	std::string::size_type sz;
	retval.x = std::stod(str, &sz);
	retval.y = std::stod(str.substr(sz));

	return retval;
}