#pragma once

#include <vector>
#include "Bug.h"
#include <SFML/Graphics.hpp>

class Board
{
	std::vector<Bug*> allBugs;

	int w, h;
	int* wPtr = &w, * hPtr = &h;
	int gridSize;

	std::vector<sf::RectangleShape> boardSquares;


public:
	Board(int w, int h, int gridSize);

	void draw(sf::RenderWindow& win);

	void updateBugs();
	void drawBugs(sf::RenderWindow& win);
	void removeDeadBugs();
	void moveBugs();

	void drawBoard(sf::RenderWindow& win);
};

