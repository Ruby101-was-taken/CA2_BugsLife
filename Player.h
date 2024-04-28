#pragma once
#include "Bug.h"
class Player : public Bug {

public:
    using Bug::Bug;

    void move();
    void update();

    std::string getInfo();
};

