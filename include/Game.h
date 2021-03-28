#include "Piece.h"
#include "HumanPlayer.h"

#ifndef GAME_H
#define GAME_H

class Game{

    private:
        Piece* board[BOARD_SIZE][BOARD_SIZE];
        bool isWhiteTurn = true;


    public:
        Game(std::string whitePlayerName, std::string blackPlayerName);
        bool isBlackCheckmate();
        bool isWhiteCheckmate();
        bool isGameOver();
        void resetBoard();
        void moveExecute(Movement);
        bool isMoveValid(Movement);
        bool checkWhiteTurn(); // it's either black or white.
        void switchTurn();
};

#endif