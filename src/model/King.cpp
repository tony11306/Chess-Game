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

    if(fromX == toX && fromY == toY) {
        return false;
    }

    if(isCastlingMoveValid(moveData, board)) { // is a castling move
        return true;
    }

    if(abs(toX-fromX) > 1 || abs(toY-fromY) > 1) { // king must move only move 0 or 1 square vertically and move 0 or 1 square horizontally
        return false;
    }
    Piece* tmpPiece = board.getPieceAtSquare(toX, toY);
    board.getSquareAt(fromX, fromY)->setPiece(nullptr);
    board.getSquareAt(toX, toY)->setPiece(this);
    for(int i = 0; i < BOARD_SIZE; ++i) { // check if the move can cause checkmate
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(board.getPieceAtSquare(i, j) == nullptr) {
                continue;
            }

            if(board.getPieceAtSquare(i, j)->getColor() == color) {
                continue;
            }
            
            MoveData md = MoveData(i, j, toX, toY);
            if(board.getPieceAtSquare(i, j)->isMoveValid(md, board)) { // 
                board.getSquareAt(toX, toY)->setPiece(tmpPiece);
                board.getSquareAt(fromX, fromY)->setPiece(this);
                return false;
            }
        }
    }

    board.getSquareAt(fromX, fromY)->setPiece(this);
    board.getSquareAt(toX, toY)->setPiece(tmpPiece);
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

    if(board.isBlackCheckmate() && pieceId == BLACK_KING) { // if it's in check
        return false;
    }

    if(board.isWhiteCheckmate() && pieceId == WHITE_KING) { // if it's in check
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


    for(int i = fromY; i != toY; i += (toY > fromY ? 1 : -1)) {
        if(i == fromY) {
            continue;
        }
        if(board.getPieceAtSquare(fromX, i) != nullptr) {
            return false;
        }
        for(int j = 0; j < BOARD_SIZE; ++j) {
            for(int k = 0; k < BOARD_SIZE; ++k) {
                if(board.getPieceAtSquare(j, k) == nullptr) {
                    continue;
                }
                if(color != board.getPieceAtSquare(j, k)->getColor()) {
                    MoveData md = MoveData(j, k, fromX, i);
                    if(board.getPieceAtSquare(j, k)->isMoveValid(md, board)) {
                        return false;
                    }
                }
            }
        }
    }

    // std::cout << "test\n";
    return true;


}

std::vector<MoveData> King::getPossibleMoves(int currentRow, int currentCol, Board& board) {
    
}