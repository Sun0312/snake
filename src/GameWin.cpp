#include "GameWin.h"

GameWin::GameWin():map(20,60,0,0),mission(),score(),renderer(){

}

//맵 객체의 맵을 그려줌
void GameWin::updateScreen(const Map& omap){
    renderer.renderMap(omap);
    //미구현renderer.renderMission(mission);
    //미구현renderer.renderScore(score);
}

Map& GameWin::getMap(){return this->map;}

void GameWin::makeObj(Objects& obj){
    renderer.renderObj(map,obj);
}