#ifndef _SCORE_H
#define _SCORE_H
#include "Snake.h"
#include "Food.h"
#include "Poison.h"
#include <ncurses.h>
#include "Board.h"
#include "Gate.h"
using namespace std;


class Score : public Board {
private:
    int snakecount;
    int poisoncount;
    int gatecount;
    int foodcount;
    int ScoreWin;
    const int maxlength=10;
public:
    Score();
    Score(int width,int height,int br,int bc);
    void updateScore( Snake& snake, Food& food, Poison& poison,  Gate& gate);
    void displayScore() const;
    
    int getSnake();
    int getPoison();
    int getGate();
    int getFood();
};


#endif


