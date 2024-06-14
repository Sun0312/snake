#include "Mission.h"

using namespace std;

Mission::Mission() : currentMissionIndex(0) {
    initializeMissions(); // 미션 데이터 초기화
}

void Mission::initializeMissions() {
    // 첫 번째 미션 데이터 (Snake 길이, Apple 먹은 개수, Poison 먹은 개수, Gate 통과 횟수)
    missions.push_back({10, 3, 2, 1});

    // 두 번째 미션 데이터
    missions.push_back({15, 5, 3, 2});

    // 세 번째 미션 데이터
    missions.push_back({20, 8, 4, 3});
}

int Mission::getCurrentMissionIndex() const {
    return currentMissionIndex;
}

vector<int> Mission::getCurrentMission() const {
    return missions[currentMissionIndex];
}

void Mission::nextMission() {
    if (currentMissionIndex + 1 < missions.size()) {
        currentMissionIndex++;
    }
}

bool Mission::missionClear(int snakeLength, int applesEaten, int poisonsEaten, int gatesPassed) const {
    const vector<int>& currentMission = missions[currentMissionIndex];
    return snakeLength >= currentMission[0] && applesEaten >= currentMission[1] && poisonsEaten >= currentMission[2] && gatesPassed >= currentMission[3];
}
