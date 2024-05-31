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
#include "Board.h"
using namespace std;


class Map : public Board{

    private:
        vector<string> grid;

    public:
        //init
        Map();
        Map(int width, int height,int br, int bc);



        //setter
        void loadFromFile(const string& filename);

        void render() const;

};


#endif