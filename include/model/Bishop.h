#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"


class Bishop: public Piece {

    private:

    public:
        Bishop(char color);
        bool isMoveValid(MoveData&, Board&, bool checkmateDetectLock=false) override;
        std::vector<MoveData> getPossibleMoves(int currentRow, int currentCol, Board& board) override;
        Bishop* clone() override;
};


#endif