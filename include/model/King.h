#include "Piece.h"

#ifndef KING_H
#define KING_H

class King: public Piece{

    private:

    public:

        King(char color);
        bool isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock=false) override;
        bool isCastlingMoveValid(MoveData& moveData, Board& board);
        std::vector<MoveData> getPossibleMoves(int currentRow, int currentCol, Board& board) override;
        King* clone() override;
};


#endif