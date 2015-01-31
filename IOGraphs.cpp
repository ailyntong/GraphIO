#include "IOGraphs.h"

IOGraphs::IOGraphs(sf::Vector2f dim, int numGraphs) :
settings(0, 0, 25),
dim(dim),
win(sf::VideoMode(dim.x, dim.y), "Graph", sf::Style::Default, settings),
view( sf::FloatRect{ 0.f, 0.f, dim.x, dim.y } ),
graph1(dim, sf::Color::Magenta),
graph2(dim, sf::Color::Cyan)
{
	win.setFramerateLimit(25);
	view.zoom(1);
	win.setView(view);
	
	numUpdates = 0;
}

IOGraphs::~IOGraphs() {

}

void IOGraphs::run() {
	while (win.isOpen()) {
		sf::Event e;

		while (win.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				win.close();
			else if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Return) toggleRunning();
			}
		}

		if (!isRunning()) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && view.getCenter().x > dim.x/2)
				updateView(-5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && view.getCenter().x < (graph1.size()*5 - dim.x/2))
				updateView(5);
		}
		else {
			graph1.addData(randValue());
			graph2.addData(randValue() - 0.5);

			if (numUpdates > dim.x/5) updateView(5);
			++numUpdates;

			std::cout << "Input: " << graph1.getLast() << "      Output: " << graph2.getLast() << std::endl;
		}

		win.clear({ 20, 27, 35 });

		graph1.draw(&win);
		graph2.draw(&win);

		win.display();
	}
}

double IOGraphs::randValue() {
	unsigned seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(-100, 100);
	auto dice = std::bind(distribution, generator);

	return dice() / 100.0;
}

void IOGraphs::updateView(int increment) {
	view.move(increment, 0);
	win.setView(view);
}

void IOGraphs::toggleRunning() {
	graph1.toggleRunning();
	graph2.toggleRunning();

	if (isRunning()) {
		if (numUpdates < dim.x / 5) {
			view.reset(sf::FloatRect{ 0.f, 0.f, dim.x, dim.y });
			win.setView(view);
		}
		else updateView((graph1.size() * 5 - dim.x / 2) - view.getCenter().x);
	}
}