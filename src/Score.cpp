#include <ncurses.h>
#include "Score.h"

Score::Score() : snakecount(3), foodcount(0), poisoncount(0),gatecount(0) {}

Score::Score(int width,int height,int br,int bc): Board(width,height,br,bc),snakecount(3), foodcount(0), poisoncount(0),gatecount(0) {};

void Score::updateScore(Snake &snake, Food&food, Poison& poison, Gate&gate1, Gate&gate2) {
        snakecount=snake.getLength();
        foodcount= food.getFoodCnt();
        poisoncount= poison.getPoisonCnt();
        gatecount= gate1.getGateCnt() + gate2.getGateCnt();
}
    

int Score::getFood(){return foodcount;}
int Score::getSnake(){return snakecount;}
int Score::getPoison(){return poisoncount;}
int Score::getGate(){return gatecount;}



/*void Score::display(WINDOW* win) 
    werase(win);  
    box(win, 0, 0);  

   
    mvwprintw(win, 1, 1, "Score Board");
    mvwprintw(win, 2, 1, "B: %d/%d", currentLength,maxlength);
    mvwprintw(win, 3, 1, "+: %d", foodCount);
    mvwprintw(win, 4, 1, "-: %d", poisonCount);
    mvwprintw(win, 5, 1, "G: %d", gateCount);

    wrefresh(win);
};*/
// test//

/*
game.cpp
class Game{
    private:
    Score score;
    Snake snake;
    Food food;
    Poison poison;
    WINDOW *scoreWin;

    public:
    Game() {
        initscr();
        noecho();
        cbreak();
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLUE);

        scoreWin = newwin(10, 30, 1, 52);  // 점수판 윈도우 생성
    }

    ~Game() {
        endwin();
    }

    void run(){
        while(true){
            score.updateLength(snake.getLength());
            score.updatefoodCount(food.getfoodCount());
            score.updatepoisonCount(poison.getpoisonCount());
            score,updategateCount(gate.getgateCount());


            
            score.display(scoreWin);
        }
    }
}*/