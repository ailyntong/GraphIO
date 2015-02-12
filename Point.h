#ifndef POINT_H
#define POINT_H
#include <cstdint>

struct Point {
	uint32_t x : 24;
	int32_t y : 8;
	Point(uint32_t x, int32_t y) :
		x(x),
		y(y)
	{
	}
};

#endif