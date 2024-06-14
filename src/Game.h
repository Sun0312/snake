/*
    Initiates and utilizes GameWin class

    hold all the game logic for snake game
*/



#ifndef _GAME_H
#define _GAME_H
#include <ncurses.h>
#include "Food.h"
#include "Poison.h"
#include "Gate.h"

class Game{

    private:
        bool gameOver = false;
        GameWin gameWin;
        Renderer renderer;
        Snake snake;

        Poison poison;
        Food food;
        Gate gate;

    public:
        //init
        Game();

        void runGame(); //run game function
        void processInput(char dir);
        char input(); //recieve user input

        void makeObjects();

        int genRand(int minLength, int maxLength);


};

#endif