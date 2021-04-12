#include "Piece.h"
#ifndef KNIGHT_H
#define KNIGHT_H

class Knight: public Piece{

    private:


    public:

        Knight(char color);
        bool isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock=false) override;

};

#endif