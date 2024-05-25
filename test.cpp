#include <ncurses.h>
#include <locale.h>
int main(){
    
    setlocale(LC_ALL, "");
    initscr();
    border('|','|','-','-','+','+','+', '+');
    //clear();
    nodelay(stdscr, FALSE);
    attron(COLOR_PAIR('w'));
    mvprintw(12, 35, "GAME OVER");
    mvprintw(17, 35, "PRESS ANY KEY...");
    getch();
    clear();

    endwin();
    
}