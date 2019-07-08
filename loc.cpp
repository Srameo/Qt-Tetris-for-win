/*******************************************************************************
 *
 * 位置类
 *
 ******************************************************************************/

#include"loc.h"

const Loc Loc::operator+(const Loc& l) const {
    return Loc(this->x + l.x, this->y + l.y);
}

const Loc Loc::operator-(const Loc& l) const {
    return Loc(this->x - l.x, this->y - l.y);
}

bool Loc::operator==(const Loc& l) const {
    if (l.x == this->x && l.y == this->y)
        return true;
    else
        return false;
}

bool Loc::operator<(const Loc& l) const {
    if (this->x < l.x && this->y < l.y)
        return true;
    else
        return false;
}

bool Loc::operator>(const Loc& l) const {
    if (this->x > l.x && this->y > l.y)
        return true;
    else
        return false;
}

bool Loc::operator<=(const Loc& l) const {
    if (this->x <= l.x && this->y <= l.y)
        return true;
    else
        return false;
}

bool Loc::operator>=(const Loc& l) const {
    if (this->x >= l.x && this->y >= l.y)
        return true;
    else
        return false;
}
