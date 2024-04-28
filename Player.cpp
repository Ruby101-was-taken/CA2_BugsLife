#include "Player.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>

void Player::update() {

}

void Player::move() {

    if (not isWayBlocked()) {
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
}

std::string Player::getInfo() {
    return "Player(You): " + std::to_string(id) +
        "\nPosition: (" + std::to_string(position.first) + ", " + std::to_string(position.second) + ")" +
        "\nSize: " + std::to_string(size) +
        "\nDirection: " + dirToStr(dir) +
        "\nStatus: " + ((alive) ? "Alive" : "Dead -> Killed by " + std::to_string(murderer));
}
