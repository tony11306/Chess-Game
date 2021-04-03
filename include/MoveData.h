#include "PieceIDEnum.h"
#include <string>

#ifndef MOVEDATA_H
#define MOVEDATA_H

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
            return "TODO";
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