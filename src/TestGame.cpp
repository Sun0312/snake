#include <ncurses.h>
#include "Map.h"
#include "Snake.h"
#include <typeinfo>
#include <iostream>

int main(){


    Map map(1,1,0,0);

    cout << typeid(map).name();
}