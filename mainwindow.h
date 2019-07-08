/*******************************************************************************
 *
 * 主窗口界面界面
 *
 ******************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "choose.h"
#include "help.h"
#include "rank_ui.h"

class Rank;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:    
    void on_btn_help_clicked();
    void on_btn_exit_clicked();
    void on_btn_start_clicked();
    void on_rank_clicked();

private:
    Ui::MainWindow *ui;
    choose a;                                                                     //选择窗口
    help h;                                                                       //帮助窗口
    Rank_ui r;                                                                    //排行榜窗口

signals:
    void refresh_rank(Rank*,Rank*);
};

#endif // MAINWINDOW_H
