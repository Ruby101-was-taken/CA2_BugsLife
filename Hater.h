#pragma once
#include "Bug.h"
class Hater : public Bug {
    Bug* player;
public:
    Hater(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir = north, Bug* player = nullptr);

    void move();
    void update();

    std::string getInfo();
};

