/*******************************************************************************
 *
 * 地图类相关函数的实现
 *
 ******************************************************************************/

#include"require.h"

gameDialog* Game::masterDialog = nullptr;
myScene* Game::masterScene = nullptr;
singleDialog* Game::masterSDialog = nullptr;
myScene_sg* Game::masterSScene = nullptr;
std::vector<Loc> Game::need_to_reset = {};
std::vector<Loc> Game::need_to_set = {};
std::vector<Color> Game::color_to_set = {};

Game::Game(int player_num):
    QObject(nullptr),
    pause(false)
{
    media = new QMediaPlayer();
    media->setVolume(100);
    ptimer = new QTimer;                                                      //新建计时器
    srand((unsigned)time(nullptr));                                           //防止随机数生成总是相同
    map = new Map(player_num);                                                //新建地图
    map->g = this;                                                            //将map中的Game指针指向这个游戏指针，便于之后map与Game互动
    media->setMedia(QUrl::fromLocalFile(
                        "C:/Users/Mechrev/Desktop/Tetris/QT resourse/line_clear.w4a"));
    if(player_num == 2) {
        connect(this,
                SIGNAL(to_refresh(std::vector<Loc>*,std::vector<Loc>*)),      //连接信号和槽
                masterScene,
                SLOT(refresh(std::vector<Loc>*,std::vector<Loc>*)));
        connect(ptimer,SIGNAL(timeout()),this,SLOT(drop_and_refresh()));
        connect(this,SIGNAL(dead()),ptimer,SLOT(stop()));
        connect(masterDialog,SIGNAL(W()),this,SLOT(player1_rotate()));
        connect(masterDialog,SIGNAL(S()),this,SLOT(player1_drop()));
        connect(masterDialog,SIGNAL(A()),this,SLOT(player1_move_left()));
        connect(masterDialog,SIGNAL(D()),this,SLOT(player1_move_right()));
        connect(masterDialog,SIGNAL(Up()),this,SLOT(player2_rotate()));
        connect(masterDialog,SIGNAL(Down()),this,SLOT(player2_drop()));
        connect(masterDialog,SIGNAL(Left()),this,SLOT(player2_move_left()));
        connect(masterDialog,SIGNAL(Right()),
                this,SLOT(player2_move_right()));
        connect(this,SIGNAL(dead()),masterDialog,SLOT(gameover()));
        connect(this,SIGNAL(score(int)),
                masterDialog->gm,SLOT(return_score(int)));
        connect(this,SIGNAL(winner(int)),
                masterDialog->gm,SLOT(return_winner(int)));
    }
    else {
        connect(this,
                SIGNAL(to_refresh(std::vector<Loc>*,std::vector<Loc>*)),     //连接信号和槽
                masterSScene,
                SLOT(refresh(std::vector<Loc>*,std::vector<Loc>*)));
        connect(ptimer,SIGNAL(timeout()),this,SLOT(drop_and_refresh()));
        connect(this,SIGNAL(dead()),ptimer,SLOT(stop()));
        connect(masterSDialog,SIGNAL(W()),this,SLOT(player1_rotate()));
        connect(masterSDialog,SIGNAL(S()),this,SLOT(player1_drop()));
        connect(masterSDialog,SIGNAL(A()),this,SLOT(player1_move_left()));
        connect(masterSDialog,SIGNAL(D()),this,SLOT(player1_move_right()));
        connect(this,SIGNAL(dead()),masterSDialog,SLOT(gameover()));
        connect(this,SIGNAL(score(int)),
                masterSDialog->gm,SLOT(return_score(int)));
    }
    ptimer->start(VELOCITY);
}

void Game::drop_and_refresh() {                                                   //用于接收QTimer的信号
    if(!map->live()) {                                                            //如果判断死亡，返回得分，发射死亡信号
        if(map->player.size() == 2) {
            if(map->player[0]->score() >= map->player[1]->score()) {
                emit score(map->player[0]->score());
                emit winner(1);
            }
            else {
                emit score(map->player[1]->score());
                emit winner(2);
            }
        }
        else {
            emit score(map->player[0]->score());
        }
        emit dead();
        return;
    }
    for(int i = 0; i < map->player.size(); i++) {                                 //向下走一个或者生成新的Shape
        if(map->player[i]->control){
            map->player[i]->drop();
        }
        else
            map->player[i]->createShape();
    }
    if(map->total_lines / LINES_TO_ADDDIFFCULTY + 1 >                             //是否增加难度
            map->difficulty &&
            map->difficulty < TOP_DIFFICULTY)
        map->addDifficulty();
    if(need_to_reset.size() || need_to_set.size())                                //返回需要刷新的方块
        emit to_refresh(&need_to_reset,&need_to_set);
    if(map->player.size() == 2) {                                                 //显示得分
        masterDialog->q2->display(map->player[1]->score());
        masterDialog->q1->display(map->player[0]->score());
    }
    else {
        masterSDialog->q2->display(map->difficulty);
        masterSDialog->q1->display(map->player[0]->score());
    }
}

void Game::player1_rotate() {                                                      //以下均用于接收按键信号
    map->player[0]->rotate();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

void Game::player2_rotate() {
    map->player[1]->rotate();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

void Game::player1_move_left() {
    map->player[0]->move_left();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

void Game::player2_move_left() {
    map->player[1]->move_left();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

void Game::player1_move_right() {
    map->player[0]->move_right();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

void Game::player2_move_right() {
    map->player[1]->move_right();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

void Game::player1_drop() {
    map->player[0]->drop();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

void Game::player2_drop() {
    map->player[1]->drop();
    if(need_to_reset.size() || need_to_set.size())
        emit to_refresh(&need_to_reset,&need_to_set);
}

bool Game::Pause() {
    if(pause)
        ptimer->start(map->velocity);
    else
        ptimer->stop();
    pause != pause;
    return pause;
}

Game::~Game() {                                                               //刷新界面并释放内存
    if(map) {
        for(int i = 0; i < map->blocks.size();i++) {                          //刷新界面（将所有方块全部清空）
            if(map->blocks[i])
                need_to_reset.push_back(map->blocks[i]->loc);
        }
        for(int i = 0; i < map->player.size(); i++){
            map->player[i]->map = nullptr;
            if(map->player[i]->control) {
                map->player[i]->control->map = nullptr;
                for(int j = 0; j < 4; j++) {
                    need_to_reset.push_back
                            (map->player[i]->control->p[j]->loc);
                }
            }
        }
        delete map;
    }
    if(need_to_reset.size())
        emit to_refresh(&need_to_reset,&need_to_set);
    this->disconnect();
    if(map->player.size() == 2)
        disconnect(masterDialog,nullptr,this,nullptr);
    else
        disconnect(masterSDialog,nullptr,this,nullptr);
    if(ptimer)
        delete ptimer;
    if(media)
        delete media;
}
