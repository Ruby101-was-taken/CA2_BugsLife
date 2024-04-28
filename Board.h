#pragma once

#include <vector>
#include "Bug.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

#include "Point.h"

#include <string>
#include <map>

class Board
{
	std::vector<Bug*> aliveBugs;
	std::vector<Bug*> allBugs;

	int w, h;
	int* wPtr = &w, * hPtr = &h;
	int gridSize;

	std::vector<sf::RectangleShape> boardSquares;

	int currentId;

	Bug* player;

	std::map<std::string, Point> points;


public:
	Board(int w, int h, int gridSize);

	void draw(sf::RenderWindow& win);

	Bug* getPlayer();

	void addPoints();

	void updateBugs();
	void drawBugs(sf::RenderWindow& win);
	void removeDeadBugs();
	void moveBugs();

	void drawBoard(sf::RenderWindow& win);
	void drawPoints(sf::RenderWindow& win);

	Bug* getBugById(const unsigned int& id);
	std::string getBugInfoById(const unsigned int& id);

	bool checkClicked(const unsigned int& mx, const unsigned int& my, sf::Text& infoText, sf::Text& historyText);


	std::string getAllCellInfo();

	~Board();
};

