#include "PieceEnum.h"
#include <string>
#include <tuple>

#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement {
    private:
        int fromX = -1;
        int fromY = -1;
        int toX = -1;
        int toY = -1;
        ID promoteTo;

    public:
        Movement(int, int, int, int);
        Movement(ID);
        std::string toString();
        std::tuple<int, int, int, int> getData();
        
};

#endif