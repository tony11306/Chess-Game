#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(char color) {
    if(color == 'w') {
        pieceId = WHITE_BISHOP;
    } else {
        pieceId = BLACK_BISHOP;
    }
    isAlive = true;
    hasMoved = false;
    this->color = color;
}

bool Bishop::isMoveValid(MoveData& moveData, Board& board) {
    // only check if it's diagonal
    // checking if it's out of range should be done outside
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    int xIncrement = 1;
    int yIncrement = 1;

    if(fromX == toX && fromY == toY) {
        return false;
    }

    if(isTargetFriendly(toX, toY, board)) {
        return false;
    }

    if(toX < fromX) {
        xIncrement = -1;
    }
    if(toY < fromY) {
        yIncrement = -1;
    }

    if(abs(toX-fromX) == abs(toY-fromY)) {
        for(int i = fromX, j = fromY; i != toX; i += xIncrement, j += yIncrement) {
            if(i == fromX) {
                continue;
            }
            if(board.getPieceAtSquare(i, j) != nullptr) {
                return false;
            }
        }
        return true;
    }

    return false;


}