
#include "Food.h"

//INIT
Food::Food(){}

Food::Food(int r, int c):Objects(r, c, symbol){ //temp symbol
    foodCnt = 0;
}
//GETTER

int Food::getFoodCnt(){
    return foodCnt;
}

void Food::incFoodCnt(){
    foodCnt++;
}


