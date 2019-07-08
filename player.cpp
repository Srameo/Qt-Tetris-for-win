/*******************************************************************************
 *
 * 玩家类
 *
 ******************************************************************************/

#include"require.h"

Map* Player::map = nullptr;

Player::Player(Loc l, Map* m):
    Score(0),control(nullptr),loc(l)
{
    if(m)map = m;
    createShape();
    last_drop = clock();
}

bool Player::drop() {                                                          //control向下移动，如果无法移动删除control并使control指向NULL
    if(control) {
        if(!control->drop()) {
            delete control;
            control = nullptr;
            return false;
        }
    return true;
    }
    else
        return false;
}

bool Player::move_left() {                                                     //control的各种移动
    if(control)
        return control->move_left();
    return false;
}

bool Player::move_right() {
    if(control)
        return control->move_right();
    return false;
}

bool Player::rotate() {
    if(control)
        return control->rotate();
    return false;
}

bool Player::createShape() {                                                   //如果没有control，则生成新的随机control
    if(!control) {
        int random = qrand() % 7;
        switch(random) {
        case 0:
            control = new shapeI(this);
            break;
        case 1:
            control = new shapeL(this);
            break;
        case 2:
            control = new shapeJ(this);
            break;
        case 3:
            control = new shapeS(this);
            break;
        case 4:
            control = new shapeZ(this);
            break;
        case 5:
            control = new shapeO(this);
            break;
        case 6:
            control = new shapeT(this);
            break;
        }
        return true;
    }
    return false;
}

int Player::score() const {
    return Score;
}
