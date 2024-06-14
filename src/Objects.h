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
        char symbol;
        bool OnMap;
        Position pos;
        Objects();
        //생성되는 구조물의 위치 row, col, 화면에 그려지는 심볼 sym
        Objects(int r , int c, char sym);
        
        //getter
        bool isOnMap();

};


#endif