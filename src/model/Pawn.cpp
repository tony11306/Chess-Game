#include "Pawn.h"
#include "Board.h"
#include <iostream>


Pawn::Pawn(char color) {
    if(color == 'w') {
        pieceId = WHITE_PAWN;
    } else {
        pieceId = BLACK_PAWN;
    }
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

bool Pawn::isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(isTargetFriendly(toX, toY, board)) {
        return false;
    }

    if(pieceId == WHITE_PAWN) {

        if(toX - fromX == -1 && abs(toY-fromY) == 1) { // capture move
            if(board.getPieceAtSquare(toX, toY) != nullptr) {
                if(!checkmateDetectLock &&isMoveGoingToCheckmate(moveData, board)) {
                    return false;
                }
                return true;
            }
        }

        if(fromY == toY && toX - fromX == -1) {
            if(board.getPieceAtSquare(toX, toY) == nullptr) {
                if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                    return false;
                }
                return true;
            }
        }

        if(!hasMoved) { // first move
            if(fromY == toY && toX - fromX == -2) {
                if(board.getPieceAtSquare(toX, toY) == nullptr) {
                    if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                        
                        return false;
                    }
                    return true;
                }
            }
        }

    } else { // black pawn

        if(toX - fromX == 1 && abs(toY-fromY) == 1) { // capture move
            if(board.getPieceAtSquare(toX, toY) != nullptr) {
                if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                    return false;
                }
                return true;
            }
            
        }

        if(fromY == toY && toX - fromX == 1) {
            if(board.getPieceAtSquare(toX, toY) == nullptr) {
                if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                    return false;
                }
                return true;
            }
        }

        if(!hasMoved) { // first move
            if(fromY == toY && toX - fromX == 2) {
                if(board.getPieceAtSquare(toX, toY) == nullptr) {
                    if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                        return false;
                    }
                    return true;
                }
            }
        }

    }

    if(isEnPassantMove(moveData, board)) {
        if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
            return false;
        }
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

std::vector<MoveData> Pawn::getPossibleMoves(int currentX, int currentY, Board& board) {
    std::vector<MoveData> result;
    MoveData moveData = MoveData(currentX, currentY, currentX+1, currentY+1);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    moveData = MoveData(currentX, currentY, currentX+1, currentY-1);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    moveData = MoveData(currentX, currentY, currentX-1, currentY+1);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    moveData = MoveData(currentX, currentY, currentX-1, currentY-1);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    moveData = MoveData(currentX, currentY, currentX+2, currentY);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    moveData = MoveData(currentX, currentY, currentX-2, currentY);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    moveData = MoveData(currentX, currentY, currentX+1, currentY);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    moveData = MoveData(currentX, currentY, currentX-1, currentY);
    if(isMoveValid(moveData, board)) {
        result.push_back(moveData);
    }

    return result;
}