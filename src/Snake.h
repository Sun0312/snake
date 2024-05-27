/*
뱀을 나타낼 수 있는 Snake클래스




머리부분 SnakeHead클래스


방향 u, d, r, l : 위 아래 오른쪽 왼쪽


*/
#ifndef _SNAKE_H
#define _SNAKE_H
#include "Objects.h"
#include <queue>
using namespace std;


class SnakeHead : public Objects{
    private:
        char direction;
    
    public:
        SnakeHead();
        SnakeHead(int row, int col, char dir);
    
        //getter
        char getDirection();
        //setter
        void setDirection(char dir);

};

class SnakeBody : public Objects{
    public:
        SnakeBody();
        SnakeBody(int r, int c);
};
class Snake : public Objects{

    private:
        int length = 3; //기본길이 3
        queue<Objects> snakes;  // head + body 를 저장하는 queue
        SnakeHead head; //머리
    public:
        //init
        Snake();
        Snake(int r, int c, char dir = 'r'); //HEAD의 시작좌표, 방향지정
        ~Snake();
        //Getter
        int getLength();
        SnakeHead getHead();
        //Setter
        void addLength();
        void minusLength();
        void setHeadDir(char dir);


};

#endif