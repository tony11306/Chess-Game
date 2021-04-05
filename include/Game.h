#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Piece.h"

class Game{

    private:
        Board* board;

    public:
        Game();
        ~Game();
        Board* getBoard();
        void moveExecute(MoveData&);

};
#endif