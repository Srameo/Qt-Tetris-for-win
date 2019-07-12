/*******************************************************************************
 *
 * 双人模式游戏显示界面
 *
 ******************************************************************************/

#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <myitem.h>
#include"loc.h"
#include"const.h"

class myScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit myScene(QObject *parent = nullptr);

    void set(Loc,Color);                                                       //将Loc设置为Color颜色
    void reset(Loc);                                                           //将Loc设置为背景图片

public slots:
    void refresh(std::vector<Loc>*,std::vector<Loc>*);                         //接受Game传递过来的需要设置的方块vector

private:
    myItem* item[360];                                                         //地图总大小

};

#endif // MYSCENE_H
