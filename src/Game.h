/*
    Initiates and utilizes GameWin class

    hold all the game logic for snake game
*/



#ifndef _GAME_H
#define _GAME_H
#include <ncurses.h>


class Game{

    private:
        bool gameOver = false;

    public:
        //init
        Game();

        void runGame(); //run game function

        char input(); //recieve user input

};

#endif