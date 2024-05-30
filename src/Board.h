#include <ncurses.h>


class Board{
    private:
        WINDOW* win;

    public:
        //init
        Board();
        Board(int width, int height, int begin_r, int begin_c);

        //Getter
        WINDOW* getWin();
};