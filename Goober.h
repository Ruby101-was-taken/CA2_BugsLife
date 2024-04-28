#pragma once
#include "Bug.h"
class Goober : public Bug
{
public:
    using Bug::Bug;

    void move();
    void update();

    std::string getInfo();
};

