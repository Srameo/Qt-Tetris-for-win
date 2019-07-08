/*******************************************************************************
 *
 * 游戏界面中的地图类
 *
 ******************************************************************************/

#ifndef MAP_H
#define MAP_H

#include<vector>
#include"loc.h"
#include"const.h"

class Player;
class Block;
class Game;

class Map {
private:
    int have(int) const;                                                        //计算第int行所拥有的blocks的个数
    void remove(int);                                                           //消除第int行的数据，并将其他格子在那上边的向下移动一个

public:
    friend class Player;
    friend class Game;
    bool isMovingCollided(Player*, Loc[4]) const;                               //player移动到Loc判断是否和另一个碰撞
    bool isCollided(Loc) const;                                                 //判断Loc是否为边界外或和已有Block在该位置上
    std::vector<Player*> player;                                                //储存player
    std::vector<Block*> blocks;                                                 //储存所有方块，方便判断是否重合
    Map(int player_num = 1);                                                    //默认游戏人数1
    int difficulty;
    void addDifficulty();                                                       //添加难度
    int total_lines;
    const int height;                                                           //地图高度
    const int width;                                                            //地图宽度
    const Size size;                                                            //地图大小
    int remove();                                                               //消除整行并返回消除行数,只需判断最后四个添加到blocks里的元素
    bool live() const;                                                          //判断游戏能否继续,只需判断最后四个添加到blocks里的元素
    int velocity;                                                               //速度：每velocity毫秒下落一个格子
    Game* g;                                                                    //指向该map隶属于的Game指针，方便二者互动
    ~Map();
};

#endif // MAP_H
