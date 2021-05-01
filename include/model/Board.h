
#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include "MoveData.h"

class Piece;


const int BOARD_SIZE = 8;


class Board {

    private:
        
        Square squares[BOARD_SIZE][BOARD_SIZE];
        bool isOutside(MoveData&);
        std::pair<int, int> blackKingPosition;
        std::pair<int, int> whiteKingPosition;

    public:

        Board();
        void initBoard();
        void movePiece(MoveData&);
        Piece* getPieceAtSquare(int row, int col);
        Square* getSquareAt(int row, int col);
        bool isBlackCheckmate();
        bool isWhiteCheckmate();
        std::pair<int, int> getWhiteKingPosition();
        std::pair<int, int> getBlackKingPosition();
        void setWhiteKingPosition(int row, int col);
        void setBlackKingPosition(int row, int col);

};
#endif