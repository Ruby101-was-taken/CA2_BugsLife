#include <iostream>

#include "Bug.h"
#include "direction.h"

#include "generalFunctions.h"

#include "Craweler.h"

#include <random>


using namespace std;

int w = 10, h = 10;

int main() {

    srand(time(NULL));

    cout << north << endl;

    int *wPtr = &w, *hPtr = &h;

    Craweler bug(1, 1, 1, 1, wPtr, hPtr, north);

    cout << bug.getX() << endl;

    bug.move();

    cout << bug.getX() << endl;


    return 0;
}
