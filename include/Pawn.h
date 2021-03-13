#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn: public Piece{
    public:
        Pawn(char, char);
        bool isMoveValid(int, int, int, int) override;
};



#endif