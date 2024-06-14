
#include "Gate.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int Gate::gateCnt = 0;
Gate::Gate() {
    
}
Gate::Gate(vector<vector<char>> &map) {
   

    int rowLength = map.size();
    int columnLength = map[0].size();

    int r = 0;
    int c = 0;

    // regenerate gate position until it is not in an immune wall
    while (r != c && r != rowLength && c != columnLength) { 
        r = this->genRand(rowLength);
        c = this->genRand(columnLength);
    }

    if (r == 0) { // gate created in upper wall
        this->outDirection = 'd';
    } else if (r == rowLength) { // gate in bottom wall
        this->outDirection = 'u';
    } else if (c == 0) { // gate created in left wall
        this->outDirection = 'r';
    } else if (c == columnLength) { // gate in right wall
        this->outDirection = 'l';
    } else { // gate not in wall

    }

    map[r][c] = 5;
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
void Gate::increaseGateCnt() {
    gateCnt++;
}