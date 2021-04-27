#include "Piece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen: public Piece {

    private:


    public:

        Queen(char color);
        bool isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock=false) override;
        std::vector<MoveData> getPossibleMoves(int currentRow, int currentCol, Board& board) override;
        
};


#endif