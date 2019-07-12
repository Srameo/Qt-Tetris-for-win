/*******************************************************************************
 *
 * 排行榜
 *
 ******************************************************************************/

#include"rank.h"

Rank::Rank(std::string name) {                                                 //生成存档
    file_name = name;
    std::ifstream fin(name);
    if(fin.is_open()) {
        for(int i = 0; i < RANK_TOP; i++) {
            fin >> rank_list[i].user_name;
            fin >> rank_list[i].score;
        }
        fin.close();
    }
    else {
        for(int i = 0; i < RANK_TOP; i++) {
            rank_list[i].user_name = "computer";
            rank_list[i].score = 500 - i * 100;
        }
    }
}

bool Rank::addScore(std::string User, int Score) {                             //排序并加入存档
    for(int i = 0; i < RANK_TOP; i++) {
        if(Score >= rank_list[i].score) {
            for(int j = RANK_TOP - 1; j > i; j--) {
                rank_list[j].user_name =
                        rank_list[j - 1].user_name;
                rank_list[j].score =
                        rank_list[j - 1].score;
            }
            rank_list[i].score = Score;
            rank_list[i].user_name = User;
            return true;
        }
    }
    return false;
}

Rank::~Rank() {                                                                //将rank上传到存档中储存起来
    QDir dir;
    if(!dir.exists(QObject::tr(RANK_DIR.c_str())))
        dir.mkdir(QObject::tr(RANK_DIR.c_str()));
    std::ofstream fout(file_name);
    for(int i = 0; i < RANK_TOP; i++) {
        fout << rank_list[i].user_name;
        fout << " ";
        fout << rank_list[i].score;
        fout << std::endl;
    }
    fout.close();
}
