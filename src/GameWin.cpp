#include "GameWin.h"

GameWin::GameWin():map(20,60,0,0),mission(5,15,0,65),score(5,15,7,65),renderer(){
    mvaddstr(12, 30, "GameWin Initialized");    
}

//맵 객체의 맵을 그려줌
void GameWin::updateScreen(const Map& omap){
    renderer.renderMap(omap);
    //renderer.renderMission(mission);
    //renderer.renderScore(score);
}

Map& GameWin::getMap(){return this->map;}

void GameWin::makeObj(Objects& obj){
    renderer.renderObj(map,obj);
}