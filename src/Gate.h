/*
    Map상에 존재하는 Gate클래스입니다.

    생성로직, 출구로직 필요.
    
    Snake의 다음칸을 가져오는 함수에서 진입방향 지정
    Gate클래스에서 Snake의 진출방향 생성
    
*/


#ifndef _GATE_H
#define _GATE_H
#include "Objects.h"
#include "vector"
using namespace std;

class Gate : public Objects{
    private:
        static int gateCnt;
        char outDirection;
        char symbol = '5';

    public:
        //init
        Gate();
        Gate(vector<vector<char>> &map);

        //getter
        char getOutDir();
        int getGateCnt();

        //setter
        void increaseGateCnt();

        //operations
        int genRand(int maxLength);

};
#endif