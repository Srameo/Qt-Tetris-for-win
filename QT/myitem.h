/*******************************************************************************
 *
 * 双人游戏死亡界面
 *
 ******************************************************************************/

#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsPixmapItem>
#include <QString>

class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    void setPic(QString path);                                                 //设置该图片块显示的颜色
};

#endif // MYITEM_H
