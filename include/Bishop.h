#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"


class Bishop: public Piece {

    private:

    public:
        Bishop(char color);
        bool isMoveValid(MoveData&, Board&, bool checkmateDetectLock=false) override;

};


#endif