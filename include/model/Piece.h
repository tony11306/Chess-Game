#ifndef PIECE_H
#define PIECE_H

#include "PieceIDEnum.h"
#include "MoveData.h"
#include <cmath>
#include <vector>

class Board;

class Piece {

    protected:
        char color;
        ID pieceId;
        bool hasMoved;
        Piece();
    public:
        char getColor();
        ID getPieceID();
        bool checkMoved();
        void setMoved(bool);
        virtual bool isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock=false) = 0;
        virtual std::vector<MoveData> getPossibleMoves(int currentRow, int currentCol, Board& board) = 0;
        bool isTargetFriendly(int targetX, int targetY, Board& board);
        bool isMoveGoingToCheckmate(MoveData& moveData, Board& board);
        virtual Piece* clone() = 0;

};

#endif

