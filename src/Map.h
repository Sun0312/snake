/*
    실제 게임이 진행될 Map클래스입니다.
    Objects
        : Wall, Food, Poison, Snake

    

*/


#ifndef MAP_H
#define MAP_H
#include <ncurses.h>


class Map{

    private:
        WINDOW* map_win;

    public:

        //init
        Map();
        Map(int width, int height);
        ~Map();

        //getter
        WINDOW getMap();

        //setter


};


#endif
