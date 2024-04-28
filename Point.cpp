#include "Point.h"

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
Point::Point() {
	this->x = 1;
	this->y = 1;
}

std::string Point::getPosStr() {
	return std::to_string(x) + ", " + std::to_string(y);
}

const int Point::getX() { return x; }
const int Point::getY() { return y; }