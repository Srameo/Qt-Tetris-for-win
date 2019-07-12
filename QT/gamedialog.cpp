/*******************************************************************************
 *
 * 双人模式游戏界面
 *
 ******************************************************************************/

#include "gamedialog.h"
#include "ui_gamedialog.h"
#include "game.h"

gameDialog::gameDialog(QWidget *parent) :
    QDialog(parent),
    r(DOUBLE_MODE_RANK),
    ui(new Ui::gameDialog)
{
    gm = new gameover_d;
    gm->r = &r;
    g = nullptr;
    ui->setupUi(this);
    this->sc = new myScene;
    player1 = new predictScene;
    player2 = new predictScene;
    q1 = ui->lcdNumber;
    q2 = ui->lcdNumber_2;
    this->ui->graphicsView->setScene(sc);
    this->ui->player1next->setScene(player1);
    this->ui->player2next->setScene(player2);
}

gameDialog::~gameDialog()
{
    if(gm)
        delete gm;
    if(sc)
        delete sc;
    if(g)
        delete g;
    delete ui;
}

void gameDialog::on_gbtn_exit_clicked()
{
    if(g) {
        delete g;
        g = nullptr;
    }
    this->close();
}

void gameDialog::on_gbtn_start_clicked()
{
    if(g) {
        delete g;
        g = nullptr;
    }
    Game::masterDialog = this;
    Game::masterScene = sc;
    g = new Game(2);
    ui->gbtn_start->setText(QString("restart"));
}

void gameDialog::on_gbtn_pause_clicked()                                        //游戏暂停
{
    if(g) {
        if(g->Pause()) {
            ui->gbtn_pause->setText(QObject::tr("begin"));
        }
        else {
            ui->gbtn_pause->setText(QObject::tr("pause"));
        }
    }
}


void gameDialog::gameover()
{
    this->gm->exec();
}

void gameDialog::keyPressEvent(QKeyEvent*event) {
    int Key = event->key();
    Qt::Key key  = static_cast<Qt::Key>(Key);
    switch(key) {
    case Qt::Key_W:
        emit W();
        break;
    case Qt::Key_S:
        emit S();
        break;
    case Qt::Key_A:
        emit A();
        break;
    case Qt::Key_D:
        emit D();
        break;
    case Qt::Key_J:
        emit Left();
        break;
    case Qt::Key_I:
        emit Up();
        break;
    case Qt::Key_L:
        emit Right();
        break;
    case Qt::Key_K:
        emit Down();
        break;
    }
}
