#include"Renderer.h"
#include <string>
#include <cstring>
#include <iostream>

Renderer::Renderer(){}

void Renderer::renderObj(vector<vector<char>>* grid, Objects &obj)const{
    vector<vector<char>> wgrid = *grid;
    obj.OnMap = true;
    int r = obj.pos.row;
    int c = obj.pos.col;
    
    wgrid.at(r).at(c) = obj.symbol;
    //(*grid)[r][c] = obj.symbol;   //해당위치에 바로 대입하려면 Objects의 위치가 변경될때 유효성검사가 필요함

}

void Renderer::renderSnake(vector<vector<char>>* grid, Snake &snake)const{
    /*  반복문사용
    for (int i = 0 ; i < snake.getLength(); i++){

        Objects curBody = snake.snakes.front();

        mvwaddch(win, curBody.pos.row, curBody.pos.col, curBody.symbol);

    }
    */
    for (auto it = snake.snakes.begin(); it != snake.snakes.end() ; ++it){
        Objects& curBody = *it;
        Renderer::renderObj(grid, curBody);
    }
}


void Renderer::renderMission(const Mission& mission, Score& score)const{
        
        //Snake 길이, Food 먹은 개수, Poison 먹은 개수, Gate 통과 횟수
        vector<int> missions = mission.getCurrentMission();
        int snakemission = missions[0];
        int Foodmission = missions[1];
        int Poisonmission = missions[2];
        int gatemission = missions[3];

        int snakeScore = score.getSnake();
        int FoodScore = score.getFood();
        int PoisonScore = score.getPoison();
        int gateScore = score.getGate();

      
        WINDOW* win = mission.getWin();
       
        box(win, '*', '*');
     
        string lengthdata = "Length :";
        lengthdata += std::to_string(snakeScore);
        lengthdata += " / ";
        lengthdata += std::to_string(snakemission);
        char chars[1000];
        std::strcpy(chars,lengthdata.c_str());
        mvwaddstr(win,2,5, chars);
        
        string foodData = "Food :";
        foodData += std::to_string(FoodScore);
        foodData += " / ";
        foodData += std::to_string(Foodmission);
        char charss[100];
        std::strcpy(charss, foodData.c_str());
        mvwaddstr(win,3,5, charss);

        string poData = "Poison:";
        poData += std::to_string(PoisonScore);
        poData += " / ";
        poData += std::to_string(PoisonScore);
        char charssss[100];
        std::strcpy(charssss, poData.c_str());
        mvwaddstr(win,4,5, charssss);

        string GateData = "Gate:";
        GateData += std::to_string(gateScore);
        GateData += " / ";
        GateData += std::to_string(gateScore);
        char charsss[100];
        std::strcpy(charsss, GateData.c_str());
        mvwaddstr(win,5,5, charsss);
      
        wrefresh(win);
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
        for (size_t x = 0; x < maps.at(y).size(); ++x) {
            int pair;
            char attr = maps.at(y).at(x);
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