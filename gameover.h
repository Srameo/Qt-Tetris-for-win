/*******************************************************************************
 *
 * 单人模式游戏死亡界面
 *
 ******************************************************************************/

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

class Rank;

namespace Ui {
class gameover;
}

class gameover : public QDialog
{
    Q_OBJECT

public slots:
    void return_score(int);                                                    //从singleDialog里回传得分

public:
    explicit gameover(QWidget *parent = nullptr);
    ~gameover();

    int score;                                                                 //记录得分，方便显示到界面上
    Rank *r;                                                                   //得分和用户名所要记录到的排行榜的指针

private slots:
    void on_escape_clicked();
    void on_save_clicked();

private:
    Ui::gameover *ui;
};

#endif // GAMEOVER_H
