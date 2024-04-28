#pragma once

#include <string>

class Point
{
	int x, y;
public:
	Point(int x, int y);
	Point();

	std::string getPosStr();

	const int getX();
	const int getY();
};

