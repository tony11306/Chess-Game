#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Piece.h"

class Game{

    private:
        Board* board;
        bool isWhiteTurn;
        void switchTurn();
        bool _isBlackInCheck;
        bool _isWhiteInCheck;

    public:
        Game();
        ~Game();
        Board* getBoard();
        void moveExecute(MoveData&);
        void undo();
        bool checkIsWhiteTurn();
        bool isWhiteWin();
        bool isBlackWin();
        bool isStalemate();
        void updateCheck();
        bool isBlackInCheck();
        bool isWhiteInCheck();

};
#endif