/*
    실제 게임이 진행될 Map클래스입니다.
    Objects
        : Wall, Food, Poison, Snake

    

*/


#ifndef MAP_H
#define MAP_H
#include <ncurses.h>
#include <vector>
#include <string>
using namespace std;


class Map{

    private:
        vector<string> grid;

    public:
        //init
        Map();
        Map(int width, int height);

        //setter
        void loadFromFile(const string& filename);


};


#endif