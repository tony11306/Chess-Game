#include "Piece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen: public Piece{
    public:
        Queen(char, char);
        bool isMoveValid(int, int, int, int) override;
};



#endif