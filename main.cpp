#include <iostream>

#include "Bug.h"
#include "direction.h"

#include "generalFunctions.h"

#include "Crawler.h"

#include <random>

#include <SFML/Graphics.hpp>

#include "shapeDefine.h"

using namespace std;

int w = 10, h = 10;

int gridSize = 48;


void moveBugs(vector<Bug> &allBugs) {
    vector<Bug>::iterator it;
    for (it = allBugs.begin(); it != allBugs.end(); it++) {
        it->move();
        cout << "X: " << it->getX() << " Y: " << it->getY() << " DIR: " << it->getDir() << endl;
    }
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


    srand(time(NULL));

    vector<Bug> allBugs;

    int* wPtr = &w, * hPtr = &h;

    Crawler bug(1, 5, 2, 1, wPtr, hPtr, north);


    allBugs.push_back(bug);

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
