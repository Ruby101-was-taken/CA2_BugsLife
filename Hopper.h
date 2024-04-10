#pragma once
#include "Bug.h"
class Hopper : public Bug {

public:
	Hopper(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir);

	void move();
};

