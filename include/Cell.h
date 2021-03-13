#include "Piece.h"
#include <utility>


#ifndef CELL_H
#define CELL_H

class Cell {
    private:
        Piece* currentPiece = nullptr;
        int x;
        int y;
    
    public:
        Cell(int, int);
        Piece* getCurrentPiece();
        void setCurrentPiece(Piece*);
        std::pair<int, int> getXY();
};


#endif