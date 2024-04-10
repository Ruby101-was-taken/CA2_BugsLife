#include <iostream>

#include "Bug.h"
#include "direction.h"

#include "generalFunctions.h"

#include "Crawler.h"
#include "Hopper.h"

#include <random>

#include <SFML/Graphics.hpp>

#include "shapeDefine.h"

#include "fileReader.h"

using namespace std;

int w = 10, h = 10;

int gridSize = 48;




void moveBugs(vector<Bug*> &allBugs) {
    vector<Bug*>::iterator it;
    vector<Bug*> movedBugs;
    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        (*it)->move();

        pair<int, int> curPos = (*it)->getPos();
        bool found = false;
        vector<Bug*>::const_iterator pit;
        for (pit = movedBugs.begin(); pit != movedBugs.end(); pit++) {
            if ((*pit)->getPos() == curPos) {
                if ((*pit)->getSize() >= (*it)->getSize())
                    (*it)->die();
                else if ((*pit)->getSize() < (*it)->getSize()) {
                    (*pit)->die();
                    pit = movedBugs.erase(pit);
                    pit--;
                }
                else
                    found = true;
            }
        }
        
        if (not found) {
            movedBugs.push_back(*it);
        }
    }
}


void removeDeadBugs(vector<Bug*>& allBugs) {
    vector<Bug*>::iterator it;
    for (it = allBugs.begin(); it != allBugs.end();) {
        if ((*it)->isAlive()) {
            it++; 
        }
        else {
            it = allBugs.erase(it);
        }
    }
}


void drawBugs(vector<Bug*>& allBugs, sf::RenderWindow &win) {
    vector<Bug*>::iterator it;
    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        sf::RectangleShape testBug = makeRect(0, 0, gridSize, gridSize, sf::Color(15+((*it)->getSize()*12), 240-((*it)->getSize() * 12), 0));
        updateRectPos(testBug, (*it)->getX() * gridSize, (*it)->getY() * gridSize);
        win.draw(testBug);
    }
}

void updateBugs(vector<Bug*>& allBugs) {
    vector<Bug*>::iterator it;
    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        (*it)->update();
    }
}

int main() {
    int* wPtr = &w, * hPtr = &h;

    vector<sf::RectangleShape> boardSquares;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            boardSquares.push_back(makeRect(x * gridSize, y * gridSize, gridSize, gridSize, sf::Color((x * (255/w)) % 255, 0, (y * (255 / h)) % 255)));
        }
    }


    vector<Bug*> allBugs = readBugFile(wPtr, hPtr);

    srand(time(NULL));

    sf::RectangleShape board = makeRect(0, 0, 480, 480, sf::Color(10, 100, 0));
        
    sf::RenderWindow win(sf::VideoMode(853, 480), "Bugs Life!");

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
            if (event.type == Event::MouseButtonPressed) { 
                moveBugs(allBugs);

                removeDeadBugs(allBugs);
            }
        }


        updateBugs(allBugs);
        

        win.clear();

        win.draw(board);

        for (sf::RectangleShape r : boardSquares) {
            win.draw(r);
        }

        drawBugs(allBugs, win);

        win.display();
    }

    return 0;
}
