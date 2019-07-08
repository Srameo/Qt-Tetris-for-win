/*******************************************************************************
 *
 * 双人游戏死亡界面
 *
 ******************************************************************************/

#ifndef GAMEOVER_D_H
#define GAMEOVER_D_H

#include <QDialog>

class Rank;

namespace Ui {
class gameover_d;
}

class gameover_d : public QDialog
{
    Q_OBJECT

public slots:
    void return_score(int);                                                    //从doubleDialog里回传得分
    void return_winner(int);                                                   //从doubleDialog里回传胜利者id

public:
    explicit gameover_d(QWidget *parent = nullptr);
    ~gameover_d();

    int score;                                                                 //记录胜者得分，方便显示
    Rank *r;                                                                   //得分和用户名所要记录到的排行榜的指针

private slots:
    void on_waive_clicked();
    void on_save_clicked();

private:
    Ui::gameover_d *ui;
};

#endif // GAMEOVER_D_H
