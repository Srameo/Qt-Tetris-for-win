/*******************************************************************************
 *
 * 预测下一个方块的窗口类
 *
 ******************************************************************************/

#ifndef PREDICT_H
#define PREDICT_H

#include <QObject>
#include <QGraphicsScene>
#include <myitem.h>
#include"const.h"

class Player;

class predictScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit predictScene(QObject *parent = nullptr);

    void set(Color);                                                           //将Loc设置为Color颜色
    void reset();                                                              //将Loc设置为背景图片
    int last_set[4];

private:
    myItem* item[16];                                                          //地图总大小
};

#endif // PREDICT_H
