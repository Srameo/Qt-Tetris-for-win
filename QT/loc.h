/*******************************************************************************
 *
 * 该头文件定义了Loc类，即在游戏显示界面中的坐标
 *
 ******************************************************************************/

#ifndef LOC_H
#define LOC_H

typedef class Loc {                                                             //位置和大小和方向的类
public:
    //data:
    int x, y;
    //constructor:
    Loc(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    Loc(const Loc& l) : x(l.x), y(l.y) {}
    //operator:
    const Loc operator+(const Loc&) const;
    const Loc operator-(const Loc&) const;
    bool operator==(const Loc&) const;                                          //各种判断函数，简化语法
    bool operator<(const Loc&) const;                                           //判断l是否在this的左上方（<=同理）
    bool operator>(const Loc&) const;                                           //判断l是否在this的左上方（>=同理）
    bool operator<=(const Loc&) const;
    bool operator>=(const Loc&) const;
}Size, Dire;

#endif // LOC_H
