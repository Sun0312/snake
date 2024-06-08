#include "Wall.h"

Wall::Wall(){}

Wall::Wall(int r , int c,bool im = false):Objects(r,c,'█'){
    immune = im;
} 

Wall::~Wall(){}

bool Wall::isImmune(){
    return immune;
}

