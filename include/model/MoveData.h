#ifndef MOVEDATA_H
#define MOVEDATA_H

#include "PieceIDEnum.h"
#include <string>
#include <iostream>

class MoveData {
    private:
        int fromX;
        int fromY;
        int toX;
        int toY;

    public:
        MoveData(int fromX, int fromY, int toX, int toY) {
            this->fromX = fromX;
            this->fromY = fromY;
            this->toX = toX;
            this->toY = toY;
        }
        std::string toString() {
            std::string s = "";
            s += char('a'+fromY);
            s += char('0'+abs(8-fromX));
            s += char('a'+toY);
            s += char('0'+abs(8-toX));
            return s;
        }

        int getFromX() {
            return fromX;
        }

        int getFromY() {
            return fromY;
        }

        int getToX() {
            return toX;
        }

        int getToY() {
            return toY;
        }
        
};

#endif