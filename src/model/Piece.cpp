#include "Piece.h"

Piece::Piece() {
    
}

char Piece::getColor() {
    return color;
}

char Piece::getPieceID() {
    return pieceId;
}

bool Piece::checkAlive() {
    return isAlive;
}

bool Piece::checkMoved() {
    return hasMoved;
}

void Piece::setAlive(bool alive) {
    isAlive = alive;
}

void Piece::setMoved(bool moved) {
    hasMoved = moved;
}
