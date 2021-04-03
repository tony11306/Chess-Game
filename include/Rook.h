#include "Piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook: public Piece {

    private:


    public:

        Rook(char color);
        bool isMoveValid(MoveData& moveData, Board& board) override;

};


#endif