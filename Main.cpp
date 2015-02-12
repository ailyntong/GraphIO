#include "IOGraphs.h"
#include "Win_UDP_Listener.h"

#include <iostream>
#include <string>
#include <array>
#include <fstream>

/*
Main
*/
int main() {
	/*std::ofstream ofs;
	ofs.open("test.txt");
	ofs << "hello";
	ofs.close();*/
	IOGraphs graphs({ 1000, 500 }, 2);
	graphs.run();
	/*
	Win_UDP_Listener rpi("4950");
	std::cout << "heree" << std::endl;
	while (true) 
		std::cout << rpi.recv() << std::endl;
		*/
/*	std::string orbits("-1 0.5 1");
	std::string::size_type sz, sz2;
	std::cout << "orbits: " << orbits << std::endl;
	std::cout << std::stod(orbits, &sz);
	std::cout << "   sz: " << sz << std::endl;

	std::cout << std::stod(orbits.substr(sz), &sz2);
	std::cout << "   sz2: " << sz2 << std::endl;

	std::cout << std::stod(orbits.substr(sz + sz2)) << std::endl;*/

	std::cin.ignore();
	return 0;
}