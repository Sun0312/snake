#include"Renderer.h"
#include <string>

Renderer::Renderer(){}



void Renderer::renderSnake(WINDOW* win, Snake &snake)const{
    /*  반복문사용
    for (int i = 0 ; i < snake.getLength(); i++){

        Objects curBody = snake.snakes.front();

        mvwaddch(win, curBody.pos.row, curBody.pos.col, curBody.symbol);

    }
    */
    for (auto it = snake.snakes.begin(); it != snake.snakes.end() ; ++it){
        const Objects& curBody = *it;
        mvwaddch(win, curBody.pos.row, curBody.pos.col, curBody.symbol);
    }

}
void Renderer::renderObjects(const Objects &obj)const{
    
}

void Renderer::renderMap(const Map &map)const{
    
}

void Renderer::renderScore(const Score &score)const{

}

void Renderer::renderMission(const Mission &mission)const{

}