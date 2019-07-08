/*******************************************************************************
 *
 * 单人模式游戏界面
 *
 ******************************************************************************/

#ifndef SINGLEDIALOG_H
#define SINGLEDIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include "myscene_sg.h"
#include <QLCDNumber>
#include "rank.h"
#include"gameover.h"

class Game;

namespace Ui {
class singleDialog;
}

class singleDialog : public QDialog
{
    Q_OBJECT

public slots:
    void keyPressEvent(QKeyEvent*);                                            //按钮反映函数

public:
    explicit singleDialog(QWidget *parent = nullptr);
    ~singleDialog();

    QLCDNumber* q1;                                                            //显示玩家得分
    QLCDNumber* q2;                                                            //显示当前难度
    Rank r;                                                                    //单人的排行榜
    gameover* gm;                                                              //指向的游戏死亡界面

private slots:
    void on_btn_exit_clicked();
    void on_btn_start_clicked();
    void on_btn_pause_clicked();
    void gameover();

private:
    Ui::singleDialog *ui;
    myScene_sg* sc;                                                            //单人游戏的游戏显示界面
    Game* g;                                                                   //隶属于该界面的单人模式界面

signals:
    void W();                                                                  //各种按钮信号，传递给Game*来反映
    void S();
    void A();
    void D();
};

#endif // SINGLEDIALOG_H
