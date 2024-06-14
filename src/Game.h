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

    public:
        //init
        Game();

        void runGame(); //run game function
        void processInput(vector<vector<char>> *map);
        char input(); //recieve user input

        void makeObject(Objects *obj, vector<vector<char>> *map);
        void makeGate(Gate  *gate, vector<vector<char>> *map);

        int genRand(int maxLength);


};

#endif