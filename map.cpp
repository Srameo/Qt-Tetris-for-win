/*******************************************************************************
 *
 * 地图类
 *
 ******************************************************************************/

#include"require.h"

Map::Map(int player_num):                                                      //默认游戏人数1
    blocks(0),height(MAP_HEIGHT),
    width(MAP_WIDTH[player_num - 1]),
    size(width,height)
{
    velocity = VELOCITY;
    difficulty = 1;                                                            //设置最初的难度
    total_lines = 0;                                                           //初始化一共消的行数
    if(player_num == 1) {                                                      //生成player
        Player* new_player = new Player(Loc((width - 1) / 2,0),this);
        player.push_back(new_player);
    }
    else {
        Player* new_player1 = new Player(Loc((width - 2) / 3,0),this);
        Player* new_player2 = new Player(Loc((width - 2) * 2 / 3,0),this);
        player.push_back(new_player1);
        player.push_back(new_player2);
    }
}

bool Map::isCollided(Loc l) const {
    if(!(l.x >= 0 && l < size))return true;                                    //判断是否和边界碰撞
    int length = blocks.size();
    for(int i = 0; i < length; i++)                                            //判断是否与其他方块碰撞
        if(blocks[i])                                                          //判断blocks[i]是否是NULL
            if(blocks[i]->loc == l)
                return true;
    return false;
}

bool Map::isMovingCollided(Player* p, Loc l[4]) const {                        //player移动到Loc判断是否和另一个碰撞
    if(player.size() > 1) {
        Player* other_player = (player[0] == p) ? player[1]:player[0];         //找到第二个player
        if(other_player->control) {
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(l[i] == other_player->control->p[j]->loc)
                        return true;
        }
    }
    return false;
}

int Map::have(int y) const{                                                    //计算第int行所拥有的blocks的个数
    int ans = 0, length = blocks.size();
    for(int i = 0; i < length; i++)
        if(blocks[i])                                                          //判断blocks[i]是否是NULL
            if(y == blocks[i]->loc.y)
                ans++;
    return ans;
}

void Map::remove(int y) {                                                      //消除第int行的数据，并将其他格子在那上边的向下移动一个
    int length = blocks.size();
    for(int i = 0; i < length; i++) {
        if(blocks[i]){
            if(blocks[i]->loc.y < y){                                          //如果block在y的上方，则向下移动一格
                Game::need_to_reset.push_back(blocks[i]->loc);
                blocks[i]->loc.y++;
                Game::need_to_set.push_back(blocks[i]->loc);
                Game::color_to_set.push_back(blocks[i]->color);
            }
            else if(blocks[i]->loc.y == y) {
                Game::need_to_reset.push_back(blocks[i]->loc);
                delete blocks[i];
                blocks[i] = nullptr;
            }
        }
    }
    emit g->to_refresh(&Game::need_to_reset,
                       &Game::need_to_set);
}

int Map::remove() {                                                            //消除整行并返回消除行数,只需判断最后四个添加到blocks里的元素
    int ans = 0;
    int length = blocks.size();
    if(length >= 4) {
        for(int i = 1; i <= 4; i++)
            if(blocks[length - i]){                                            //判断blocks[i]是否是NULL
                int num = have(blocks[length - i]->loc.y);
                if(num == width) {
                    ans++;
                    remove(blocks[length - i]->loc.y);
                }
            }
    }
    if(ans) {
        g->media->play();
    }
    return ans;
}

bool Map::live() const {                                                       //判断游戏能否继续,只需判断最后四个添加到blocks里的元素
    int length = blocks.size();
    if(length >= 4) {
        for(int i = 1; i <= 4; i++)
            if(blocks[length - i])                                             //判断blocks[i]是否是NULL
                if(blocks[length - i]->loc.y < 0)
                    return false;
    }
    return true;
}

void Map::addDifficulty() {                                                    //增加难度
    velocity *= (1 - DIFFICULT_RATE);
    difficulty++;
    g->ptimer->setInterval(velocity);
}

Map::~Map() {
    int length = blocks.size();
    if(length) {
        for(int i = 0; i < length; i++)                                         //删除所有使用new新建的元素，释放内存
            if(blocks[i]) {
                delete blocks[i];
                blocks[i] = nullptr;
            }
    }
    for(int i = 0; i < player.size(); i++)
        if(player[i]) {
            delete player[i];
            player[i] = nullptr;
        }
}
