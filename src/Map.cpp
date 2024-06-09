#include "Map.h"
#include "Board.h"
#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>
using namespace std;

Map::Map(int width, int height, int br, int bc) : Board(width, height, br, bc), currentMapIndex(0) {
    initializeMaps(); // 맵 데이터 초기화
}

void Map::initializeMaps() {
    // 첫 번째 맵 데이터
    maps.push_back({
        {'2', '1', '1', '1', '1', '1', '1', '1', '1', '2'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'2', '1', '1', '1', '1', '1', '1', '1', '1', '2'}
    });

    // 두 번째 맵 데이터
    maps.push_back({
        {'2', '1', '1', '1', '1', '1', '1', '1', '1', '2'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '1', '1', '1', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'2', '1', '1', '1', '1', '1', '1', '1', '1', '2'}
    });

    // 세 번째 맵 데이터
    maps.push_back({
        {'2', '1', '1', '1', '1', '1', '1', '1', '1', '2'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '1', '1', '1', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '1', '1', '1', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'2', '1', '1', '1', '1', '1', '1', '1', '1', '2'}
    });
}

void Map::nextMap() {
    if (currentMapIndex + 1 < maps.size()) {
        currentMapIndex++;
    }
}

int Map::getCMI(){return currentMapIndex;}
void Map::render() const {

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);  // 글자: 흰색, 배경: 검은색
    init_pair(2, COLOR_BLACK, COLOR_WHITE);  // 글자: 검은색, 배경: 흰색
    init_pair(3, COLOR_WHITE, COLOR_BLUE);   // 글자: 흰색, 배경: 파란색
    init_pair(4, COLOR_WHITE, COLOR_GREEN);  // Apple 색상
    init_pair(5, COLOR_WHITE, COLOR_RED);    // Poision 색상
    init_pair(6, COLOR_WHITE, COLOR_BLUE);   // Gate 색상

    for (size_t y = 0; y < maps[currentMapIndex].size(); ++y) {
        for (size_t x = 0; x < maps[currentMapIndex][y].size(); ++x) {
            int pair = (maps[currentMapIndex][y][x] == '2') ? 3 : ((maps[currentMapIndex][y][x] == '1') ? 1 : 2);
            wattron(win, COLOR_PAIR(pair));
            // 각 셀을 가로로 세 번 출력
            for (int i = 0; i < 3; i++) {
                mvwaddch(win, y, 3 * x + i, ' ');  // x 위치를 3배로 확장하여 출력
            }
            wattroff(win, COLOR_PAIR(pair));
        }
    }
    wrefresh(win);
}

vector<vector<vector<char>>>* Map::getGrid(){
    return &maps;
}