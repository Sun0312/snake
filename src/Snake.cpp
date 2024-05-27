#include "Snake.h"

//SNAKEHEAD

SnakeHead::SnakeHead(){};

SnakeHead::SnakeHead(int row, int col, char dir):Objects(row, col){
    this->direction = dir;

}
    //Getter
    char SnakeHead::getDirection(){
        return direction;
    }
    //Setter
    void SnakeHead::setDirection(char dir){
        direction = dir;
    }
//SNAKEBODY
SnakeBody::SnakeBody(){};

SnakeBody::SnakeBody(int r, int c):Objects(r,c){
    ;
};

//SNAKE

Snake::Snake(){};
Snake::Snake(int r, int c, char dir = 'r'){
    this->head = SnakeHead(r,c,dir);
    snakes.push(SnakeBody(r,c - 1)); //칸이 줄보다 작아서 2배수or3배수될듯...
    snakes.push(SnakeBody(r,c - 2));

}

Snake::~Snake(){};

    //SNAKE : GETTER

    int Snake::getLength(){
        return length;
    };

    SnakeHead Snake::getHead(){
        return head;
    }

    //SNAKE : SETTER

    void Snake::addLength(){
        length++;
    }

    void Snake::minusLength(){
        length--;
    }

    void Snake::setHeadDir(char dir){
        head.setDirection(dir);
    }