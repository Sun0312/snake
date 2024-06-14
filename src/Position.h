#ifndef _POSITION_H
#define _POSITION_H

struct Position{    //해당 Position은 해당 WINDOW의 상대좌표임

    int row;
    int col;
    Position(int r, int c);
    Position();

};

#endif