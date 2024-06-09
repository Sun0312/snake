#include "Board.h"


Board::Board(){}

Board::Board(int width, int height,int begin_r, int begin_c){
    this->win = newwin(width, height,begin_r, begin_c);
}

WINDOW* Board::getWin(){
    return this->win;
}

WINDOW* Board::getWin()const{
    return this->win;
}