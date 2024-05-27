#include <ncurses.h>


struct Position{

    int row;
    int col;

    Position(int r, int c);
    Position();

};

class Objects{
    public:

        Position pos;
        Objects();
        Objects(int r , int c);

};