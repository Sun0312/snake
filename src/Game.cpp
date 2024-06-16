#include "Game.h"

Game::Game() : direction('u') {
    

}

//(int 최소값, int 최대값)사이의 랜덤 정수 반환
int Game::genRand(int minlength, int maxLength) {
    srand(time(0));

    int range = maxLength - minlength + 1;
    int randNum = rand() % range + minlength;

    return randNum;
}

//게임 실행 함수
void Game::runGame(){
    // game title page
    gameWin.updateScreen(gameWin.getMap(), gameWin.getMap().getGrid());
    box(gameWin.getMap().getWin(),'*','*');
    wrefresh(gameWin.getMap().getWin());

    refresh();
    // game page
    werase(gameWin.getMap().getWin());
    gameOver = false;

    while(!gameOver) {
        vector<vector<char>>* init_grid = gameWin.getMap().getGrid();
        vector<vector<char>> grid_copy = *init_grid;
        vector<vector<char>>* grid = &grid_copy;

        vector<vector<char>> maps = *init_grid;
        for (size_t y = 0; y < maps.size(); ++y) {
            for (size_t x = 0; x < maps[0].size(); ++x) {
                mvprintw(y, x+ 150, "%c ", maps[y][x]);
            }
        }

        // recieve input
        char dir = input();
        if (dir == 'x') break;
        wrefresh(gameWin.getMap().getWin());

        mvaddch(0, 70, dir);
        //맵의 복사본이 아닌 Grid의 복사본을 생성하여 수정후 넘겨주자!
        // make objects
        makeObjects(grid);          //cmap에 현재 Objects의 위치에 따라서 배치

        // process input
        // gameOver = processInput(dir);
        gameWin.makeSnake(snake);

        // update window
        gameWin.updateScore(snake, food, poison, gate1, gate2);
        gameWin.updateScreen(gameWin.getMap(), grid);
        timeout(2000);
    }
    // game end page

    mvaddstr(10, 30, "finishing game");
    endwin();
}

//유저입력을 방향으로 변환
char Game::input() { //recieve user input
    char input_direction = getch();

    // unless user goes opposite to current direction, change current direction to user input
    switch (input_direction)
    {
    case (char)KEY_UP:
        direction = (direction != 'd') ? 'u' : 'x';
        break;
    case (char)KEY_DOWN:
        direction = (direction != 'u') ? 'd' : 'x';
        break;
    case (char)KEY_RIGHT:
        direction = (direction != 'l') ? 'r' : 'x';
        break;
    case (char)KEY_LEFT:
        direction = (direction != 'r') ? 'l' : 'x';
        break;
    
    default:
        break;
    }
    return direction;
}

//Objects 객체를 map에 입력함
void Game::makeObjects(vector<vector<char>>* grid){

    vector<vector<char>>* mapData = grid;

    int rowLength = mapData->size();
    int columnLength = mapData[0].size();

    int f_r = food.pos.row;
    int f_c = food.pos.col;
    int p_r = poison.pos.row;
    int p_c = poison.pos.col;

    // make food if no food on map
    if (food.isOnMap() == false) {
        f_r = genRand(1, rowLength-1);
        f_c = genRand(1, columnLength-1);
    }

    // make poison if no poison on map
    if (poison.isOnMap() == false) {
        p_r = genRand(1, rowLength-1);
        p_c = genRand(1, columnLength-1);

    }

    food.pos.col = f_c;
    food.pos.row = f_r;
    poison.pos.col = p_c;
    poison.pos.row = p_r;

    // gate
    int r1 = gate1.pos.row;
    int c1 = gate1.pos.col;
    int r2 = gate2.pos.row;
    int c2 = gate2.pos.row;
    if(gate1.isOnMap() == false) {

        // change position until not in immune wall
        while (r1 == c1 && r1 == rowLength || r1 == c1 && c1 == columnLength) {
            r1 = genRand(0, rowLength);
            c1 = genRand(0, columnLength);
        }
        while (r2 == c2 && r2 == rowLength || r2 == c2 && c2 == columnLength) {
            r2 = genRand(0, rowLength);
            c2 = genRand(0, columnLength);
        }
    }

    // set gate position
    gate1.pos.col = c1;
    gate1.pos.row = r1;
    gate2.pos.col = c2;
    gate2.pos.row = r2;
    
    // change map data
    gameWin.makeObj(grid, poison);
    gameWin.makeObj(grid, food);
    gameWin.makeObj(grid, gate2);
    gameWin.makeObj(grid, gate1);

}

//유저 Input에 따른 처리과정
bool Game::processInput(char dir) {
    mvaddstr(30, 30, "processing input");
    Map &map = gameWin.getMap();
    vector<vector<char>> *pmap = map.getGrid();
    vector<vector<char>> mapData = *pmap;
    snake.grow(dir);

    int next_r, next_c;

    next_c = snake.getPosCol();
    next_r = snake.getPosRow();

    char mapPosInt = mapData[next_r][next_c];

    // check if next position is snake
    for (Objects snakeBody : snake.getBody()) {
        if (snakeBody.pos.col == next_c || snakeBody.pos.row == next_r) {
            return false;
        }
    }

    if (mapPosInt == '1' || mapPosInt == '6') { // encounter wall -> end game
        return false;
    } else if (mapPosInt == '5') { // encounter gate
        if (next_r == gate1.pos.row) {
            snake.setHeadPos(gate2.pos.row, gate2.pos.col);
            snake.move(gate2.getOutDir());
            gate2.increaseGateCnt();
        } else {
            snake.setHeadPos(gate1.pos.row, gate1.pos.col);
            snake.move(gate1.getOutDir());
            gate1.increaseGateCnt();
        }
        snake.shrink();
    } else if (mapPosInt == '4') { // encounter poison
        snake.shrink();
        poison.incPoisonCnt();
        poison.OnMap = false;
    } else if (mapPosInt == '3') {
        food.incFoodCnt();
        food.OnMap = false;
    }    
    return true;
}

void Game::initGame(){
    

    mvaddstr(15,30, "game initialized");

}