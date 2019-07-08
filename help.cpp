/*******************************************************************************
 *
 * 帮助界面
 *
 ******************************************************************************/

#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_btn_exit__clicked()
{
    this->close();
}
