/*******************************************************************************
 *
 * 包含游戏类
 * 使用方法：
 * masterSDialog masterSScene masterDialog masterScene均为静态变量
 * 1.单人模式：
 *   先将masterSDialog指向单人模式的界面
 *   再将masterSScene指向单人模式中的游戏显示界面
 *   然后将masterSDialog中的Game*指向新建的游戏指针
 *       g = new Game(1);
 * 2.双人模式：
 *   先将masterDialog指向双人模式的界面
 *   再将masterScene指向双人模式中的游戏显示界面
 *   然后将masterDialog中的Game*指向新建的游戏指针
 *       g = new Game(2);
 *
 ******************************************************************************/

#ifndef GAME_H
#define GAME_H

#include"block.h"
#include"const.h"
#include<vector>
#include<QTimer>
#include<ctime>
#include"myscene.h"
#include"gamedialog.h"
#include"myscene_sg.h"
#include"singledialog.h"
#include"map.h"
#include"player.h"
#include"shape.h"
#include<QMediaPlayer>

class Game:public QObject
{
    Q_OBJECT
private slots:
    void drop_and_refresh();                                                    //两个player向下掉落的操作

    void player1_rotate();                                                      //player的各种操作槽函数
    void player2_rotate();
    void player1_move_left();
    void player2_move_left();
    void player1_move_right();
    void player2_move_right();
    void player1_drop();
    void player2_drop();

private:
    Map* map;                                                                   //游戏中的地图
    bool pause;                                                                 //判断当前游戏是否暂停

public:
    Game(int player_num = 1);                                                   //构造函数：默认为单人模式
    static myScene* masterScene;                                                //游戏显示界面
    static gameDialog* masterDialog;                                            //游戏显示界面所存在的
    static myScene_sg* masterSScene;
    static singleDialog* masterSDialog;
    static std::vector<Loc> need_to_reset;                                      //每次刷新需要设置为背景图片的方块
    static std::vector<Loc> need_to_set;                                        //每次刷新需要设置颜色的方块
    static std::vector<Color> color_to_set;                                     //需要设置颜色的方块的颜色，与上方一一对应
    ~Game();
    QMediaPlayer *media;                                                        //播放音乐
    QTimer *ptimer;                                                             //计时器
    bool Pause();                                                               //停止计时器达到暂停效果

signals:
    void to_refresh(std::vector<Loc>*,std::vector<Loc>*);                       //发送需要刷新的格子给游戏显示界面
    void dead();                                                                //发送死亡信号
    void score(int);                                                            //发送得分
    void winner(int);                                                           //发送胜者的id
};

#endif // GAME_H
