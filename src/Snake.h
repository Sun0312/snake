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

class SnakeBody : public Objects{
    public:
        SnakeBody();
        SnakeBody(int r, int c);
};

class Snake {

    private:
        //height and width of 1 snake block
        int height = 1;
        int width = 3; 

        int length = 3; //기본길이 3
        char dir = 'r'; //initial direction = right
        
    public:
    deque<Objects> snakes;  // head + body 를 저장하는 queue
        //init
        Snake();
        Snake(int r, int c, char dir = 'r'); //HEAD의 시작좌표, 방향지정
        ~Snake();
        //Getter
        int getLength();
        char getDir();
    
        //Setter
        void setDir(char dir);
        //functions
        void move(char dir);
        void grow(char dir);
        void shrink();
        
};

#endif