/*
    Objects를 상속하는 벽 구조물입니다.
    Gate가 생성될 수 있는지를 판단하는 immune속성
*/
#ifndef _WALL_H
#define _WALL_H
#include "Objects.h"
class Wall: public Objects{
    private:
        bool immune;
    
    public:
        //init
        Wall();
        Wall(int r, int c, bool im = false);
        ~Wall();
        
        //getter
        bool isImmune();
        //setter
        

};




#endif