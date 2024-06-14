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

int Game::genRand(int maxLength) {
    srand(time(0));

    int randNum = 0 + rand() % (maxLength + 1);

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
        processInput();

        // update window
        gameWin.update();
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
    int rowLength = map->size();
    int columnLength = map[0].size();
    int r, c;

    if (obj->isOnMap() == false) {
        r = genRand(rowLength);
        c = genRand(columnLength);

        map[r][c] = obj->symbol;
    }
}
void Game::makeGate(Gate *gate, vector<vector<char>> *map) {
    int rowLength = map->size();
    int columnLength = map[0].size();
    int r, c;

    if (gate->isOnMap() == false) {
        

        map[r][c] = gate->symbol;
    }
}

void Game::processInput(vector<vector<char>> *map) {

    

    snake.move(dir);
}
