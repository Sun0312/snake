#include "GameWin.h"

GameWin::GameWin():map(20,60,0,0),mission(),score(),renderer(){

}

void GameWin::updateScreen(){
    renderer.renderMap(map);
    //미구현renderer.renderMission(mission);
    //미구현renderer.renderScore(score);
}

Map& GameWin::getMap(){return this->map;}

void GameWin::makeObj(Objects& obj){
    renderer.
}