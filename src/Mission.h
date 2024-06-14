/*

    달성과제를 띄우는 WINDOW객체를 관리하는 
    Mission클래스입니다.

*/

using namespace std;

#ifndef MISSION_H
#define MISSION_H

#include <vector>
#include <ncurses.h>
#include "Board.h"

class Mission : public Board {
private:
    vector<vector<int>> missions; // 여러 미션 데이터를 저장할 2차원 벡터
    int currentMissionIndex;                // 현재 활성화된 미션 인덱스

public:
    Mission(int width, int height, int br, int bc);
    void initializeMissions();              // 미션 데이터 초기화
    int getCurrentMissionIndex() const;     // 현재 미션 인덱스 반환
    vector<int> getCurrentMission() const; // 현재 미션 반환
    void nextMission();                     // 다음 미션으로 전환
    bool missionClear(int snakeLength, int foodEaten, int poisonsEaten, int gatesPassed) const; // 미션 완료 여부 검사
};

#endif
