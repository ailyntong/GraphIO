#include "IOGraphs.h"

IOGraphs::IOGraphs(sf::Vector2f dim, int numGraphs) :
settings(0, 0, 25),
dim(dim),
win1(sf::VideoMode(dim.x, dim.y), "Win1", sf::Style::Default, settings),
win2(sf::VideoMode(dim.x, dim.y), "Win2", sf::Style::Default, settings),
view( sf::FloatRect{ 0.f, 0.f, dim.x, dim.y } ),
graph1(dim),
graph2(dim)
{
	win1.setFramerateLimit(75);
	win2.setFramerateLimit(75);
	view.zoom(1);
	win1.setView(view);
	win2.setView(view);
	
	numUpdates = 0;
}

IOGraphs::~IOGraphs() {

}

void IOGraphs::run() {
	while (win1.isOpen() && win2.isOpen()) {
		sf::Event e;
		while (win1.pollEvent(e)) {
			if (e.type = sf::Event::Closed) {
				win1.close();
				win2.close();
			}
			else if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Space) toggleRunning();
			}
		}
		while (win2.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				win2.close();
				win1.close();
			}
			else if (e.type == sf::Event::KeyPressed) {
				//space pauses/unpauses graphs
				if (e.key.code == sf::Keyboard::Space) toggleRunning();
			}
		}

		if (!isRunning()) {
			//scrolling
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && view.getCenter().x > dim.x/2)
				updateView(-5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && view.getCenter().x < graph1.getDataSize() * 5)
				updateView(5);
		}
		else {
			graph1.addData(randValue() + 0.5, randValue());
			graph2.addData(randValue() - 0.5, randValue());

			if (numUpdates > 200) updateView(5);
			++numUpdates;

			std::cout << "Input: " << graph1.getLastInput() << "      Output: " << graph1.getLastOutput() << std::endl;
		}

		win1.clear({ 20, 27, 35 });	//clears into nice blue-grayish background color
		win2.clear({ 20, 27, 35 });

		graph1.draw(&win1);
		graph2.draw(&win2);

		win1.display();
		win2.display();
	}
}

//generates a random value between -1 and 1, supposed to simulate joysticks
double IOGraphs::randValue() {
	unsigned seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(-100, 100);
	auto dice = std::bind(distribution, generator);

	return dice() / 100.0;
}

//moves the view left/right depending on the increment, and sets the wins to that
void IOGraphs::updateView(int increment) {
	view.move(increment, 0);
	win1.setView(view);
	win2.setView(view);
}