//
// Created by ruby_ on 20/03/2024.
//

#include "Crawler.h"
#include "direction.h"
#include "generalFunctions.h"

#include <iostream>



bool Bug::changePos(int& z, int by) {
    if (not isWayBlocked()) {
        z += by;
        return true;
    }
    else {
        bool canMove = false;

        while (not canMove) {
            int rand = randInt(1, 4);

            direction dirBefore = getDir();

            switch (rand) {
                case 1:
                    setDir((dirBefore != north)? north : south);
                    if (isWayBlocked())
                        setDir(south);
                    break;
                case 2:
                    setDir((dirBefore != east) ? east : west);
                    if (isWayBlocked())
                        setDir(west);
                    break;
                case 3:
                    setDir((dirBefore != south) ? south : north);
                    if (isWayBlocked())
                        setDir(north);
                    break;
                case 4:
                    setDir((dirBefore != west) ? west : east);
                    if (isWayBlocked())
                        setDir(east);
                    break;
                default: //if it ever gets to here then something went... very very wrong
                    setDir(north);
            }


            canMove = not isWayBlocked();


        }
        move();


        return false;
    }

    
}

void Bug::move() {
    int x = 0, y = 0;
    switch (getDir()) {
        case north:
            y = getY();
            if(changePos(y, -1))
                setY(y);
            break;
        case south:
            y = getY();
            if (changePos(y, 1))
                setY(y);
            break;
        case east:
            x = getX();
            changePos(x, 1);
            setX(x);
            break;
        case west:
            x = getX();
            changePos(x, -1);
            setX(x);
            break;
    }
}