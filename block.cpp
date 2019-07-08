/*******************************************************************************
 *
 * 单人模式游戏界面
 *
 ******************************************************************************/

#include"block.h"

Block::Block(int x, int y, Color c):
    QObject(nullptr),color(c),loc(x,y) {}

const Loc Block::operator-(const Block& b) const {                             //返回两个方块相减所得到的Loc
    return loc - b.loc;
}

const Loc Block::operator+(const Block& b) const {
    return loc + b.loc;
}
