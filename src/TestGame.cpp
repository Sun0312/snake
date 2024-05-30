#include <ncurses.h>
#include "Map.h"
#include "Snake.h"



int main(){


    Map map = Map();

    initscr();
    map.render(stdscr);
    refresh();
    getch();



    return 0;
}