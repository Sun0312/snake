#ifndef _POISON_H
#define _POISON_H

#include "Objects.h"

class Poison : public Objects{
    private:

        static int poisonCnt;    // ScoreBoard에서 사용할 FoodCnt
    public:
        char symbol = 4;
        //init
        Poison();
        Poison(int r, int c);

        //getter
        int getPoisonCnt();

        //setter
        //poisonCnt를 하나 늘림
        void incPoisonCnt();  

};


#endif