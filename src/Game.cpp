#include "Game.h"

#include <iostream>
using namespace std;

Game::Game() : direction('r') {}

//(int 최소값, int 최대값)사이의 랜덤 정수 반환
int Game::genRand(int minlength, int maxLength) {
    srand(time(0));

    int randNum = rand() % (maxLength + 1) + minlength;

    return randNum;
}

//게임 실행 함수
void Game::runGame(){
    // game title page

    cout << "Begin runGame()";
    // game page

    while(gameOver != false) {

        // recieve input
        char dir = input();
        // make Copy of map
        Map cmap(gameWin.getMap()); //현재 맵의 복사본 cmap생성
        // make objects
        makeObjects(cmap);          //cmap에 현재 Objects의 위치에 따라서 배치

        // process input
        gameOver = processInput(dir);

        // update window
        gameWin.updateScreen(cmap);
    }
    // game end page

    endwin();
}

//유저입력을 방향으로 변환
char Game::input() { //recieve user input
    char input_direction = getch();

    // unless user goes opposite to current direction, change current direction to user input
    if (input_direction == KEY_UP && direction != 'd') {
        direction = 'u';
    } else if (input_direction == KEY_DOWN && direction != 'u') {
        direction = 'd';
    } else if (input_direction == KEY_LEFT && direction != 'r') {
        direction = 'l';
    } else if (input_direction == KEY_RIGHT && direction != 'l') {
        direction = 'r';
    }
    return direction;
}

//Objects 객체를 map에 입력함
void Game::makeObjects(Map& cmap){

    vector<vector<char>>* mapData = cmap.getGrid();

    int rowLength = mapData->size();
    int columnLength = mapData[0].size();

    // make food if no food on map
    if (food.isOnMap() == false) {
        int r, c;

        r = genRand(1, rowLength);
        c = genRand(1, columnLength);

        food.pos.col = c;
        food.pos.row = r;

        gameWin.makeObj(food);
    }

    // make poison if no poison on map
    if (poison.isOnMap() == false) {
        int r, c;

        r = genRand(1, rowLength-1);
        c = genRand(1, columnLength-1);

        poison.pos.col = c;
        poison.pos.row = c;

        gameWin.makeObj(poison);
    }

    // gate
    if(gate1.isOnMap() == false) {
        int r1, c1, r2, c2;

        // change position until not in immune wall
        while (r1 == c1 && r1 == rowLength || r1 == c1 && c1 == columnLength) {
            r1 = genRand(0, rowLength);
            c1 = genRand(0, columnLength);
        }
        while (r2 == c2 && r2 == rowLength || r2 == c2 && c2 == columnLength) {
            r2 = genRand(0, rowLength);
            c2 = genRand(0, columnLength);
        }

        // set gate position
        gate1.pos.col = c1;
        gate1.pos.row = r1;
        gate2.pos.col = c2;
        gate2.pos.row = r2;

        // change map data
        gameWin.makeObj(gate2);
        gameWin.makeObj(gate1);
    }
}

//유저 Input에 따른 처리과정
bool Game::processInput(char dir) {
    Map &map = gameWin.getMap();
    vector<vector<char>> *pmap = map.getGrid();
    vector<vector<char>> mapData = *pmap;
    snake.grow(dir);

    int next_r, next_c;

    next_c = snake.getPosCol();
    next_r = snake.getPosRow();

    char mapPosInt = mapData[next_r][next_c];

    if (mapPosInt == '1' || mapPosInt == '6') { // encounter wall -> end game
        return false;
    } else if (mapPosInt == '5') { // encounter gate
        if (next_r == gate1.pos.row) {
            snake.setHeadPos(gate2.pos.row, gate2.pos.col);
            snake.move(gate2.getOutDir());
            gate2.increaseGateCnt();
        } else {
            snake.setHeadPos(gate1.pos.row, gate1.pos.col);
            snake.move(gate1.getOutDir());
            gate1.increaseGateCnt();
        }
        snake.shrink();
    } else if (mapPosInt == '4') { // encounter poison
        snake.shrink();
        poison.incPoisonCnt();
    } else if (mapPosInt == '3') {
        food.incFoodCnt();
    }    
    return true;
}

void Game::initGame(){
    initscr();
    noecho();
    curs_set(0);

    box(gameWin.getMap().getWin(),'*','*');
    wrefresh(gameWin.getMap().getWin());

    cout << "game initialized";
    
    getch();
}