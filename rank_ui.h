/*******************************************************************************
 *
 * 排行榜显示界面
 *
 ******************************************************************************/

#ifndef RANK_UI_H
#define RANK_UI_H

#include <QDialog>

class Rank;

namespace Ui {
class Rank_ui;
}

class Rank_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Rank_ui(QWidget *parent = nullptr);
    ~Rank_ui();

public slots:
    void refresh(Rank*,Rank*);                                                 //接受MainWindow传回要刷新的排行榜指针

private slots:
    void on_exit_clicked();

private:
    Ui::Rank_ui *ui;
};

#endif // RANK_UI_H
