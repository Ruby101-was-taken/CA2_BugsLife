#include <iostream>

#include "Bug.h"
#include "direction.h"

#include "generalFunctions.h"

#include "Board.h"

#include "Crawler.h"
#include "Hopper.h"

#include <random>

#include <SFML/Graphics.hpp>

#include "shapeDefine.h"

#include "fileReader.h"

using namespace std;

int w = 10, h = 10;

int gridSize = 48;


int main() {
    int* wPtr = &w, * hPtr = &h;

    Board board(w, h, gridSize);


    srand(time(NULL));

    sf::RenderWindow win(sf::VideoMode(853, 480), "Bugs Life!");

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
            if (event.type == Event::MouseButtonPressed) { 
                board.moveBugs();

                board.removeDeadBugs();
            }
        }


        board.updateBugs();
        

        win.clear();

        

        board.draw(win);

        win.display();
    }

    return 0;
}
