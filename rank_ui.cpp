/*******************************************************************************
 *
 * 排行榜界面
 *
 ******************************************************************************/

#include "rank_ui.h"
#include "ui_rank_ui.h"
#include "rank.h"
#include<QString>

Rank_ui::Rank_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank_ui)
{
    ui->setupUi(this);
}

Rank_ui::~Rank_ui()
{
    delete ui;
}

void Rank_ui::on_exit_clicked()
{
    this->close();
}

void Rank_ui::refresh(Rank* single,Rank* couple) {
    //single rank:
    this->ui->p_1->
            setText(QString::fromStdString(single->rank_list[0].user_name));
    this->ui->p_2->
            setText(QString::fromStdString(single->rank_list[1].user_name));
    this->ui->p_3->
            setText(QString::fromStdString(single->rank_list[2].user_name));
    this->ui->p_4->
            setText(QString::fromStdString(single->rank_list[3].user_name));
    this->ui->p_5->
            setText(QString::fromStdString(single->rank_list[4].user_name));
    this->ui->s_1->setText(QString::number(single->rank_list[0].score));
    this->ui->s_2->setText(QString::number(single->rank_list[1].score));
    this->ui->s_3->setText(QString::number(single->rank_list[2].score));
    this->ui->s_4->setText(QString::number(single->rank_list[3].score));
    this->ui->s_5->setText(QString::number(single->rank_list[4].score));
    //double rank:
    this->ui->dp_1->
            setText(QString::fromStdString(couple->rank_list[0].user_name));
    this->ui->dp_2->
            setText(QString::fromStdString(couple->rank_list[1].user_name));
    this->ui->dp_3->
            setText(QString::fromStdString(couple->rank_list[2].user_name));
    this->ui->dp_4->
            setText(QString::fromStdString(couple->rank_list[3].user_name));
    this->ui->dp_5->
            setText(QString::fromStdString(couple->rank_list[4].user_name));
    this->ui->ds_1->setText(QString::number(couple->rank_list[0].score));
    this->ui->ds_2->setText(QString::number(couple->rank_list[1].score));
    this->ui->ds_3->setText(QString::number(couple->rank_list[2].score));
    this->ui->ds_4->setText(QString::number(couple->rank_list[3].score));
    this->ui->ds_5->setText(QString::number(couple->rank_list[4].score));
}
