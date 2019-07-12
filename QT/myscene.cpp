/*******************************************************************************
 *
 * 双人游戏显示界面
 *
 ******************************************************************************/

#include "myscene.h"
#include "game.h"

myScene::myScene(QObject *parent) : QGraphicsScene(parent)                    //生成界面
{
    int i = 0;
    for (i = 0;i < MAP_HEIGHT * MAP_WIDTH[1]; i++) {
        this->item[i] = new myItem;
        this->item[i]->setPos(
                    i%MAP_WIDTH[1]*this->item[i]->boundingRect().height(),
                    i/MAP_WIDTH[1]*this->item[i]->boundingRect().width());
        this->addItem(this->item[i]);
    }
}

void myScene::refresh(std::vector<Loc>* r,std::vector<Loc>* s) {              //刷新方块显示
    int length = r->size();
    for(int i = 0; i < length; i++) {
        reset((*r)[i]);
    }
    r->clear();                                                               //清空vector,防止下次再次刷新
    length = s->size();
    for(int i = 0; i < length; i++) {
        set((*s)[i],Game::color_to_set[i]);
    }
    Game::color_to_set.clear();
    s->clear();
}

void myScene::set(Loc l,Color c) {                                            //按照颜色刷新界面
    if(l.y >= 0) {
        switch(c) {
        case Blue:
            this->item[l.x + MAP_WIDTH[1] * l.y]->
                    setPic(":/new/prefix1/QT resourse/blue.jpg");
            break;
        case Red:
            this->item[l.x + MAP_WIDTH[1] * l.y]->
                    setPic(":/new/prefix1/QT resourse/red.jpg");
            break;
        case DarkGreen:
            this->item[l.x + MAP_WIDTH[1] * l.y]->
                    setPic(":/new/prefix1/QT resourse/dark_green.jpg");
            break;
        case Gray:
            this->item[l.x + MAP_WIDTH[1] * l.y]->
                    setPic(":/new/prefix1/QT resourse/gray.jpg");
            break;
        case Green:
            this->item[l.x + MAP_WIDTH[1] * l.y]->
                    setPic(":/new/prefix1/QT resourse/green.jpg");
            break;
        case Purple:
            this->item[l.x + MAP_WIDTH[1] * l.y]->
                    setPic(":/new/prefix1/QT resourse/purple.jpg");
            break;
        case Yellow:
            this->item[l.x + MAP_WIDTH[1] * l.y]->
                    setPic(":/new/prefix1/QT resourse/yellow.jpg");
            break;
        }
    }
}

void myScene::reset(Loc l) {                                                   //重新设置为背景图标
    if(l.y >= 0)
        this->item[l.x + MAP_WIDTH[1] * l.y]->
            setPic(":/new/prefix1/QT resourse/background.jpg");
}
