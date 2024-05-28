#include "Snake.h"

//SNAKEBODY
SnakeBody::SnakeBody(){};

SnakeBody::SnakeBody(int r, int c):Objects(r,c){
    ;
};

//SNAKE

Snake::Snake(){};
Snake::Snake(int r, int c, char dir = 'r'){
    this->dir = dir;
    snakes.push(SnakeBody(r,c - 1*width)); //칸이 줄보다 작아서 2배수or3배수될듯...
    snakes.push(SnakeBody(r,c - 2*width));
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

    void Snake::addLength(){
        length++;
        Position lastPos = snakes.back().pos; //get pos of last snake body

        move(getDir()); // move in current direction
        snakes.push(SnakeBody(lastPos.row, lastPos.col)); // add a snake body
    }

    void Snake::minusLength(){
        length--;
    }

    void Snake::setDir(char dir){
        this->dir = dir;
    }

    // SNAKE : FUNCTIONS

    void Snake::move(char dir) {
        grow(dir);
        shrink();
    }

    void Snake::grow(char dir) {
        Position currentPos = snakes.front().pos;
        Position newPos;
        if (dir == 'l') newPos = Position(currentPos.row, currentPos.col - width);
        if (dir == 'r') newPos = Position(currentPos.row, currentPos.col + width);
        if (dir == 'u') newPos = Position(currentPos.row - height, currentPos.col);
        if (dir == 'd') newPos = Position(currentPos.row + height, currentPos.col);

        snakes.push(SnakeBody(newPos.row, newPos.col));   //insert new snake body at the front     
        setDir(dir);
    }
    void Snake::shrink() {
        snakes.pop();     //remove last body              
    }