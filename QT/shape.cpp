/*******************************************************************************
 *
 * 所有形状类
 *
 ******************************************************************************/

#include"require.h"

Map* Shape::map = nullptr;

Shape::Shape(Player* plar) {
    if(!map)map = plar->map;
    player = plar;
    p.resize(4);
    move = true;
}

Loc Shape::rotate(Loc l) const {                                                //旋转单独一个Loc
        return Loc(-l.y, l.x);
}

bool Shape::drop() {
    if(!move)return false;
    Loc new_p[4];
    for (int i = 0; i < 4; i++) {                                               //判断是否相撞
        new_p[i] = p[i]->loc + Down;
        if(isCollided(new_p[i]))return false;
    }
    if(isMovingCollided(new_p)) {                                               //判断是否和另一个相撞
        Player* other_player =                                                  //找到第二个player
                (map->player[0] == player) ? map->player[1]:map->player[0];
        if(!other_player->drop())                                               //如果另一个没法向下则return false
            return false;
    }
    for (int i = 0; i < 4; i++) {
        Game::need_to_reset.push_back(p[i]->loc);
        Game::need_to_set.push_back(new_p[i]);
        Game::color_to_set.push_back(p[i]->color);
        p[i]->loc = new_p[i];
    }
    emit map->g->to_refresh(&Game::need_to_reset,
                       &Game::need_to_set);
    return true;
}

bool Shape::move_left() {
    if(!move)return false;
    Loc new_p[4];
    for (int i = 0; i < 4; i++) {
        new_p[i] = p[i]->loc + Left;
        if(isCollided(new_p[i]))return false;
    }
    if(isMovingCollided(new_p)) {
        Player* other_player =
                (map->player[0] == player) ? map->player[1]:map->player[0];
        if(!other_player->move_left())
            return false;
    }
    for (int i = 0; i < 4; i++){
        Game::need_to_reset.push_back(p[i]->loc);
        Game::need_to_set.push_back(new_p[i]);
        Game::color_to_set.push_back(p[i]->color);
        p[i]->loc = new_p[i];
    }
    return true;
}

bool Shape::move_right() {
    if(!move)return false;
    Loc new_p[4];
    for (int i = 0; i < 4; i++) {
        new_p[i] = p[i]->loc + Right;
        if(isCollided(new_p[i]))return false;
    }
    if(isMovingCollided(new_p)) {
        Player* other_player =
                (map->player[0] == player) ? map->player[1]:map->player[0];
        if(!other_player->move_right())
            return false;
    }
    for (int i = 0; i < 4; i++) {
        Game::need_to_reset.push_back(p[i]->loc);
        Game::need_to_set.push_back(new_p[i]);
        Game::color_to_set.push_back(p[i]->color);
        p[i]->loc = new_p[i];
    }
    return true;
}

bool Shape::rotate() {
    if(!move)return false;
    Loc new_p[4];
    for (int i = 0; i < 4; i++) {                                               //绕中心旋转
        Loc rotated = rotate(p[i]->loc - center->loc);
        new_p[i] = rotated + center->loc;
        if(isCollided(new_p[i]))return false;
    }
    if(isMovingCollided(new_p))return false;
    for (int i = 0; i < p.size(); i++) {
        Game::need_to_reset.push_back(p[i]->loc);
        Game::need_to_set.push_back(new_p[i]);
        Game::color_to_set.push_back(p[i]->color);
        p[i]->loc = new_p[i];
    }
    return true;
}

Shape::~Shape() {
    move = false;
    if(map) {
        map->blocks.push_back(p[0]);                                            //将所有block加入到blocks
        map->blocks.push_back(p[1]);
        map->blocks.push_back(p[2]);
        map->blocks.push_back(p[3]);
        if(int lines = map->remove()) {
            player->Score += lines * LINE_SCORE * map->difficulty +
                    float((lines - 1)) / 2 * LINE_SCORE;
            map->total_lines += lines;
        }
    }
}

bool shapeI::rotate() {                                                         //先判断为那种状态之后，再进行旋转
    if(!move)return false;
    bool rect = false;
    if(p[0]->loc.y - p[1]->loc.y < 0)rect = true;
    Loc new_p[4];
    if(rect) {
        new_p[0] = Loc(p[0]->loc.x + 1, p[0]->loc.y + 1);
        new_p[1] = Loc(p[1]->loc.x, p[1]->loc.y);
        new_p[2] = Loc(p[2]->loc.x - 1, p[2]->loc.y - 1);
        new_p[3] = Loc(p[3]->loc.x - 2, p[3]->loc.y - 2);
    }
    else {
        new_p[0] = Loc(p[0]->loc.x - 1, p[0]->loc.y - 1);
        new_p[1] = Loc(p[1]->loc.x, p[1]->loc.y);
        new_p[2] = Loc(p[2]->loc.x + 1, p[2]->loc.y + 1);
        new_p[3] = Loc(p[3]->loc.x + 2, p[3]->loc.y + 2);
    }
    if(isMovingCollided(new_p))return false;
    for (int i = 0; i < 4; i++)
        if(isCollided(new_p[i]))return false;
    for (int i = 0; i < 4; i++) {
        Game::need_to_reset.push_back(p[i]->loc);
        Game::need_to_set.push_back(new_p[i]);
        Game::color_to_set.push_back(p[i]->color);
        p[i]->loc = new_p[i];
    }
    return true;
}

