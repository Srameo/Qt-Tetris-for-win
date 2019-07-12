/*******************************************************************************
 *
 * 预测下一个方块的窗口类的各种函数实现
 *
 ******************************************************************************/

#include"predict.h"

predictScene::predictScene(QObject *parent) : QGraphicsScene(parent)           //生成界面
{
    last_set[0] = 0;
    last_set[1] = 0;
    last_set[2] = 0;
    last_set[3] = 0;
    for (int i = 0;i < 16; i++) {
        this->item[i] = new myItem;
        this->item[i]->setPos(
                    i%4*this->item[i]->boundingRect().height(),
                    i/4*this->item[i]->boundingRect().width());
        this->addItem(this->item[i]);
    }
}

void predictScene::set(Color c) {                                              //根据颜色设置不同的下一个方块
    this->reset();
    switch(c) {
    case Red:
        this->item[1]->setPic(":/new/prefix1/QT resourse/red.jpg");
        this->item[5]->setPic(":/new/prefix1/QT resourse/red.jpg");
        this->item[9]->setPic(":/new/prefix1/QT resourse/red.jpg");
        this->item[13]->setPic(":/new/prefix1/QT resourse/red.jpg");
        last_set[0] = 1;
        last_set[1] = 5;
        last_set[2] = 9;
        last_set[3] = 13;
        break;
    case Yellow:
        this->item[2]->setPic(":/new/prefix1/QT resourse/yellow.jpg");
        this->item[6]->setPic(":/new/prefix1/QT resourse/yellow.jpg");
        this->item[10]->setPic(":/new/prefix1/QT resourse/yellow.jpg");
        this->item[9]->setPic(":/new/prefix1/QT resourse/yellow.jpg");
        last_set[0] = 2;
        last_set[1] = 6;
        last_set[2] = 10;
        last_set[3] = 9;
        break;
    case Blue:
        this->item[5]->setPic(":/new/prefix1/QT resourse/blue.jpg");
        this->item[9]->setPic(":/new/prefix1/QT resourse/blue.jpg");
        this->item[13]->setPic(":/new/prefix1/QT resourse/blue.jpg");
        this->item[14]->setPic(":/new/prefix1/QT resourse/blue.jpg");
        last_set[0] = 5;
        last_set[1] = 9;
        last_set[2] = 13;
        last_set[3] = 14;
        break;
    case Green:
        this->item[4]->setPic(":/new/prefix1/QT resourse/green.jpg");
        this->item[5]->setPic(":/new/prefix1/QT resourse/green.jpg");
        this->item[6]->setPic(":/new/prefix1/QT resourse/green.jpg");
        this->item[9]->setPic(":/new/prefix1/QT resourse/green.jpg");
        last_set[0] = 4;
        last_set[1] = 5;
        last_set[2] = 6;
        last_set[3] = 9;
        break;
    case DarkGreen:
        this->item[9]->setPic(":/new/prefix1/QT resourse/dark_green.jpg");
        this->item[6]->setPic(":/new/prefix1/QT resourse/dark_green.jpg");
        this->item[7]->setPic(":/new/prefix1/QT resourse/dark_green.jpg");
        this->item[10]->setPic(":/new/prefix1/QT resourse/dark_green.jpg");
        last_set[0] = 9;
        last_set[1] = 6;
        last_set[2] = 7;
        last_set[3] = 10;
        break;
    case Purple:
        this->item[5]->setPic(":/new/prefix1/QT resourse/purple.jpg");
        this->item[6]->setPic(":/new/prefix1/QT resourse/purple.jpg");
        this->item[10]->setPic(":/new/prefix1/QT resourse/purple.jpg");
        this->item[11]->setPic(":/new/prefix1/QT resourse/purple.jpg");
        last_set[0] = 5;
        last_set[1] = 6;
        last_set[2] = 10;
        last_set[3] = 11;
        break;
    case Gray:
        this->item[10]->setPic(":/new/prefix1/QT resourse/gray.jpg");
        this->item[5]->setPic(":/new/prefix1/QT resourse/gray.jpg");
        this->item[6]->setPic(":/new/prefix1/QT resourse/gray.jpg");
        this->item[9]->setPic(":/new/prefix1/QT resourse/gray.jpg");
        last_set[0] = 10;
        last_set[1] = 5;
        last_set[2] = 6;
        last_set[3] = 9;
        break;
    }
}

void predictScene::reset() {                                              //将上一个方块的图像去掉
    for(int i = 0; i < 4; i++) {
        item[last_set[i]]->
                setPic(":/new/prefix1/QT resourse/background.jpg");
    }
}
