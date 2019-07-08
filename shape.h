/*******************************************************************************
 *
 * 所有形状的类
 *
 ******************************************************************************/

#ifndef SHAPE_H
#define SHAPE_H

#include"Loc.h"
#include<vector>
#include"const.h"
#include"map.h"
#include"block.h"
#include"player.h"

class Shape {                                                                   //基类，拥有一些基本操作
private:
    Loc rotate(Loc) const;

protected:
    friend class Player;
    friend class Game;
    friend class Map;
    bool isMovingCollided(Loc[4]);                                              //判断了l[4]中是否有其他player的方块
    bool isCollided(Loc l) const {                                              //判断在当前地图中是否l是否已有东西
        return map->isCollided(l);
    }
    static Map* map;
    std::vector<Block*> p;                                                      //所有格子的位置
    Block* center;                                                              //记录中心位置
    Player* player;                                                             //隶属于那个player
    Color color;                                                                //颜色
    Shape(Player*);
    bool move;                                                                  //判断是否可以移动
    bool drop();                                                                //向下移动
    bool move_left();                                                           //向左移动
    bool move_right();                                                          //向右移动
    virtual bool rotate();                                                      //旋转
    virtual ~Shape();                                                           //在删除的时候将p[4]放入blocks,并将move设为false
};

class shapeI:public Shape {
public:
    shapeI(Player*);
    bool rotate();
};

class shapeJ:public Shape {
public:
    shapeJ(Player*);
};

class shapeL:public Shape {
public:
    shapeL(Player*);
};

class shapeT:public Shape {
public:
    shapeT(Player*);
};

class shapeS:public Shape {
public:
    shapeS(Player* plar);
    bool rotate();
};

class shapeZ:public Shape {
public:
    shapeZ(Player* plar);
    bool rotate();
};

class shapeO:public Shape {
public:
    shapeO(Player*);
    bool rotate(){
        return true;
    }
};

#endif // SHAPE_H
