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
#include "Map.h"
#include "Renderer.h"
#include "GameWin.h"

class Game{

    private:
        bool gameOver;
        GameWin gameWin;
        Renderer renderer;
        Snake snake;

        Poison poison;
        Food food;
        Gate gate1;
        Gate gate2;

        char direction;

    public:
        //init
        Game();

        void runGame(); //run game function
        bool processInput(char dir);
        char input(); //recieve user input

        // make objects on map
        void makeObjects(vector<vector<char>>* grid);

        // generate random number
        int genRand(int minLength, int maxLength);

        // init Game
        void initGame();
};

#endif