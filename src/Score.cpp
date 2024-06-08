#include <ncurses.h>
#include "Score.h"

class Score{
    Score::Score() : currentLength(0), foodCount(0), poisonCount(0) {}


void Score::updateLength(int length) {
    currentLength = length;
}


void Score::updatefoodCount(int count) {
    foodCount = count;
}


void Score::updatepoisonCount(int count) {
    poisonCount = count;
}


void Score::display(WINDOW* win) 
    werase(win);  
    box(win, 0, 0);  

   
    mvwprintw(win, 1, 1, "Score Board");
    mvwprintw(win, 2, 1, "B: %d/%d", currentLength,maxlength);
    mvwprintw(win, 3, 1, "+: %d", foodCount);
    mvwprintw(win, 4, 1, "-: %d", poisonCount);
    mvwprintw(win, 5, 1, "G: %d", gateCount);

    wrefresh(win);
};
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