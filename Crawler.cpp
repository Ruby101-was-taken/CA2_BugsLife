//
// Created by ruby_ on 20/03/2024.
//

#include "Crawler.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>

void Crawler::update() {

}

void Crawler::move() {

    bool wayBlocked = isWayBlocked();
    while (wayBlocked) {
        randomiseDirection();
        wayBlocked = isWayBlocked();
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

std::string Crawler::getInfo() {
    return "Crawler: " + std::to_string(id) + 
        "\nPosition: (" + std::to_string(position.first) + ", " + std::to_string(position.second) + ")" + 
        "\nSize: " + std::to_string(size) + 
        "\nDirection: " + dirToStr(dir) + 
        "\nStatus: " + ((alive) ? "Alive" : "Dead -> Killed by " + std::to_string(murderer));
}