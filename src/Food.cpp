
#include "Food.h"

int Food::foodCnt = 0;
//INIT
Food::Food():Objects(0, 0, symbol){}


Food::Food(int r, int c):Objects(r, c, symbol){ //temp symbol
    
}
//GETTER

int Food::getFoodCnt(){
    return foodCnt;
}

void Food::incFoodCnt(){
    foodCnt++;
}


