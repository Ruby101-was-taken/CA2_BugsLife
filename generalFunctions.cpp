#include "generalFunctions.h"
#include <random>
#include <iostream>


int randInt(int min, int max) {
	return min + (rand() % (max - min + 1));
}