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
        bool isAlive;
        bool hasMoved;
        Piece();
    public:
        char getColor();
        ID getPieceID();
        bool checkAlive();
        bool checkMoved();
        void setAlive(bool);
        void setMoved(bool);
        virtual bool isMoveValid(MoveData& moveData, Board& board) = 0;
        bool isTargetFriendly(int targetX, int targetY, Board& board);

};

#endif

