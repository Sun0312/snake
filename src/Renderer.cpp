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


void Renderer::renderMission(const Mission& mission, const Score& score)const{
        //Snake 길이, Apple 먹은 개수, Poison 먹은 개수, Gate 통과 횟수
        vector<int> missions = mission.getCurrentMission();
        int snakemission = missions[0];
        int Foodmission = missions[1];
        int Poisonmission = missions[2];
        int gatemission = missions[3];

        int snakeScore = score.getSnake();
        int FoodScore = score.get

        WINDOW* win = mission.getWin();

        mvaddstr(2,5,"Length :");
        mvaddch(2,5, snakemission + '0');

        mvaddstr(3,5,"Food :");
        mvaddch(3,5, snakemission + '0');
        mvaddstr(2,5,"Length :");
        mvaddch(2,5, snakemission + '0');
        mvaddstr(2,5,"Length :");
        mvaddch(2,5, snakemission + '0');

}



void Renderer::renderScore(const Score& score)const{
    
}

void Renderer::renderMap(const Map& map, vector<vector<char>>* mapData)const{
    WINDOW* win = map.getWin();
    vector<vector<char>>maps = *mapData;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);  // 글자: 흰색, 배경: 검은색
    init_pair(2, COLOR_BLACK, COLOR_WHITE);  // 글자: 검은색, 배경: 흰색
    init_pair(3, COLOR_WHITE, COLOR_BLUE);   // 글자: 흰색, 배경: 파란색
    init_pair(4, COLOR_WHITE, COLOR_GREEN);  // Apple 색상
    init_pair(5, COLOR_WHITE, COLOR_RED);    // Poision 색상
    init_pair(6, COLOR_WHITE, COLOR_BLUE);   // Gate 색상
    init_pair(7, COLOR_WHITE, COLOR_YELLOW); // Snake 색상

    for (size_t y = 0; y < maps.size(); ++y) {
        for (size_t x = 0; x < maps[y].size(); ++x) {
            int pair;
            char attr = maps[y][x];
            switch(attr){
                case '0':
                pair = 1;
                break;
                case '1':
                pair = 2;
                break;
                case '2':
                pair = 3;
                break;
                case '3':
                pair = 4;
                break;
                case '4':
                pair = 5;
                break;
                case '5':
                pair = 6;
                break;
                case '6':
                pair = 7;
                break;

            }
            wattron(win, COLOR_PAIR(pair));
            
            mvwaddstr(win,y,3*x,"   ");
            wattroff(win, COLOR_PAIR(pair));
        }
    }
    wrefresh(win);
}