#include "GameWin.h"

GameWin::GameWin():map(22,66,0,0),mission(10,30,0,70),score(10,30,11,70),renderer(){
    mvaddstr(12, 30, "GameWin Initialized");    
}

//맵 객체의 맵을 그려줌
void GameWin::updateScreen(const Map& map, vector<vector<char>>* mapData){
    renderer.renderMap(map, mapData);
    renderer.renderMission(mission,score);
   
}

Map& GameWin::getMap(){return this->map;}

void GameWin::makeObj(Objects& obj){
    renderer.renderObj(map,obj);
}
void GameWin::makeSnake(Snake& snake) {
    renderer.renderSnake(map, snake);
}