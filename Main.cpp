#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif	//SFML_STATIC

#include "Constants.h"
#include "Graph.h"
#include "Win_UDP_Listener.h"

/*
Main
*/
int main() {
	Graph graph;
	graph.run();

	std::cin.ignore();
	return 0;
}