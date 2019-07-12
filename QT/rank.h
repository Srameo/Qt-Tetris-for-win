/*******************************************************************************
 *
 * 排行榜类
 *
 ******************************************************************************/

#ifndef RANK_H
#define RANK_H

#include<string>
#include<fstream>
#include<QDir>
#include"const.h"

class Rank {
private:
    struct User {
        std::string user_name;                                                 //用户名
        int score;                                                             //得分
    };
    std::string file_name;                                                     //存档文件夹的名字

public:
    Rank(std::string);
    User rank_list[5];                                                         //总共有多少个玩家在排行榜上
    bool addScore(std::string,int);                                            //将string和int添加到排行榜里
    ~Rank();                                                                   //将存档写入到文件中
};

#endif // RANK_H
