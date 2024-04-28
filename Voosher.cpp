#include "Voosher.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>


//Voosher bug always goes up or down but randomly switches

void Voosher::update() {

}

void Voosher::move() {
    randomiseDirection();

    bool wayBlocked = isWayBlocked() or dir == east or dir == west;
    while (wayBlocked) {
        randomiseDirection();
        wayBlocked = isWayBlocked() or dir == east or dir == west;
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

std::string Voosher::getInfo() {
    return "Voosher: " + std::to_string(id) +
        "\nPosition: (" + std::to_string(position.first) + ", " + std::to_string(position.second) + ")" +
        "\nSize: " + std::to_string(size) +
        "\nDirection: " + dirToStr(dir) +
        "\nStatus: " + ((alive) ? "Alive" : "Dead -> Killed by " + std::to_string(murderer));
}

