#include "Piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight: public Piece{
    public:
        Knight(char, char);
        bool isMoveValid(int, int, int, int) override;
};



#endif