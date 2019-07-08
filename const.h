/*******************************************************************************
 *
 * 所有常数均储存在该头文件里
 *
 ******************************************************************************/

#ifndef CONST_H
#define CONST_H

#include<string>
#include"loc.h"

const int MAP_HEIGHT = 18;                                                     //地图高度：格子数*修改也无效*
const int MAP_WIDTH[] = {11, 20};                                              //单人或双人地图宽度：格子数*修改也无效*
const int VELOCITY = 500;                                                      //最初的速度：毫秒

enum Color {Red, Yellow, Blue, Green, DarkGreen, Purple, Gray};                //方便访问颜色

const int LINE_SCORE = 10;                                                     //消除一行所加的分数
const int LINES_TO_ADDDIFFCULTY = 5;                                           //消除几行增加难度
const int TOP_DIFFICULTY = 10;                                                 //最高难度

const double DIFFICULT_RATE = 0.2;                                             //增加一次难度速度增加的比率

const int RANK_TOP = 5;                                                        //排行榜记录的人员上限*修改也无效*

const std::string RANK_DIR = "_save_files_";                                   //存档的文件夹
const std::string SINGLE_MODE_RANK = RANK_DIR + "//" + "singlemode";           //单人模式存档名
const std::string DOUBLE_MODE_RANK = RANK_DIR + "//" + "doublemode";           //双人模式存档名

const Dire Up(0, -1), Down(0, 1), Left(-1, 0), Right(1, 0), Stop(0, 0);        //direction:上下左右停五个操作

#endif // CONST_H
