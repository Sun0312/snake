#include <ncurses.h>
#include <locale.h>

int main() {
    // Initialize locale and ncurses
    setlocale(LC_ALL, "");
    initscr();
    
    // Check if the terminal supports color
    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }
    
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    
    // Get the screen size
    int height, width;
    getmaxyx(stdscr, height, width);
    
    // Calculate window sizes and positions
    int win_height = height / 3;
    int win_width = width;
    
    // Create windows
    WINDOW *win1 = newwin(win_height, win_width, 0, 0);
    WINDOW *win2 = newwin(win_height, win_width, win_height, 0);
    WINDOW *win3 = newwin(win_height, win_width, 2 * win_height, 0);
    
    // Draw borders around the windows
    box(win1, 0, 0);
    box(win2, 0, 0);
    box(win3, 0, 0);
    border('*','*','*','*','*','*','*','*');
    wborder(win1,'*','*','*','*','*','*','*','*');
    wborder(win2,'*','*','*','*','*','*','*','*');
    wborder(win3,'*','*','*','*','*','*','*','*');
    
   
    refresh();
    wbkgd(win1,COLOR_PAIR(1));
    wbkgd(win2,COLOR_PAIR(2));
    wbkgd(win3,COLOR_PAIR(3));
    
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);
    getch();
    
    // Clear and end ncurses mode
    delwin(win1);
    delwin(win2);
    delwin(win3);
    endwin();
    
    return 0;
}
