/*******************************************************************************
 *
 * 帮助界面
 *
 ******************************************************************************/

#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:
    void on_btn_exit__clicked();

private:
    Ui::help *ui;
};

#endif // HELP_H
