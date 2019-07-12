/*******************************************************************************
 *
 * 单人模式游戏界面
 *
 ******************************************************************************/

#include "singledialog.h"
#include "ui_singledialog.h"
#include "game.h"

singleDialog::singleDialog(QWidget *parent) :
    QDialog(parent),
    r(SINGLE_MODE_RANK),
    ui(new Ui::singleDialog)
{
    gm = new class gameover;
    gm->r = &r;
    g = nullptr;
    ui->setupUi(this);
    this->sc = new myScene_sg;
    player1 = new predictScene;
    q1 = ui->score;
    q2 = ui->difficulty;
    this->ui->graphicsView->setScene(sc);
    this->ui->predictView->setScene(player1);
}

singleDialog::~singleDialog()
{
    if(gm)
        delete gm;
    if(sc)
        delete sc;
    if(g)
        delete g;
    if(player1)
        delete player1;
    delete ui;
}

void singleDialog::on_btn_exit_clicked()
{
    if(g) {
        delete g;
        g = nullptr;
    }
    this->close();
}

void singleDialog::on_btn_start_clicked()
{
    if(g) {
        delete g;
        g = nullptr;
    }
    Game::masterSDialog = this;
    Game::masterSScene = sc;
    g = new Game(1);
    ui->btn_start->setText(QString("restart"));
}

void singleDialog::on_btn_pause_clicked()                                       //游戏暂停
{
    if(g) {
        if(g->Pause()) {
            ui->btn_pause->setText(QObject::tr("begin"));
        }
        else {
            ui->btn_pause->setText(QObject::tr("pause"));
        }
    }
}

void singleDialog::gameover()
{
    this->gm->exec();
}

void singleDialog::keyPressEvent(QKeyEvent*event) {
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
    }
}
