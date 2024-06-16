
#include "Poison.h"

int Poison::poisonCnt = 0;
//INIT
Poison::Poison():Objects(0, 0, symbol = '4'){}

Poison::Poison(int r, int c):Objects(r, c, symbol = '4'){ //symbol임시 설정
    
}


//GETTER

int Poison::getPoisonCnt(){
    return poisonCnt;
}

void Poison::incPoisonCnt(){
    poisonCnt++;
}

