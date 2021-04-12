#ifndef PIECE_H
#define PIECE_H

#include "PieceIDEnum.h"
#include "MoveData.h"
#include <cmath>

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
        bool isTargetFriendly(int targetX, int targetY, Board& board);
        bool isMoveGoingToCheckmate(MoveData& moveData, Board& board);

};

#endif

