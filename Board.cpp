#include "Board.h"

#include <vector>
#include "Bug.h"
#include <SFML/Graphics.hpp>
#include "fileReader.h"
#include "shapeDefine.h"


Board::Board(int w, int h, int gridSize) {
	this->w = w;
	this->h = h;
	this->gridSize = gridSize;

	wPtr = &this->w;
	hPtr = &this->h;

	allBugs = readBugFile(wPtr, hPtr);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            boardSquares.push_back(makeRect(x * gridSize, y * gridSize, gridSize, gridSize, sf::Color((x * (255 / w)) % 255, 0, (y * (255 / h)) % 255)));
        }
    }
}

void Board::updateBugs() {
	std::vector<Bug*>::iterator it;
	for (it = allBugs.begin(); it != allBugs.end(); it++) {
		(*it)->update();
	}
}
void Board::drawBugs(sf::RenderWindow& win) {
	std::vector<Bug*>::iterator it;
	for (it = allBugs.begin(); it != allBugs.end(); it++) {
		sf::RectangleShape testBug = makeRect(0, 0, gridSize, gridSize, sf::Color(15 + ((*it)->getSize() * 12), 240 - ((*it)->getSize() * 12), 0));
		updateRectPos(testBug, (*it)->getX() * gridSize, (*it)->getY() * gridSize);
		win.draw(testBug);
	}
}
void Board::removeDeadBugs() {
	std::vector<Bug*>::iterator it;
	for (it = allBugs.begin(); it != allBugs.end();) {
		if ((*it)->isAlive()) {
			it++;
		}
		else {
			it = allBugs.erase(it);
		}
	}
}
void Board::moveBugs() {
    std::vector<Bug*>::iterator it;
    std::vector<Bug*> movedBugs;

    std::map<std::string, std::vector<Bug*>> tileValues;

    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        (*it)->move();
        std::string bugPos = (*it)->getPosStr();
        tileValues[bugPos].push_back((*it));
    }

    for (auto mit = tileValues.begin(); mit != tileValues.end(); mit++) {
        std::vector<Bug*>& bugs = mit->second;
        if (bugs.size() > 1) {
            int totalSize = 0;
            int biggestSize = 0;
            Bug* biggestBug = nullptr;

            std::vector<Bug*>::iterator it;
            for (it = bugs.begin(); it != bugs.end(); it++) {
                totalSize += (*it)->getSize();
                if ((*it)->getSize() > biggestSize) {
                    if (biggestBug != nullptr)
                        biggestBug->die();
                    biggestBug = (*it);
                }
                else {
                    (*it)->die();
                }
            }

            biggestBug->grow(totalSize - biggestBug->getSize());
        }
    }
}

void Board::drawBoard(sf::RenderWindow& win) {
    for (sf::RectangleShape r : boardSquares) {
        win.draw(r);
    }
}


void Board::draw(sf::RenderWindow& win) {
    drawBoard(win);
    drawBugs(win);
}