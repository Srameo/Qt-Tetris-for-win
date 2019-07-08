/*******************************************************************************
 *
 * 单人模式显示界面
 *
 ******************************************************************************/

#include "myscene_sg.h"
#include"game.h"

myScene_sg::myScene_sg(QObject *parent) : QGraphicsScene(parent)              //构造界面
{
    int i = 0;
    for (i = 0;i < MAP_HEIGHT * MAP_WIDTH[0]; i++) {
        this->item_sg[i] = new myItem;
        this->item_sg[i]->setPos(
                    i%MAP_WIDTH[0]*this->item_sg[i]->boundingRect().height(),
                    i/MAP_WIDTH[0]*this->item_sg[i]->boundingRect().width());
        this->addItem(this->item_sg[i]);
    }
}

void myScene_sg::refresh(std::vector<Loc>* r,std::vector<Loc>* s) {           //刷新方块显示
    int length = r->size();
    for(int i = 0; i < length; i++) {
        reset((*r)[i]);
    }
    r->clear();
    length = s->size();
    for(int i = 0; i < length; i++) {
        set((*s)[i],Game::color_to_set[i]);
    }
    Game::color_to_set.clear();
    s->clear();
}

void myScene_sg::set(Loc l,Color c) {                                           //按照颜色刷新界面
    if(l.y >= 0) {
        switch(c) {
        case Blue:
            this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
                    setPic(":/new/prefix1/QT resourse/blue.jpg");
            break;
        case Red:
            this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
                    setPic(":/new/prefix1/QT resourse/red.jpg");
            break;
        case DarkGreen:
            this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
                    setPic(":/new/prefix1/QT resourse/dark_green.jpg");
            break;
        case Gray:
            this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
                    setPic(":/new/prefix1/QT resourse/gray.jpg");
            break;
        case Green:
            this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
                    setPic(":/new/prefix1/QT resourse/green.jpg");
            break;
        case Purple:
            this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
                    setPic(":/new/prefix1/QT resourse/purple.jpg");
            break;
        case Yellow:
            this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
                    setPic(":/new/prefix1/QT resourse/yellow.jpg");
            break;
        }
    }
}

void myScene_sg::reset(Loc l) {                                                  //重新设置为背景图标
    if(l.y >= 0)
        this->item_sg[l.x + MAP_WIDTH[0] * l.y]->
            setPic(":/new/prefix1/QT resourse/background.jpg");
}
