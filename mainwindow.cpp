/*******************************************************************************
 *
 * 主窗口
 *
 ******************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(this,SIGNAL(refresh_rank(Rank*,Rank*)),
            &r,SLOT(refresh(Rank*,Rank*)));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_help_clicked()
{
    h.exec();
}

void MainWindow::on_btn_exit_clicked()
{
    this->close();
}


void MainWindow::on_btn_start_clicked()
{
    this->a.exec();


}

void MainWindow::on_rank_clicked()
{
    emit refresh_rank(&a.single.r,&a.couple.r);                                  //刷新rank
    this->r.exec();
}
