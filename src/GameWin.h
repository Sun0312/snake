/*

    Map, Score, Mission 윈도우를 불러와 직접 
    화면에 띄우고 Objects객체들도 같이 띄우는
    역할을 하는 함수들을 가지고있는
    GameWin 클래스입니다.

    모든 화면의 업데이트(render)를 담당합니다.
*/

#ifndef _GAMEWIN_H
#define _GAMEWIN_H
#include <ncurses.h>
#include "Board.h" 
#include "Map.h"
#include "Mission.h"   
#include "Score.h"
#include "Renderer.h"
class GameWin{

    Map map;
    Mission mission;
    Score score;
    
    Renderer renderer;

    public:
        //init
        GameWin();
        

        //getter
        Map& getMap();
        //setter

        //function

        //스크린 업데이트
        void updateScreen();
        //맵에 오브젝트 삽입
        void makeObj(Objects& obj);

};

#endif