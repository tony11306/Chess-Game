#include "Piece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop: public Piece{
    public:
        Bishop(char, char);
        bool isMoveValid(int, int, int, int) override;
};



#endif