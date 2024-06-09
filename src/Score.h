/*
    현재 스코어를 띄워줄 WINDOW객체를 관리하는
    Score클래스입니다.

*/


#define SCORE_H
#include "Snake.h"
#include "Food.h"
#include "Game.h"
#include "Poison.h"
#include <ncurses.h>
using namespace std;


class Score {
    private:
    int currentLength;
    int foodCount;
    int poisonCount;
    int gateCount;
    int maxlength=100;
    public:
    Score(); 

    void updateLenght(int length){
        currentLength = length;
    }
    void updatefoodcount(int count){
        foodCount = count;
    }
    void updatepoisoncount(int count){
        poisonCount = count;
    }
    void updategatecount(int count){
        gateCount = count;
    }

    int getSnakeLength() const {
        return currentLength;
    }
    int getFoodCount() const {
        return foodCount;
    }
    int getPoisonCount() const {
        return poisonCount;
    }  
    int getGateCount() const{
        return gateCount;
    }
    
    //test
};
