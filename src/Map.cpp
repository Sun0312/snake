#include "Map.h"
#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>
using namespace std;

void Map::loadFromFile(const string& filename) {  // 파일 읽는 함수
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        grid.push_back(line); // grid 벡터에 저장
    }
    file.close();
}

void Map::render(WINDOW* win) const {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);  // 글자: 흰색, 배경: 검은색
    init_pair(2, COLOR_BLACK, COLOR_WHITE);  // 글자: 검은색, 배경: 흰색
    init_pair(3, COLOR_WHITE, COLOR_BLUE);   // 글자: 흰색, 배경: 파란색
    for (size_t y = 0; y < grid.size(); ++y) {
        for (size_t x = 0; x < grid[y].size(); ++x) {
            int pair = (grid[y][x] == '1') ? 1 : ((grid[y][x] == '0') ? 2 : 3);
            wattron(win, COLOR_PAIR(pair));
            mvwaddch(win, y, x, ' ');
            wattroff(win, COLOR_PAIR(pair));
        }
    }
}
int main() {
    initscr();
    noecho();
    curs_set(0);
    int height = 40;    // 예시로 설정한 맵의 높이
    int width = 80;     // 예시로 설정한 맵의 너비
    int start_y = 0;    // 윈도우가 시작할 y 좌표
    int start_x = 0;    // 윈도우가 시작할 x 좌표
    WINDOW* map_win = newwin(height, width, start_y, start_x);
    Map myMap;
    myMap.loadFromFile("map.txt");
    myMap.render(map_win);
    refresh();
    wrefresh(map_win);
    getch();
    endwin();
    return 0;
}