bool shapeS::rotate() {
    if(!move)return false;
    bool rect = false;
    if(p[0]->loc.y - p[1]->loc.y < 0)rect = true;
    Loc new_p[4];
    if(rect) {
        new_p[0] = Loc(p[0]->loc.x + 1, p[0]->loc.y + 1);
        new_p[1] = Loc(p[1]->loc.x + 1, p[1]->loc.y);
        new_p[2] = Loc(p[2]->loc.x + 1, p[2]->loc.y + 1);
        new_p[3] = Loc(p[3]->loc.x - 1, p[3]->loc.y);
    }
    else {
        new_p[0] = Loc(p[0]->loc.x - 1, p[0]->loc.y - 1);
        new_p[1] = Loc(p[1]->loc.x - 1, p[1]->loc.y);
        new_p[2] = Loc(p[2]->loc.x - 1, p[2]->loc.y - 1);
        new_p[3] = Loc(p[3]->loc.x + 1, p[3]->loc.y);
    }
    if(isMovingCollided(new_p))return false;
    for (int i = 0; i < 4; i++)
        if(isCollided(new_p[i]))return false;
    for (int i = 0; i < 4; i++) {
        Game::need_to_reset.push_back(p[i]->loc);
        Game::need_to_set.push_back(new_p[i]);
        Game::color_to_set.push_back(p[i]->color);
        p[i]->loc = new_p[i];
    }
    return true;
}

bool shapeZ::rotate() {
    if(!move)return false;
    bool rect = false;
    if(p[0]->loc.y - p[1]->loc.y < 0)rect = true;
    Loc new_p[4];
    if(rect) {
        new_p[0] = Loc(p[0]->loc.x, p[0]->loc.y + 1);
        new_p[1] = Loc(p[1]->loc.x, p[1]->loc.y - 1);
        new_p[2] = Loc(p[2]->loc.x + 1, p[2]->loc.y + 1);
        new_p[3] = Loc(p[3]->loc.x + 1, p[3]->loc.y + 1);
    }
    else {
        new_p[0] = Loc(p[0]->loc.x, p[0]->loc.y - 1);
        new_p[1] = Loc(p[1]->loc.x, p[1]->loc.y + 1);
        new_p[2] = Loc(p[2]->loc.x - 1, p[2]->loc.y - 1);
        new_p[3] = Loc(p[3]->loc.x - 1, p[3]->loc.y - 1);
    }
    if(isMovingCollided(new_p))return false;
    for (int i = 0; i < 4; i++)
        if(isCollided(new_p[i]))return false;
    for (int i = 0; i < 4; i++) {
        Game::need_to_reset.push_back(p[i]->loc);
        Game::need_to_set.push_back(new_p[i]);
        Game::color_to_set.push_back(p[i]->color);
        p[i]->loc = new_p[i];
    }
    return true;
}

bool Shape::isMovingCollided(Loc l[4]) {                                           //判断了l[4]中是否有其他player的方块
    return map->isMovingCollided(player,l);
}

shapeI::shapeI(Player* plar):
    Shape(plar)
{
    color = Red;
    int x = plar->loc.x;
    p[0] = new Block(x,-4,color);                                             //生成的格子必须全部在地图上边；下同
    p[1] = new Block(x,-3,color);
    p[2] = new Block(x,-2,color);
    p[3] = new Block(x,-1,color);
    center = nullptr;
}

shapeJ::shapeJ(Player* plar):
    Shape(plar)
{
    color = Yellow;
    int x = plar->loc.x;
    center = new Block(x,-2,color);
    p[0] = new Block(x,-3,color);
    p[1] = center;
    p[2] = new Block(x,-1,color);
    p[3] = new Block(x - 1,-1,color);
}

shapeL::shapeL(Player* plar):
    Shape(plar)
{
    color = Blue;
    int x = plar->loc.x;
    center = new Block(x,-2,color);
    p[0] = new Block(x,-3,color);
    p[1] = center;
    p[2] = new Block(x,-1,color);
    p[3] = new Block(x + 1,-1,color);
}

shapeT::shapeT(Player* plar):
    Shape(plar)
{
    color = Green;
    int x = plar->loc.x;
    center = new Block(x,-2,color);
    p[0] = new Block(x - 1,-2,color);
    p[1] = center;
    p[2] = new Block(x + 1,-2,color);
    p[3] = new Block(x,-1,color);
}

shapeS::shapeS(Player* plar):
    Shape(plar)
{
    color = DarkGreen;
    int x = plar->loc.x;
    p[0] = new Block(x,-2,color);
    p[1] = new Block(x + 1,-2,color);
    p[2] = new Block(x,-1,color);
    p[3] = new Block(x - 1,-1,color);
    center = nullptr;
}

shapeZ::shapeZ(Player* plar):
    Shape(plar)
{
    color = Purple;
    int x = plar->loc.x;
    p[0] = new Block(x,-2,color);
    p[1] = new Block(x - 1,-2,color);
    p[2] = new Block(x,-1,color);
    p[3] = new Block(x + 1,-1,color);
    center = nullptr;
}

shapeO::shapeO(Player* plar):
    Shape(plar)
{
    color = Gray;
    int x = plar->loc.x;
    p[0] = new Block(x,-2,color);
    p[1] = new Block(x - 1,-2,color);
    p[2] = new Block(x,-1,color);
    p[3] = new Block(x - 1,-1,color);
    center = nullptr;
}
