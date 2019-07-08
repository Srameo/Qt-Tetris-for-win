/*******************************************************************************
 *
 * 双人游戏界面
 *
 ******************************************************************************/

#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include "myscene.h"
#include <QLCDNumber>
#include "rank.h"
#include "gameover_d.h"

class Game;

namespace Ui {
class gameDialog;
}

class gameDialog : public QDialog
{
    Q_OBJECT

public slots:
    void keyPressEvent(QKeyEvent*);                                            //按钮反映函数

public:
    explicit gameDialog(QWidget *parent = nullptr);
    ~gameDialog();

    QLCDNumber* q1;                                                            //显示玩家一得分
    QLCDNumber* q2;                                                            //显示玩家二得分
    Rank r;                                                                    //双人模式的排行榜
    gameover_d* gm;                                                            //双人游戏界面死亡时弹出的界面


private slots:
    void on_gbtn_exit_clicked();
    void on_gbtn_start_clicked();
    void on_gbtn_pause_clicked();
    void gameover();                                                           //打开死亡界面

private:
    Ui::gameDialog *ui;
    myScene* sc;                                                               //游戏显示界面
    Game* g;                                                                   //对应的游戏

signals:
    void W();                                                                  //各种按钮信号，传递给Game*来反映
    void S();
    void A();
    void D();
    void Up();
    void Down();
    void Left();
    void Right();
};

#endif // GAMEDIALOG_H
