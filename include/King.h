#include "Piece.h"

#ifndef KING_H
#define KING_H

class King: public Piece{
    public:
        King(char, char);
        bool isMoveValid(int, int, int, int) override;
};



#endif