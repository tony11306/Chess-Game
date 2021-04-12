#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn: public Piece {

    private:
        bool canBeEnPassant;

    public:

        Pawn(char color);
        bool isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock=false) override;
        bool isEnPassantMove(MoveData& moveData, Board& board);
        void setCanBeEnPassant(bool);
        bool checkCanBeEnPassant();
        


};


#endif