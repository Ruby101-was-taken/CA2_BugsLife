//
// Created by ruby_ on 20/03/2024.
//

#include "Crawler.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>





void Bug::move() {
    int x = 0, y = 0;
    switch (getDir()) {
        case north:
            y = getY();
            if (changePos(y, -1)) {
                setY(y);
                path.push_back(getPos());
            }
            break;
        case south:
            y = getY();
            if (changePos(y, 1)) {
                setY(y);
                path.push_back(getPos());
            }
            break;
        case east:
            x = getX();
            if (changePos(x, 1)) {
                setX(x);
                path.push_back(getPos());
            }
            break;
        case west:
            x = getX();
            if (changePos(x, -1)) {
                setX(x);
                path.push_back(getPos());
            }
            break;
    }
}