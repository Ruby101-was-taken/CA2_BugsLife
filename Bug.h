//
// Created by ruby_ on 20/03/2024.
//

#ifndef CA2_BUGSLIFE_BUG_H
#define CA2_BUGSLIFE_BUG_H

#include <utility>
#include <list>
#include "direction.h"


class Bug {
    unsigned int id;
    std::pair<int, int> position;
    direction dir;
    unsigned int size;
    bool alive;
    std::list<std::pair<int, int>> path;
    const int* boardW;
    const int* boardH;

public:

    Bug(unsigned int id, unsigned int x, unsigned int y, unsigned int size, int* w, int* h, direction dir = north);

    unsigned int getId() const;


    int getX() const;
    int getY() const;

    void setX(const unsigned int x);
    void setY(const unsigned int y);

    direction getDir() const;
    void setDir(direction d);

    unsigned int getSize() const;

    bool isAlive() const;

    const std::list<std::pair<int, int>>& getPath() const;

    virtual void move();
    virtual void changePos(int* z, int by);

    bool isWayBlocked();

};


#endif //CA2_BUGSLIFE_BUG_H