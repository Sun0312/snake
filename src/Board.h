#ifndef _BOARD_H
#define _BOARD_H
#include <ncurses.h>

class Board{
    protected:
        WINDOW* win;

    public:
        //init
        Board();
        Board(int width, int height, int begin_r, int begin_c);
        Board(WINDOW* win);

        //Getter
        WINDOW* getWin();
        WINDOW* getWin()const;
};

#endif