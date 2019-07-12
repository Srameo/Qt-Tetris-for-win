/*******************************************************************************
 *
 * 单人模式死亡界面
 *
 ******************************************************************************/

#include "gameover.h"
#include "ui_gameover.h"
#include"rank.h"
#include <QString>


gameover::gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
}

gameover::~gameover()
{
    delete ui;
}

void gameover::return_score(int score_) {                                      //储存得分并显示
    score = score_;
    ui->score->setText(QString::number(score));
}

void gameover::on_escape_clicked()
{
    this->close();
}

void gameover::on_save_clicked()
{
    r->addScore(ui->pyer_name->text().toStdString(),score);                    //上传得分
    this->close();
}
