#pragma once
#include "Hopper.h"
class Hooper : public Hopper{
public:
    using Hopper::Hopper;

    void update();

    std::string getInfo();
};

