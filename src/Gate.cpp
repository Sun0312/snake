
#include "Gate.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Gate::Gate() {
    this->gateCnt = 0;
}
Gate::Gate(int* map) {
    this->gateCnt = 0;

    int rowLength = *map.size();
    int columnLength = *map[0].size();

    int r = this->genRand(rowLength);
    int c = this->genRand(columnLength);

    if (r == 0) { // gate created in upper wall
        this->outDirection = 'd';
    } else if (c == 0) { // gate created in left wall
        this->outDirection = 'r';
    }
}

char Gate::getOutDir() {
    return this->outDirection;
}
int Gate::getGateCnt() {
    return this->gateCnt;
}

int Gate::genRand(int maxLength) {
    srand(time(0));

    int randNum = 0 + rand() % (maxLength + 1);

    return randNum;
}