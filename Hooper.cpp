#include "Hooper.h"
#include <iostream>

#include "generalFunctions.h"

//hooper is a hopper but it picks a random hop length

void Hooper::update() {
    hopSize = randInt(1, 5);
}

std::string Hooper::getInfo() {
    return "Hooper: " + std::to_string(id) +
        "\nPosition: (" + std::to_string(position.first) + ", " + std::to_string(position.second) + ")" +
        "\nSize: " + std::to_string(size) +
        "\nDirection: " + dirToStr(dir) +
        "\nStatus: " + ((alive) ? "Alive" : "Dead -> Killed by " + std::to_string(murderer));
}