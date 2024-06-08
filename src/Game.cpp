#include "Game.h"
#include "GameWin.h"
#include "Renderer.h"

#include <ncurses.h>

Game::Game() {};

void Game::runGame() {

    // game title page

    // game page
    GameWin gameWin = GameWin();
    Renderer renderer = Renderer();

    while(gameOver != false) {

        char dir = input();

        gameWin.processInput(dir);

        renderer.render(gameWin);
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