#include "Board.h"

#include <vector>
#include "Bug.h"
#include <SFML/Graphics.hpp>
#include "fileReader.h"

Board::Board(int w, int h) {
	this->w = w;
	this->h = h;

	wPtr = &this->w;
	hPtr = &this->h;

	allBugs = readBugFile(wPtr, hPtr);
}