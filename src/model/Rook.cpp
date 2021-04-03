#include "Rook.h"
#include "Board.h"

Rook::Rook(char color) {
    if(color == 'w') {
        pieceId = WHITE_ROOK;
    } else {
        pieceId = BLACK_ROOK;
    }
    isAlive = true;
    hasMoved = false;
    this->color = color;
}

bool Rook::isMoveValid(MoveData& moveData, Board& board) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(fromX == toX && fromY == toY) {
        return false;
    }
    

    if(isTargetFriendly(toX, toY, board)) {
        return false;
    }
    
    if(fromX == toX) {
        int yIncrement = 1;
        if(toY < fromY) {
            yIncrement = -1;
        }
        for(int i = fromY; i != toY; i += yIncrement) {
            if(i == fromY) {
                continue;
            }

            if(board.getPieceAtSquare(toX, i) != nullptr) {
                return false;
            }
            
        }
        return true;
    }
    
    if (fromY == toY) {
        int xIncrement = 1;
        if(toX < fromX) {
            xIncrement = -1;
        }
        for(int i = fromX; i != toX; i += xIncrement) {
            if(i == fromX) {
                continue;
            }

            if(board.getPieceAtSquare(i, toY) != nullptr) {
                return false;
            }
            
        }
        return true;
    }
    

    return false;
}