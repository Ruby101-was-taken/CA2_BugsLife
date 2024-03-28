//
// Created by ruby_ on 20/03/2024.
//

#include "Craweler.h"
#include "direction.h"

void Bug::move() {
    switch(getDir()){
        case north:
            if(not isWayBlocked()) {
                setY(getY() - 1); //north is considered to be 0, therefor we minus 1 rather than add one
            }
            else {
                bool canMove = false;

                while(not canMove) {

                }
            }
            break;
    }
}