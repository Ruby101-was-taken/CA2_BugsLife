#pragma once

#include <vector>
#include "Bug.h"
#include <SFML/Graphics.hpp>

#include <string>

class Board
{
	std::vector<Bug*> aliveBugs;
	std::vector<Bug*> allBugs;

	int w, h;
	int* wPtr = &w, * hPtr = &h;
	int gridSize;

	std::vector<sf::RectangleShape> boardSquares;

	int currentId;


public:
	Board(int w, int h, int gridSize);

	void draw(sf::RenderWindow& win);

	void updateBugs();
	void drawBugs(sf::RenderWindow& win);
	void removeDeadBugs();
	void moveBugs();

	void drawBoard(sf::RenderWindow& win);

	Bug* getBugById(const unsigned int& id);
	std::string getBugInfoById(const unsigned int& id);

	bool checkClicked(const unsigned int& mx, const unsigned int& my, sf::Text& infoText, sf::Text& historyText);


	std::string getAllCellInfo();

	~Board();
};

