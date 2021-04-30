#include "Queen.h"
#include "Board.h"


Queen::Queen(char color) {
    if(color == 'w') {
        pieceId = WHITE_QUEEN;
    } else {
        pieceId = BLACK_QUEEN;
    }
    hasMoved = false;
    this->color = color;
}

bool Queen::isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock) {
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

    if(abs(fromX-toX) == abs(fromY-toY)) { // diagonal
        int xIncrement = 1;
        int yIncrement = 1;

        if(toX < fromX) {
            xIncrement = -1;
        }
        if(toY < fromY) {
            yIncrement = -1;
        }

        for(int i = fromX, j = fromY; i != toX; i += xIncrement, j += yIncrement) {
            if(i == fromX) {
                continue;
            }
            if(board.getPieceAtSquare(i, j) != nullptr) {
                return false;
            }
        }
        if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
            return false;
        }
        return true;
    
    }

    if(fromX == toX || fromY == toY) { // line
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
            if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                return false;
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
            if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                return false;
            }
            return true;
        }
    

    }

    return false;
}

std::vector<MoveData> Queen::getPossibleMoves(int currentX, int currentY, Board& board) {
    std::vector<MoveData> result;

    for(int x = currentX+1, y = currentY+1; x < BOARD_SIZE && y < BOARD_SIZE; ++x, ++y) {
        MoveData moveData = MoveData(currentX, currentY, x, y);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    for(int x = currentX+1, y = currentY-1; x < BOARD_SIZE && y >= 0; ++x, --y) {
        MoveData moveData = MoveData(currentX, currentY, x, y);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    for(int x = currentX-1, y = currentY+1; x >= 0 && y < BOARD_SIZE; --x, ++y) {
        MoveData moveData = MoveData(currentX, currentY, x, y);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    for(int x = currentX-1, y = currentY-1; x >= 0 && y >= 0; --x, --y) {
        MoveData moveData = MoveData(currentX, currentY, x, y);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    for(int i = currentX+1; i < BOARD_SIZE; ++i) {
        MoveData moveData = MoveData(currentX, currentY, i, currentY);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    for(int i = currentX-1; i >=0; --i) {
        MoveData moveData = MoveData(currentX, currentY, i, currentY);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    for(int i = currentY+1; i < BOARD_SIZE; ++i) {
        MoveData moveData = MoveData(currentX, currentY, currentX, i);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    for(int i = currentY-1; i >= 0; --i) {
        MoveData moveData = MoveData(currentX, currentY, currentX, i);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }

    return result;
}