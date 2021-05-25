#include "King.h"
#include "Board.h"
#include <iostream>

King::King(char color) {
    if(color == 'w') {
        pieceId = WHITE_KING;
    } else {
        pieceId = BLACK_KING;
    }
    hasMoved = false;
    this->color = color;
}

bool King::isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(isTargetFriendly(toX, toY, board)) {
        return false;
    }

    if(toX < 0 || toY < 0) {
        return false;
    }

    if(toX >= BOARD_SIZE || toY >= BOARD_SIZE) {
        return false;
    }

    if(fromX < 0 || fromY < 0) {
        return false;
    }

    if(fromX >= BOARD_SIZE || fromY >= BOARD_SIZE) {
        return false;
    }

    if(fromX == toX && fromY == toY) {
        return false;
    }


    if(isCastlingMoveValid(moveData, board)) { // is a castling move
        return true;
    }
    // board.printBoard();

    if(abs(toX-fromX) > 1 || abs(toY-fromY) > 1) { // king must move only move 0 or 1 square vertically and move 0 or 1 square horizontally
        return false;
    }

    

    if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
        return false;
    }

    return true;


}

bool King::isCastlingMoveValid(MoveData& moveData, Board& board) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();


    if(hasMoved) { // if it has moved
        return false;
    }

    if(fromX != toX || abs(toY-fromY) != 2) { // if it does not move 2 squares horizontally
        return false;
    }


    if((pieceId == BLACK_KING && fromX != 0) || (pieceId == WHITE_KING && fromX != 7)) {
        return false;
    }

    if(toY-fromY > 0) { // king side
        if(board.getPieceAtSquare(fromX, 7) == nullptr) {
            return false;
        }
        if(board.getPieceAtSquare(fromX, 7)->getPieceID() != BLACK_ROOK && board.getPieceAtSquare(fromX, 7)->getPieceID() != WHITE_ROOK) {
            return false;
        }
        if(board.getPieceAtSquare(fromX, 7)->getColor() != color) {
            return false;
        }
    } else { // queen side
        if(board.getPieceAtSquare(fromX, 0) == nullptr) {
            return false;
        }
        if(board.getPieceAtSquare(fromX, 0)->getPieceID() != BLACK_ROOK && board.getPieceAtSquare(fromX, 0)->getPieceID() != WHITE_ROOK) {
            return false;
        }
        if(board.getPieceAtSquare(fromX, 0)->getColor() != color) {
            return false;
        }
    }

    for(int i = fromY; i != (toY > fromY ? BOARD_SIZE-1 : 0); i += (toY > fromY ? 1 : -1)) {
        
        if(i == fromY) {
            continue;
        }
        
        if(board.getPieceAtSquare(fromX, i) != nullptr) {
            return false;
        }

        if(isMoveGoingToCheckmate(moveData, board)) {
            return false;
        }
    }

    if(board.isBlackCheckmate() && pieceId == BLACK_KING) { // if it's in check
        return false;
    }

    if(board.isWhiteCheckmate() && pieceId == WHITE_KING) { // if it's in check
        return false;
    }

    return true;


}

std::vector<MoveData> King::getPossibleMoves(int currentX, int currentY, Board& board) {
    std::vector<MoveData> result;
    for(int i = -1; i < 2; ++i) {
        for(int j = -1; j < 2; ++j) {
            if(i == 0 && j == 0) {
                continue;
            }
            MoveData moveData = MoveData(currentX, currentY, currentX+i, currentY+j);
            if(isMoveValid(moveData, board)) {
                result.push_back(moveData);
            }

        }
    }
    if(!hasMoved) {
        MoveData moveData = MoveData(currentX, currentY, currentX, currentY+2);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
        moveData = MoveData(currentX, currentY, currentX, currentY-2);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
    }


    return result;

}