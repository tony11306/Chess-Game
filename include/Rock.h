#include "Piece.h"

#ifndef ROCK_H
#define ROCK_H

class Rock: public Piece{
    public:
        Rock(char, char);
        bool isMoveValid(int, int, int, int) override;
};



#endif