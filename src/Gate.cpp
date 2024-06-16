
#include "Gate.h"
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int Gate::gateCnt = 0;
Gate::Gate():Objects(0, 0, symbol = '5') {}
Gate::Gate(vector<vector<char>> &map):Objects(0, 0, symbol = '5') {
   

    
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

void Gate::setOutDir(vector<vector<char>>* grid, char inDir) {

    if (pos.row == 0) { // gate created in upper wall
        this->outDirection = 'd';
    } else if (pos.row == (*grid).size()) { // gate in bottom wall
        this->outDirection = 'u';
    } else if (pos.col == 0) { // gate created in left wall
        this->outDirection = 'r';
    } else if (pos.col == (*grid)[0].size()) { // gate in right wall
        this->outDirection = 'l';
    } else { // gate not in wall

        // if out direction is not a wall;
        if (inDir == 'r' && (*grid)[pos.row + 1][pos.col] != '1') {
            this->outDirection = 'r';
        } else if (inDir == 'l' && (*grid)[pos.row - 1][pos.col] != '1') {
            this->outDirection = 'l';
        } else if (inDir == 'u' && (*grid)[pos.row][pos.col - 1] != '1') {
            this->outDirection = 'u';
        } else if (inDir == 'd' && (*grid)[pos.row][pos.col + 1] != '1') {
            this->outDirection = 'd';
        }
        // if out direction is a wall, check clockwise

    }
}