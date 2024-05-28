#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>
using namespace std;
class Map {
private:
    vector<string> grid;
public:
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            grid.push_back(line);
        }
        file.close();
    }
    void render() const {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);  // 글자: 흰색, 배경: 검은색
        init_pair(2, COLOR_BLACK, COLOR_WHITE);  // 글자: 검은색, 배경: 흰색
        init_pair(3, COLOR_WHITE, COLOR_BLUE);   // 글자: 흰색, 배경: 파란색
        for (size_t y = 0; y < grid.size(); ++y) {
            for (size_t x = 0; x < grid[y].size(); ++x) {
                int pair = (grid[y][x] == '1') ? 1 : ((grid[y][x] == '0') ? 2 : 3);
                attron(COLOR_PAIR(pair));
                mvaddch(y, x, ' ');
                attroff(COLOR_PAIR(pair));
            }
        }
    }
};
int main() {
    initscr();
    noecho();
    curs_set(0);
    Map myMap;
    myMap.loadFromFile("map.txt");
    myMap.render();
    refresh();
    getch();
    endwin();
    return 0;
}