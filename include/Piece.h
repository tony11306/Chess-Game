#include "Movement.h"
#include "PieceEnum.h"

#ifndef PIECE_H
#define PIECE_H

const int BOARD_SIZE = 8;


// base class
class Piece{

    

    protected:
        char color;
        char pieceId;
        bool isAlive;
        bool hasMoved;
        Piece();

    public:
        char getColor();
        char getPieceID();
        bool checkAlive();
        bool checkMoved();
        bool isTargetCapturable(); // 判斷目標棋子是否能吃 只判斷顏色部分 或是否空
        
        void setAlive(bool);
        void setMoved(bool);
        bool virtual isMoveValid(Piece*[][BOARD_SIZE], Movement&) = 0;

        
};

class EmptyPiece: public Piece{
    public:
        EmptyPiece();
        bool isMoveValid(Piece* board[][BOARD_SIZE], Movement&) override;
};

class Pawn: public Piece{
    public:
        Pawn(char);
        bool isMoveValid(Piece* board[][BOARD_SIZE], Movement&) override;
};


class Knight: public Piece{
    public:
        Knight(char);
        bool isMoveValid(Piece* board[][BOARD_SIZE], Movement&) override;
};

class Queen: public Piece{
    public:
        Queen(char);
        bool isMoveValid(Piece* board[][BOARD_SIZE], Movement&) override;
};

class King: public Piece{
    public:
        King(char);
        bool isMoveValid(Piece* board[][BOARD_SIZE], Movement&) override;
};

class Bishop: public Piece{
    public:
        Bishop(char);
        bool isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement&) override;
};

class Rook: public Piece{
    public:
        Rook(char);
        bool isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement&) override;
};


#endif // PIECE_H