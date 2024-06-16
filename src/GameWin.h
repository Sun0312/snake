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

        //넘겨받은 스크린 업데이트
        void updateScore(Snake &snake, Food &food, Poison &poison, Gate &gate1, Gate &gate2);
        void updateScreen(const Map&, vector<vector<char>>* mapData);
        //맵에 오브젝트 삽입
        void makeObj(vector<vector<char>>* grid, Objects& obj);
        void makeSnake(vector<vector<char>>* grid, Snake& snake);

};

#endif