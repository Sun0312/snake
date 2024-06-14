#include"Renderer.h"
#include <string>

Renderer::Renderer(){}

void Renderer::renderObj(Map& map, Objects &obj)const{
    vector<vector<char>> *grid = map.getGrid();
    obj.OnMap = true;
    int r = obj.pos.row;
    int c = obj.pos.col;
    (*grid)[r][c] = obj.symbol;   //해당위치에 바로 대입하려면 Objects의 위치가 변경될때 유효성검사가 필요함
}

void Renderer::renderSnake(Map& map, Snake &snake)const{
    /*  반복문사용
    for (int i = 0 ; i < snake.getLength(); i++){

        Objects curBody = snake.snakes.front();

        mvwaddch(win, curBody.pos.row, curBody.pos.col, curBody.symbol);

    }
    */
    for (auto it = snake.snakes.begin(); it != snake.snakes.end() ; ++it){
        Objects& curBody = *it;
        Renderer::renderObj(map, curBody);
    }

}


void Renderer::renderBoard(const Board &board)const{
    
}

void Renderer::renderMap(const Map& map)const{
    vector<vector<char>> maps = map.getGrid();
    WINDOW* win = map.getWin();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);  // 글자: 흰색, 배경: 검은색
    init_pair(2, COLOR_BLACK, COLOR_WHITE);  // 글자: 검은색, 배경: 흰색
    init_pair(3, COLOR_WHITE, COLOR_BLUE);   // 글자: 흰색, 배경: 파란색
    init_pair(4, COLOR_WHITE, COLOR_GREEN);  // Apple 색상
    init_pair(5, COLOR_WHITE, COLOR_RED);    // Poision 색상
    init_pair(6, COLOR_WHITE, COLOR_BLUE);   // Gate 색상

    for (size_t y = 0; y < maps.size(); ++y) {
        for (size_t x = 0; x < maps[y].size(); ++x) {
            int pair = (maps[y][x] == '2') ? 3 : ((maps[y][x] == '1') ? 1 : 2);
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