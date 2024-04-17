#pragma once

#include <vector>
#include "Bug.h"
#include <SFML/Graphics.hpp>

class Board
{
	std::vector<Bug*> allBugs;

	int w, h;
	int* wPtr = &w, * hPtr = &h;

	std::vector<sf::RectangleShape> boardSquares;

public:
	Board(int w, int h);
};

