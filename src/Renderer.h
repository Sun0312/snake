#ifndef _RENDERER_H
#define _RENDERER_H


#include <ncurses.h>
#include "Objects.h"
#include "Board.h"
#include "Map.h"
#include "Snake.h"
class Renderer{

    public:

        Renderer();

        void renderObj(Map& map, Objects &obj)const;
        void renderSnake(Map& map, Snake &snake)const;
        void renderBoard(const Board &board)const;
        void renderMap(const Map &map, vector<vector<char>>* mapData)const;


};

#endif