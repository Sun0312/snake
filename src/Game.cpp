#include "Game.h"
#include "GameWin.h"
#include "Renderer.h"
#include "Snake.h"
#include "Poison.h"
#include "Wall.h"
#include "Food.h"
#include "Map.h"

#include <ncurses.h>

Game::Game() {};

void Game::runGame() {
    GameWin gameWin = GameWin();
    Renderer renderer = Renderer();
    Snake snake = Snake(3, 4);

    Map map = Map(50, 50, 10, 10);

    Poison poison;
    Food food;

    // game title page

    // game page

    while(gameOver != false) {

        char dir = input();

        processInput(map.getGrid());

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

void Game::processInput(vector<vector<char>> *map) {

    

    snake.move(dir);
}