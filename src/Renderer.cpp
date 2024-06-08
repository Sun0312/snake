#include"Renderer.h"
#include <string>

Renderer::Renderer(){}

void Renderer::renderObj(Map& map, const Objects &obj)const{
    vector<string> *grid = map.getGrid();
    int r = obj.pos.row;
    int c = obj.pos.col;
    vector<string> g = *grid;
    g[r][c] = obj.symbol;   //해당위치에 바로 대입하려면 Objects의 위치가 변경될때 유효성검사가 필요함
}

void Renderer::renderSnake(Map& map, const Snake &snake)const{
    /*  반복문사용
    for (int i = 0 ; i < snake.getLength(); i++){

        Objects curBody = snake.snakes.front();

        mvwaddch(win, curBody.pos.row, curBody.pos.col, curBody.symbol);

    }
    */
    for (auto it = snake.snakes.begin(); it != snake.snakes.end() ; ++it){
        const Objects& curBody = *it;
        Renderer::renderObj(map, curBody);
    }

}


void Renderer::renderBoard(const Board &board)const{


}