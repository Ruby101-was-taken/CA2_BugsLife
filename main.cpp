#include <iostream>

#include "Bug.h"
#include "direction.h"

#include "generalFunctions.h"

#include "Crawler.h"

#include <random>

#include <SFML/Graphics.hpp>

#include "shapeDefine.h"

#include "fileReader.h"

using namespace std;

int w = 10, h = 10;

int gridSize = 48;


void moveBugs(vector<Bug> &allBugs) {
    vector<Bug>::iterator it;
    //cout << "=====" << endl;
    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        //cout << it->getId() << "----" << endl;
        it->move();
        //cout << "X: " << it->getX() << " Y: " << it->getY() << " DIR: " << it->getDir() << endl;
    }
    //cout << "=====" << endl;
}

void drawBugs(vector<Bug>& allBugs, sf::RenderWindow &win) {
    sf::RectangleShape testBug = makeRect(0, 0, gridSize, gridSize, sf::Color::Green);
    vector<Bug>::iterator it;
    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        updateRectPos(testBug, it->getX() * gridSize, it->getY() * gridSize);
        win.draw(testBug);
    }
}

int main() {
    int* wPtr = &w, * hPtr = &h;

    vector<Bug> allBugs = readBugFile(wPtr, hPtr);

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
            }
        }

        

        win.clear();

        win.draw(board);

        drawBugs(allBugs, win);

        win.display();
    }

    return 0;
}
