#include "Hopper.h"

Hopper::Hopper(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir) {
    this->id = id;
    this->position.first = x; this->position.second = y;
    this->size = size % 20; // the size may only be 1 - 20 so this prevents it goinf higher
    this->dir = dir;
    this->alive = true; // the bug should never start dead so this is always true

    this->boardW = w; this->boardH = h; // gives each bug a way of knowing the size of the board

}

void Hopper::move() {
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