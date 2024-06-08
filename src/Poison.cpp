
#include "Poison.h"

//INIT
Poison::Poison(){}

Poison::Poison(int r, int c):Objects(r, c, symbol){ //symbol임시 설정
    poisonCnt = 0;
}


//GETTER

int Poison::getPoisonCnt(){
    return poisonCnt;
}

void Poison::incPoisonCnt(){
    poisonCnt++;
}

