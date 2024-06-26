#pragma once
#include "Bug.h"
class Hopper : public Bug {
protected:
	int hopSize;

	//these values are used when the bug move method is recalled so it knows how far to move
	int hopsLeft;
	int hopsDone;

public:
	Hopper(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir, int hopSize);
	Hopper(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir);

	void move();
	void update();

	std::string getInfo();
};

