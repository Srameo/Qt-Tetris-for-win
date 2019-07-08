/*******************************************************************************
 *
 * 包含每一个方块的类
 *
 ******************************************************************************/

#ifndef BLOCK_H
#define BLOCK_H

#include"loc.h"
#include"const.h"
#include<QObject>

class Block:public QObject
{
    Q_OBJECT

public:
    Color color;
    Loc loc;
    Block(int,int,Color);
    const Loc operator-(const Block&) const;
    const Loc operator+(const Block&) const;
};

#endif // BLOCK_H
