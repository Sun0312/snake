#ifndef _FOOD_H
#define _FOOD_H

#include "Objects.h"

class Food : public Objects{
    private:

        static int foodCnt;    // ScoreBoard에서 사용할 FoodCnt
    public:
        char symbol = 3;
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