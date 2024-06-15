#ifndef _RENDERER_H
#define _RENDERER_H


#include <ncurses.h>
#include "Objects.h"
#include "Board.h"
#include "Map.h"
#include "Snake.h"
#include "Score.h" 
#include "Mission.h"

class Renderer{

    public:

        Renderer();

        void renderObj(vector<vector<char>>* grid, Objects &obj)const;
        void renderSnake(vector<vector<char>>* grid, Snake &snake)const;
        
        void renderMap(const Map &map, vector<vector<char>>* mapData)const;

        void renderMission(const Mission& mission, Score& score)const;
        void renderScore(const Score& score)const;

};

#endif