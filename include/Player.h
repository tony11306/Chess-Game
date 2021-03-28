#include "Piece.h"
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

// abstract class
class Player {
    protected:
        std::string name;
        char color;
        Player();
    public:
        Movement virtual decide() = 0;
        char getColor();
};
#endif