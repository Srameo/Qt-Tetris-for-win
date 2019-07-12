#include "choose.h"
#include "ui_choose.h"

choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
}

choose::~choose()
{
    delete ui;
}

void choose::on_btn_single_clicked()
{
    this->single.exec();
    this->close();
}

void choose::on_btn_couple_clicked()
{
    this->couple.exec();
    this->close();
}

void choose::on_btn_escape_clicked()
{
    this->close();
}
