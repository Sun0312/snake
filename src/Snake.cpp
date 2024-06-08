#include "Snake.h"

//SNAKEBODY
SnakeBody::SnakeBody(){};

SnakeBody::SnakeBody(int r, int c):Objects(r,c,symbol){
    ;
};

//SNAKE

Snake::Snake(){};
Snake::Snake(int r, int c, char dir = 'r'){
    this->dir = dir;
    snakes.emplace_back(SnakeBody(r,c - 1*width)); //칸이 줄보다 작아서 2배수or3배수될듯...
    snakes.emplace_back(SnakeBody(r,c - 2*width));
    snakes.emplace_front(SnakeBody(r,c));  //헤드
}

Snake::~Snake(){};

    //SNAKE : GETTER

    int Snake::getLength(){
        return length;
    };

    char Snake::getDir(){
        return dir;
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
        if (dir == 'l') newPos = Position(currentPos.row, currentPos.col - width);
        if (dir == 'r') newPos = Position(currentPos.row, currentPos.col + width);
        if (dir == 'u') newPos = Position(currentPos.row - height, currentPos.col);
        if (dir == 'd') newPos = Position(currentPos.row + height, currentPos.col);

        snakes.emplace_front(SnakeBody(newPos.row, newPos.col));   //insert new snake body at the front     
        setDir(dir);
        length++;
    }
    void Snake::shrink() {
        snakes.pop_back();     //remove last body      
        length--;        
    }
    