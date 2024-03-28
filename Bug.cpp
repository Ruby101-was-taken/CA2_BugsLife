//
// Created by ruby_ on 20/03/2024.
//

#include "Bug.h"
#include "direction.h"


Bug::Bug(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir) {
    this->id = id;
    this->position.first = x; this->position.second = y;
    this->size = size % 20; // the size may only be 1 - 20 so this prevents it goinf higher
    this->dir = dir;
    this->alive = true; // the bug should never start dead so this is always true

    this->boardW = w; this->boardH = h; // gives each bug a way of knowing the size of the board
}

unsigned int Bug::getId() const {
    return id;
}

unsigned int Bug::getX() const {
    return position.first;
}
unsigned int Bug::getY() const {
    return position.second;
}

void Bug::setX(const unsigned int x){
    position.first = x;
}
void Bug::setY(const unsigned int y){
    position.second = y;
}

direction Bug::getDir() const {
    return dir;
}

unsigned int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

const std::list<std::pair<int, int>> &Bug::getPath() const {
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
            return getX() - 1 >= 0;
    }
}

