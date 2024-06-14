#include "Game.h"
#include "GameWin.h"
#include "Renderer.h"
#include "Snake.h"
#include "Poison.h"
#include "Wall.h"
#include "Food.h"
#include "Map.h"

#include <ncurses.h>

Game::Game() {
};

int Game::genRand(int minlength, int maxLength) {
    srand(time(0));

    int randNum = rand() % (maxLength + 1) + minlength;

    return randNum;
}

void Game::runGame() {
    // game title page

    // game page

    while(gameOver != false) {

        // recieve input
        char dir = input();

        // make objects
        makeObjects();

        // process input
        gameOver = processInput(dir);

        // update window
        gameWin.updateScreen();
    }
    // game end page
}

char Game::input() { //recieve user input
    char direction = 'r';
    char input_direction = getch();
    switch(input_direction) {
        case KEY_UP: direction = 'u'; break;
        case KEY_DOWN: direction = 'd'; break;
        case KEY_LEFT: direction = 'l'; break;
        case KEY_RIGHT: direction = 'r'; break;
        default: break;
    }
    return direction;
}

void Game::makeObjects(){
    Map &map = gameWin.getMap();
    vector<vector<char>> *mapData = map.getGrid();

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

bool Game::processInput(char dir) {
    Map &map = gameWin.getMap();
    vector<vector<char>> *mapData = map.getGrid();

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
        } else {
            snake.setHeadPos(gate1.pos.row, gate1.pos.col);
            snake.move(gate1.getOutDir());
        }
        snake.shrink();
    } else if (mapPosInt == '4') { // encounter poison
        snake.shrink();
    }

    // don't do anything when encountering food ('4')
    
    return true;
}
