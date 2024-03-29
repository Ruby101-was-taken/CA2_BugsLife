#include <iostream>

#include "Bug.h"
#include "direction.h"

#include "generalFunctions.h"

#include "Crawler.h"

#include <random>

using namespace std;

int w = 10, h = 10;

int main() {

    srand(time(NULL));

    int* wPtr = &w, * hPtr = &h;

    Crawler bug(1, 1, 1, 1, wPtr, hPtr, north);

    cout << bug.getX() << "-" <<  bug.getY() << "-" << bug.getDir() << endl;

    bug.move();

    cout << bug.getX() << "-" << bug.getY() << "-" << bug.getDir() << endl;

    cout << bug.getY() - 1 << endl;


    for (int i = 0;i < 100;i++) {
        bug.move();
        cout << bug.getX() << "-" << bug.getY() << "-" << bug.getDir() << endl;
    }

    




    return 0;
}
