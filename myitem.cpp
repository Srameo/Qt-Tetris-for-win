/*******************************************************************************
 *
 * 图源类
 *
 ******************************************************************************/

#include "myitem.h"
#include <QPixmap>
myItem::myItem()
{
    this->setPixmap(QPixmap(":/new/prefix1/QT resourse/background.jpg"));

}

void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}
