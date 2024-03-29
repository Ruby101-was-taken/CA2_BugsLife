//
// Created by ruby_ on 20/03/2024.
//

#include "Crawler.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>



void Bug::changePos(int* z, int by) {
    if (not isWayBlocked()) {
        *z += by;
    }
    else {
        bool canMove = false;

        while (not canMove) {
            int rand = randInt(1, 4);

            switch (rand) {
                case 1:
                    setDir(north);
                    break;
                case 2: 
                    setDir(east);
                    break;
                case 3:
                    setDir(south);
                    break;
                case 4:
                    setDir(west);
                    break;
                default: //if it ever gets to here then something went... very very wrong
                    setDir(north);
            }


            canMove = not isWayBlocked();


        }
        move();
    }

    
}

void Bug::move() {
    int x = 0, y = 0;
    switch (getDir()) {
        case north:
            y = getY();
            changePos(&y, -1);
            setY(y);
            break;
        case south:
            y = getY();
            changePos(&y, 1);
            setY(y);
            break;
        case east:
            x = getX();
            changePos(&x, 1);
            setX(x);
            break;
        case west:
            x = getX();
            changePos(&x, -1);
            setX(x);
            break;
    }
}