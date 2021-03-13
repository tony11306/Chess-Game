#include "Cell.h"

Cell::Cell(int x, int y) {
    this->x = x;
    this->y = y;
}

Piece* Cell::getCurrentPiece() {
    return currentPiece;
}

void Cell::setCurrentPiece(Piece* piece) {
    currentPiece = piece;
}

std::pair<int, int> Cell::getXY() {
    return std::make_pair(x, y);
}