#ifndef _FOOD_H
#define _FOOD_H

#include "Objects.h"

class Food : public Objects{
    private:

        int foodCnt;    // ScoreBoard에서 사용할 FoodCnt
    public:
        //init
        Food();
        Food(int r, int c);

        //getter
        int getFoodCnt();

        //setter
        //foodCnt를 하나 늘림
        void incFoodCnt();  

};









#endif