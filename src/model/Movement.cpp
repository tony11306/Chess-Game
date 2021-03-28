#include "Movement.h"

Movement::Movement(int fromX, int fromY, int toX, int toY) {
    this->fromX = fromX;
    this->fromY = fromY;
    this->toX = toX;
    this->toY = toY;
}

Movement::Movement(ID promoteTo) {
    this->promoteTo = promoteTo;
}

std::string Movement::toString() {
    std::string s;
    s = (8-fromX+'0') + (fromY+'a') + (8-toX+'0') + (toY+'a');
    return s;
}

std::tuple<int, int, int, int> Movement::getData() {
    return std::make_tuple(fromX, fromY, toX, toY);
}