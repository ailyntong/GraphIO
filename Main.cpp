#include "IOGraphs.h"

double randValue();

int main() {
	IOGraphs graphs({ 1000, 500 }, 2);
	graphs.run();

	return 0;
}