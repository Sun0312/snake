#include "Game.h"

int main(){
    Game* game = new Game();

    game->initGame();

    game->runGame();

    getch();
}