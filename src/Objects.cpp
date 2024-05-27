#include "Objects.h"



Objects::Objects(){};
Objects::Objects(int r, int c){     //추가로 생성시간 등의 속성추가

    this->pos = Position(r, c);

}