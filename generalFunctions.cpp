#include "generalFunctions.h"
#include <random>


int generalFunctions::randInt(int min, int max) {
	return min + (rand() % (max - min));
}