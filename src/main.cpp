#include "Game.h"

int main(){
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    Game game;

    game.initGame();

    game.runGame();

    getch();
}