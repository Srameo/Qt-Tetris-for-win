/*******************************************************************************
 *
 * 玩家类
 *
 ******************************************************************************/

#include"require.h"

Map* Player::map = nullptr;

Player::Player(Loc l, Map* m):
    Score(0),control(nullptr),
    next(nullptr),loc(l)
{
    if(m)map = m;
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
        control = next;                                                        //将下一个方块变为现在的control
        int random = qrand() % 7;
        switch(random) {                                                       //生成新的next
        case 0:
            next = new shapeI(this);
            break;
        case 1:
            next = new shapeJ(this);
            break;
        case 2:
            next = new shapeL(this);
            break;
        case 3:
            next = new shapeT(this);
            break;
        case 4:
            next = new shapeS(this);
            break;
        case 5:
            next = new shapeZ(this);
            break;
        case 6:
            next = new shapeO(this);
            break;
        }
        if(predict)
            predict->set(Color(random));
        return true;
    }
    return false;
}

int Player::score() const {
    return Score;
}

Player::~Player() {
    if(control)
        delete control;
    if(next)
        delete next;
}
