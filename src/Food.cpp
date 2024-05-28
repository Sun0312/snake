
#include "Food.h"

//INIT
Poison::Poison(){}

Poison::Poison(int r, int c):Objects(r, c){
    foodCnt = 0;
}


//GETTER

int Poison::getFoodCnt(){
    return foodCnt;
}

void Poison::incFoodCnt(){
    foodCnt++;
}


