#include "GameWin.h"

GameWin::GameWin():map(22,66,0,0),mission(10,30,0,70),score(10,30,11,70),renderer(){
    mvaddstr(12, 30, "GameWin Initialized");    
}

//맵 객체의 맵을 그려줌
void GameWin::updateScreen(const Map& map, vector<vector<char>>* mapData){
    renderer.renderMap(map, mapData);
    renderer.renderMission(mission,score);
}
//update score
void GameWin::updateScore(Snake &snake, Food &food, Poison& poison, Gate &gate1, Gate &gate2) {
    score.updateScore(snake, food, poison, gate1, gate2);
}

Map& GameWin::getMap(){return this->map;}

void GameWin::makeObj(vector<vector<char>>* grid, Objects& obj){
    mvaddstr(5,100,"create");
    renderer.renderObj(grid,obj);
}
void GameWin::makeSnake(Snake& snake, vector<vector<char>>* grid) {
    renderer.renderSnake(grid, snake);
}