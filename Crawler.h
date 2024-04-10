//
// Created by ruby_ on 20/03/2024.
//

#ifndef CA2_BUGSLIFE_CRAWELER_H
#define CA2_BUGSLIFE_CRAWELER_H

#include "Bug.h"

class Crawler : public  Bug {

public:
    using Bug::Bug;

    void move();

};


#endif //CA2_BUGSLIFE_CRAWELER_H
