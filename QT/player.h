/*******************************************************************************
 *
 * 玩家类
 *
 ******************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include<ctime>
#include"loc.h"
#include"predict.h"

class Shape;
class Map;

class Player {
private:
    friend class Map;
    friend class Shape;
    friend class Game;
    static Map* map;                                                            //玩家所在地图
    int Score;                                                                  //记录分数
    Shape* control;                                                             //记录正在操作的方块
    Shape* next;                                                                //下一个要操作的方块

public:
    Player(Loc, Map* m = nullptr);
    predictScene *predict;
    bool drop();                                                                //control向下移动，如果无法移动删除control并使control指向NULL
    bool move_left();                                                           //control向左移动
    bool move_right();                                                          //control向右移动
    bool rotate();                                                              //control旋转
    Loc loc;                                                                    //制造方块的位置
    bool createShape();                                                         //如果没有control，则生成新的随机control
    int score() const;                                                          //返回得分
    ~Player();
};

#endif // PLAYER_H
