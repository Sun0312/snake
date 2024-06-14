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


class Map : public Board {
private:
    vector<vector<vector<char>>> maps; // 여러 맵 데이터
    int currentMapIndex;               // 현재 활성화된 맵 인덱스

public:
    Map(int width, int height, int br, int bc);
    void initializeMaps();             // 맵 데이터 초기화
    int getCMI();                      //현재 맵 인덱스
    int getCMI()const;
    void nextMap();                    // 다음 맵으로 전환
    void render() const;               // 현재 맵 렌더링환

    // 현재 맵데이터의 포인터 반환
    vector<vector<char>>* getGrid();   
    //현재 맵데이터 반환
    vector<vector<char>> getGrid()const;
};

#endif