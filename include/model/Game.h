#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Piece.h"

class Game{

    private:
        Board* board;
        bool isWhiteTurn;
        void switchTurn();
        bool isGameOver;

    public:
        Game();
        ~Game();
        Board* getBoard();
        void moveExecute(MoveData&);
        bool checkIsWhiteTurn();

};
#endif