#ifndef _RENDERER_H
#define _RENDERER_H


#include <ncurses.h>
#include "Objects.h"
#include "Board.h"
class Renderer{

    public:

        Renderer();

        void render(WINDOW* win, const Objects &obj)const;
        void render(WINDOW* win, const Board &board)const;



};



#endif