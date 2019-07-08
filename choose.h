#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>
#include <gamedialog.h>
#include <singledialog.h>

namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();

    singleDialog single;
    gameDialog couple;

private slots:
    void on_btn_single_clicked();
    void on_btn_couple_clicked();
    void on_btn_escape_clicked();

private:
    Ui::choose *ui;
};

#endif // CHOOSE_H
