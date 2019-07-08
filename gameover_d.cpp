/*******************************************************************************
 *
 * 双人模式死亡界面
 *
 ******************************************************************************/

#include "gameover_d.h"
#include "ui_gameover_d.h"
#include"rank.h"

gameover_d::gameover_d(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover_d)
{
    ui->setupUi(this);
}

gameover_d::~gameover_d()
{
    delete ui;
}

void gameover_d::on_waive_clicked()
{
    this->close();
}

void gameover_d::return_score(int score_) {                                    //储存得分并显示
    score = score_;
    ui->score->setText(QString::number(score));
}

void gameover_d::return_winner(int winner) {                                   //显示胜者
    ui->winner->setText(QString::number(winner));
}

void gameover_d::on_save_clicked()
{
    r->addScore(ui->pyer_name->text().toStdString(),score);                    //上传用户名和得分
    this->close();
}
