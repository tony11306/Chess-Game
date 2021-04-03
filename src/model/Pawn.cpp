#include "Pawn.h"
#include "Board.h"


Pawn::Pawn(char color) {
    if(color == 'w') {
        pieceId = WHITE_PAWN;
    } else {
        pieceId = BLACK_PAWN;
    }
    isAlive = true;
    hasMoved = false;
    this->color = color;
    canBeEnPassant = false;
}

bool Pawn::isEnPassantMove(MoveData& moveData, Board& board) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(board.getPieceAtSquare(fromX, toY) == nullptr) {
        return false;
    }

    if(pieceId == WHITE_PAWN) {
        if(toX - fromX == -1 && abs(toY-fromY) == 1) {
            if(board.getPieceAtSquare(fromX, toY)->getPieceID() == BLACK_PAWN) {
                return dynamic_cast<Pawn*>(board.getPieceAtSquare(fromX, toY))->checkCanBeEnPassant();
            }
            
        }

    } else { // black pawn
        if(toX - fromX == 1 && abs(toY-fromY) == 1) {
            if(board.getPieceAtSquare(fromX, toY)->getPieceID() == WHITE_PAWN) {
                return dynamic_cast<Pawn*>(board.getPieceAtSquare(fromX, toY))->checkCanBeEnPassant();
            }
        }
    }
    return false;

}

bool Pawn::isMoveValid(MoveData& moveData, Board& board) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(isTargetFriendly(toX, toY, board)) {
        return false;
    }

    if(pieceId == WHITE_PAWN) {

        if(toX - fromX == -1 && abs(toY-fromY) == 1) { // capture move
            if(board.getPieceAtSquare(fromX, toY) == nullptr) {
                if(board.getPieceAtSquare(toX, toY) != nullptr) {
                    return true;
                }
            }
        }

        if(fromY == toY && toX - fromX == -1) {
            if(board.getPieceAtSquare(toX, toY) == nullptr) {
                return true;
            }
        }

        if(!hasMoved) { // first move
            if(fromY == toY && toX - fromX == -2) {
                if(board.getPieceAtSquare(toX, toY) == nullptr) {
                    return true;
                }
            }
        }

    } else { // black pawn

        if(toX - fromX == 1 && abs(toY-fromY) == 1) { // capture move
            if(board.getPieceAtSquare(fromX, toY) == nullptr) {
                if(board.getPieceAtSquare(toX, toY) != nullptr) {
                    return true;
                }
            }
        }

        if(fromY == toY && toX - fromX == 1) {
            if(board.getPieceAtSquare(toX, toY) == nullptr) {
                return true;
            }
        }

        if(!hasMoved) { // first move
            if(fromY == toY && toX - fromX == 2) {
                if(board.getPieceAtSquare(toX, toY) == nullptr) {
                    return true;
                }
            }
        }

    }

    if(isEnPassantMove(moveData, board)) {
        return true;
    }

    return false;
}

void Pawn::setCanBeEnPassant(bool canBeEnPassant) {
    this->canBeEnPassant = canBeEnPassant;
}

bool Pawn::checkCanBeEnPassant() {
    return canBeEnPassant;
}