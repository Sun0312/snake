#include "Snake.h"

//SNAKEBODY
SnakeBody::SnakeBody(){};

SnakeBody::SnakeBody(int r, int c):Objects(r,c,symbol = '6'){ 
};

//SNAKE

Snake::Snake(int r, int c, char dir){
    this->dir = dir;
    snakes.emplace_back(SnakeBody(r, c+1)); //칸이 줄보다 작아서 2배수or3배수될듯...
    snakes.emplace_back(SnakeBody(r,c));
    snakes.emplace_front(SnakeBody(r,c+2));  //헤드

    // for debugging
   int t = 0;
   for (auto it = snakes.begin(); it != snakes.end(); ++it) {
        mvprintw(0+t, 100, "snake init snakeBody at %d: %c", it->pos.col, it->symbol);
        t++;
   }

}

Snake::~Snake(){};

    //SNAKE : GETTER

    int Snake::getLength(){
        return length;
    };

    char Snake::getDir(){
        return dir;
    }

    int Snake::getPosRow() {
        return snakes.front().pos.row;
    }
    int Snake::getPosCol() {
        return snakes.front().pos.col;
    }
    deque<Objects> Snake::getBody() {
        return snakes;
    }

    //SNAKE : SETTER

    void Snake::setDir(char dir){
        this->dir = dir;
    }

    // SNAKE : FUNCTIONS

    void Snake::move(char dir) {
        grow(dir);
        shrink();
    }

    void Snake::grow(char dir) {    //키보드입력 -> dir
        Position currentPos = snakes.front().pos;   //  현재 헤드위치
        Position newPos;
        if (dir == 'l') newPos = Position(currentPos.row, currentPos.col - 1);
        if (dir == 'r') newPos = Position(currentPos.row, currentPos.col + 1);
        if (dir == 'u') newPos = Position(currentPos.row - 1, currentPos.col);
        if (dir == 'd') newPos = Position(currentPos.row + 1, currentPos.col);

        snakes.emplace_front(SnakeBody(newPos.row, newPos.col));   //insert new snake body at the front     
        setDir(dir);
        length++;
    }
    void Snake::shrink() {
        snakes.pop_back();     //remove last body      
        length--;        
    }
    
    void Snake::setHeadPos(int r, int c){
        snakes.front().pos.row = r;
        snakes.front().pos.col = c;
    }