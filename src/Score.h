
#define SCORE_H
#include "Snake.h"
#include "Food.h"
#include "Game.h"
#include "Poison.h"
#include <ncurses.h>
#include "Board.h"
using namespace std;


class Score : public Board {
private:
    int snakecount;
    int posioncount;
    int gatecount;
    int foodcount;
    int ScoreWin;
    int maxlength=10;
public:
    Score();
    void updateScore(const Snake& snake,const Poison& poison,const Food& food,const Gate& gate);
    Score(int width,int height,int br,int bc);
    void displayScore() const;



