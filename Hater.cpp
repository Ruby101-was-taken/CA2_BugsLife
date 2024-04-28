#include "Hater.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>



Hater::Hater(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir, Bug* player) {
    this->id = id;
    this->position.first = x; this->position.second = y;
    this->size = size % 20; // the size may only be 1 - 20 so this prevents it goinf higher
    this->dir = dir;
    this->alive = true; // the bug should never start dead so this is always true

    this->boardW = w; this->boardH = h; // gives each bug a way of knowing the size of the board

    path.push_back(position);

    this->player = player;
}

void Hater::update(){}

void Hater::move() {

    if (player->isAlive()) {
        if (player->getX() > position.first) {
            setDir(east);
        }
        else if (player->getX() < position.first) {
            setDir(west);
        }
        else if (player->getY() < position.second) {
            setDir(north);
        }
        else if (player->getY() > position.second) {
            setDir(south);
        }
    }


    else {
        randomiseDirection();
        bool wayBlocked = isWayBlocked();
        while (wayBlocked) {
            randomiseDirection();
            wayBlocked = isWayBlocked();
        }
    }

    int x = 0, y = 0;
    switch (dir) {
    case north:
        y = getY();
        if (changePos(y, -1)) {
            setY(y);
            path.push_back(position);
        }
        break;
    case south:
        y = getY();
        if (changePos(y, 1)) {
            setY(y);
            path.push_back(position);
        }
        break;
    case east:
        x = getX();
        if (changePos(x, 1)) {
            setX(x);
            path.push_back(position);
        }
        break;
    case west:
        x = getX();
        if (changePos(x, -1)) {
            setX(x);
            path.push_back(position);
        }
        break;
    }
}


std::string Hater::getInfo() {
    return "Hater: " + std::to_string(id) +
        "\nPosition: (" + std::to_string(position.first) + ", " + std::to_string(position.second) + ")" +
        "\nSize: " + std::to_string(size) +
        "\nDirection: " + dirToStr(dir) +
        "\nStatus: " + ((alive) ? "Alive" : "Dead -> Killed by " + std::to_string(murderer));
}