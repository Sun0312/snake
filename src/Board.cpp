#include "Board.h"


Board::Board(){}

Board::Board(int width, int height,int begin_r, int begin_c){
    this->win = newwin(width, height,begin_r, begin_c);
    mvaddstr(10, 30, "Board Initialized");
}
Board::Board(WINDOW* win) {
    this->win = newwin(win->_maxx, win->_maxy, win->_begx, win->_begy);
}

WINDOW* Board::getWin(){
    return this->win;
}

WINDOW* Board::getWin()const{
    return this->win;
}