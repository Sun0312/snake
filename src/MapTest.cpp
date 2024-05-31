#include <ncurses.h>
#include "Board.h"
#include "Map.h"
#include "Snake.h"
int main() {
    initscr();
    noecho();
    curs_set(0);
    
    Map myMap(20, 60, 0, 0);
    box(myMap.getWin(),'*','*');
    myMap.render();
    wrefresh(myMap.getWin());
    
    getch();
    endwin();
    return 0;
}