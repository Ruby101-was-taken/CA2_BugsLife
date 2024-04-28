#include "Board.h"

#include <vector>
#include "Bug.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "fileReader.h"
#include "shapeDefine.h"
#include "generalFunctions.h"

#include <iostream>


Board::Board(int w, int h, int gridSize) {
	this->w = w;
	this->h = h;
	this->gridSize = gridSize;

	wPtr = &this->w;
	hPtr = &this->h;

	allBugs = readBugFile(wPtr, hPtr);
    std::vector<Bug*>::iterator it;
    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        aliveBugs.push_back((*it));
    }

    player = new Player(100, 0, 5, 5, wPtr, hPtr, east);
    allBugs.push_back(player);
    aliveBugs.push_back(player);


    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            boardSquares.push_back(makeRect(x * gridSize, y * gridSize, gridSize, gridSize, Color::Green, 1));
        }
    }

    currentId = aliveBugs[0]->getId();
}

Bug* Board::getPlayer() {
    return player;
}

void Board::updateBugs() {
	std::vector<Bug*>::iterator it;
	for (it = aliveBugs.begin(); it != aliveBugs.end(); it++) {
		(*it)->update();
	}
}
void Board::drawBugs(sf::RenderWindow& win) {
	std::vector<Bug*>::iterator it;
	for (it = aliveBugs.begin(); it != aliveBugs.end(); it++) {
		sf::RectangleShape testBug = makeRect(0, 0, gridSize, gridSize, sf::Color(15 + ((*it)->getSize() * 12), 240 - ((*it)->getSize() * 12), 0), 3, ((*it)->getId() == 100) ? sf::Color::Yellow : sf::Color::White);
		updateRectPos(testBug, (*it)->getX() * gridSize, (*it)->getY() * gridSize);
		win.draw(testBug);
	}
}
void Board::removeDeadBugs() {
	std::vector<Bug*>::iterator it;
	for (it = aliveBugs.begin(); it != aliveBugs.end();) {
		if ((*it)->isAlive()) {
			it++;
		}
		else {
			it = aliveBugs.erase(it);
		}
	}
}

void Board::addPoints() {
    if (randInt(1, 30) == 15) {
        Point p(randInt(0, 9), randInt(0, 9));
        points[p.getPosStr()] = p;
    }
}


void Board::moveBugs() {
    std::vector<Bug*>::iterator it;
    std::vector<Bug*> movedBugs;

    std::map<std::string, std::vector<Bug*>> tileValues;

    for (it = aliveBugs.begin(); it != aliveBugs.end(); it++) {
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
                        biggestBug->die((*it)->getId());
                    biggestBug = (*it);
                }
                else {
                    (*it)->die(biggestBug->getId());
                }
            }

            biggestBug->grow(totalSize - biggestBug->getSize());
            if (points.count(biggestBug->getPosStr())) {
                biggestBug->grow(1);
                points.erase(biggestBug->getPosStr());
            }

        }
        else if (bugs.size() == 1) {
            if (points.count(bugs[0]->getPosStr())) {
                bugs[0]->grow(1);
                points.erase(bugs[0]->getPosStr());
            }
        }
    }


    addPoints();
}

void Board::drawPoints(sf::RenderWindow& win) {
    sf::RectangleShape prect = makeRect(0, 0, 20, 20, sf::Color::Yellow);
    for (auto p : points) {
        prect.setPosition((p.second.getX() * gridSize) + (gridSize / 2) - 10, (p.second.getY() * gridSize) + (gridSize / 2) - 10);
        win.draw(prect);
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
    drawPoints(win);
}

Bug* Board::getBugById(const unsigned int& id) {
    std::vector<Bug*>::iterator it;
    for (it = aliveBugs.begin(); it != aliveBugs.end(); it++) {
        if ((*it)->getId() == id) {
            return (*it);
        }
    }
    return nullptr;
}

std::string Board::getBugInfoById(const unsigned int& id) {
    Bug* bug = getBugById(id);
    if (bug != nullptr) {
        return bug->getInfo();
    }
    return "???";

}

bool Board::checkClicked(const unsigned int& mx, const unsigned int& my, sf::Text& infoText, sf::Text& historyText) {
    std::vector<Bug*>::iterator it;
    for (it = aliveBugs.begin(); it != aliveBugs.end(); it++) {
        if ((*it)->isClicked(mx, my)) {
            infoText.setString((*it)->getInfo());
            historyText.setString((*it)->getHistory());
            return true;
        }
    }

    return false;
}


Board::~Board() {
    writeBugFile(allBugs);
}

std::string Board::getAllCellInfo() {
    std::string returnString = "";

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            bool found = false;
            std::vector<Bug*>::iterator it;
            for (it = aliveBugs.begin(); it != aliveBugs.end(); it++) {
                if ((*it)->getX() == x and (*it)->getY() == y) {
                    returnString += "(" + std::to_string(x) + ", " + std::to_string(y) + "): " + (*it)->getInfo().substr(0, (*it)->getInfo().find("\n")) + "\n";
                    found = true;
                    break;
                }
            }
            if (not found) {
                returnString += "(" + std::to_string(x) + ", " + std::to_string(y) + "): empty\n";
            }
        }
    }
    return returnString;
}