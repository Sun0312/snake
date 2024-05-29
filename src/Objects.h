/*
    snake게임중 Map위에 존재하는 구조물을
    담당하는 Objects클래스입니다.
    모든 구조물들은 해당클래스를 상속함.


*/
#ifndef _OBJECTS_H
#define _OBJECTS_H
#include <ncurses.h>
struct Position{    //해당 Position은 해당 WINDOW의 상대좌표임

    int row;
    int col;

    Position(int r, int c);
    Position();

};

class Objects{
    public:

        Position pos;
        Objects();
        Objects(int r , int c);
        //모든 구조물들은 해당하는 윈도우에 그려질 수 있어야함
        virtual void render(WINDOW &win);   

};


#endif