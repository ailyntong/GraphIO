#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif	//SFML_STATIC

#include "Win_UDP_Listener.h"
#include "IOGraphs.h"

/*
Main
*/
int main() {
	IOGraphs graphs;
	graphs.run();

	std::cin.ignore();
	return 0;
}