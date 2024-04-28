#include "Hopper.h"
#include <iostream>

#include "generalFunctions.h"

Hopper::Hopper(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir, int hopSize) {
    this->id = id;
    this->position.first = x; this->position.second = y;
    this->size = size % 20; // the size may only be 1 - 20 so this prevents it goinf higher
    this->dir = dir;
    this->alive = true; // the bug should never start dead so this is always true


    if (this->hopSize < 2) {
        this->hopSize = 2;
    }

    this->boardW = w; this->boardH = h; // gives each bug a way of knowing the size of the board

    path.push_back(position);
}
Hopper::Hopper(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir) {
    this->id = id;
    this->position.first = x; this->position.second = y;
    this->size = size % 20; // the size may only be 1 - 20 so this prevents it goinf higher
    this->dir = dir;
    this->alive = true; // the bug should never start dead so this is always true


    this->hopSize = 1;

    this->boardW = w; this->boardH = h; // gives each bug a way of knowing the size of the board

    path.push_back(position);
}

void Hopper::update() {
}

void Hopper::move() {


    bool wayBlocked = isWayBlocked();
    while (wayBlocked) {
        randomiseDirection();
        wayBlocked = isWayBlocked();
    }

    int x = 0, y = 0;
    switch (dir) {
    case north:
        y = getY();
        if (changePos(y, -hopSize)) {
            setY(y);
            path.push_back(position);
        }
        break;
    case south:
        y = getY();
        if (changePos(y, hopSize)) {
            setY(y);
            path.push_back(position);
        }
        break;
    case east:
        x = getX();
        if (changePos(x, hopSize)) {
            setX(x);
            path.push_back(position);
        }
        break;
    case west:
        x = getX();
        if (changePos(x, -hopSize)) {
            setX(x);
            path.push_back(position);
        }
        break;
    }
    
}

std::string Hopper::getInfo() {
    return "Hopper: " + std::to_string(id) +
        "\nHop Size: " + std::to_string(hopSize) + 
        "\nPosition: (" + std::to_string(position.first) + ", " + std::to_string(position.second) + ")" +
        "\nSize: " + std::to_string(size) +
        "\nDirection: " + dirToStr(dir) +
        "\nStatus: " + ((alive) ? "Alive" : "Dead -> Killed by " + std::to_string(murderer));
}