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
        processInput(dir);

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

<<<<<<< Updated upstream
void Game::makeObject(Objects *obj, vector<vector<char>> *map) {
    
}
void Game::makeGate(Gate *gate, vector<vector<char>> *map) {
    int rowLength = map->size();
    int columnLength = map[0].size();
    int r, c;
=======
void Game::makeObjects(){
    Map &map = gameWin.getMap();
    vector<vector<char>> mapData = map.getGrid();
    int rowLength = map.size();
    int columnLength = map[0].size();
    int r, c;

    // food
    if (food.isOnMap() == false) {


        r = genRand(1, rowLength);
        c = genRand(1, columnLength);


        renderer.renderObj(food);
    }
>>>>>>> Stashed changes

    // poison
    if (poison.isOnMap() == false) {
        r = genRand(1, rowLength);
        c = genRand(1, columnLength);

        renderer.renderObj(poison);
    }

    // gate
    if(gate.isOnMap() == false) {
        r = genRand(0, rowLength);
        c = genRand(0, columnLength);

        renderer.renderObj(gate);
    }
}

void Game::processInput(char dir) {

    snake.move(dir);
}
