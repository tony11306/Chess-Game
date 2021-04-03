#include "Piece.h"
#include "Board.h"

Piece::Piece() {
}

ID Piece::getPieceID() {
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

char Piece::getColor() {
    return color;
}

bool Piece::isTargetFriendly(int targetX, int targetY, Board& board) {

    if(board.getPieceAtSquare(targetX, targetY) == nullptr) {
        return false;
    }

    if(color == board.getPieceAtSquare(targetX, targetY)->getColor()) {
        return true;
    }
    return false;
}