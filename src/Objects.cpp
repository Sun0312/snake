#include "Objects.h"



Objects::Objects(){};
Objects::Objects(int r, int c, char sym){     //추가로 생성시간 등의 속성추가

    this->pos = Position(r, c);
    this->symbol = sym;

}

void Objects::render(WINDOW *win){
    mvwaddch(win, pos.row, pos.col,'-');
}

//낄낄낄