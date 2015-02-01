#include "IOGraphs.h"

/*
Main
*/
int main() {
	IOGraphs graphs({ 1000, 500 }, 2);
	graphs.run();

	std::cin.ignore();
	return 0;
}