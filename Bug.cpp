//
// Created by ruby_ on 20/03/2024.
//

#include "Bug.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>
#include <string>


Bug::Bug(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir) {
    this->id = id;
    this->position.first = x; this->position.second = y;
    this->size = size % 20; // the size may only be 1 - 20 so this prevents it goinf higher
    this->dir = dir;
    this->alive = true; // the bug should never start dead so this is always true

    this->boardW = w; this->boardH = h; // gives each bug a way of knowing the size of the board

    path.push_back(position);
}
Bug::Bug() {
    this->id = 1;
    this->position.first = 0; this->position.second = 0;
    this->size = 1 % 20; // the size may only be 1 - 20 so this prevents it goinf higher
    this->dir = south;
    this->alive = true; // the bug should never start dead so this is always true

    this->boardW = 0; this->boardH = 0; // gives each bug a way of knowing the size of the board

}

unsigned int Bug::getId() const {
    return id;
}

int Bug::getX()  {
    return position.first;
}
int Bug::getY()  {
    return position.second;
}

void Bug::setX(const unsigned int x) {
    position.first = x;
}
void Bug::setY(const unsigned int y) {
    position.second = y;
}
std::pair<int, int> Bug::getPos() {
    return position;
}

std::list<std::pair<int, int>> Bug::getPath() {
    return path;
}


direction Bug::getDir() const {
    return dir;
}
void Bug::setDir(direction d) { dir = d; }

unsigned int Bug::getSize() const {
    return size;
}
void Bug::grow(unsigned int by) {
    size += by;
}

bool Bug::isAlive() const {
    return alive;
}
void Bug::die(int murderer) {
    alive = false;
    this->murderer = murderer;
}

const std::list<std::pair<int, int>>& Bug::getPath() const {
    return path;
}

bool Bug::isWayBlocked() {
    switch (dir) {
        case north:
            return getY() - 1 < 0;
        case south:
            return getY() + 1 >= *boardH;
        case east:
            return getX() + 1 >= *boardW;
        case west:
            return getX() - 1 < 0;
    }
}

void Bug::randomiseDirection() {
    int random = randInt(1, 4);

    this->dir = intToDir(random);
}

bool Bug::changePos(int& z, int by, const int limit) {



    if (not isWayBlocked()) {
        z += by;

        if (z < 0) {
            z = 0;
        }
        else if (z >= limit) {
            z = limit - 1;
        }

        return true;
    }

}

std::string Bug::getPosStr() {
    return std::to_string(getX()) + ", " + std::to_string(getY());
}


bool Bug::isClicked(int mx, int my) {
    int x = position.first * 48;
    int y = position.second * 48;
    return mx >= x and mx <= x + 48 and my >= y and my <= y + 48;
}

std::string Bug::getHistory() {
    std::string returnString = std::to_string(id) + "'s history" + ((path.size() > 15) ? "\n(Scroll): \n" : ":\n");
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        returnString += std::to_string(it->first) + ", " + std::to_string(it->second) + "\n";
    }
    return returnString;
}