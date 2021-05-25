#include "Piece.h"
#include "Board.h"
#include <iostream>

Piece::Piece() {
}

ID Piece::getPieceID() {
    return pieceId;
}

bool Piece::checkMoved() {
    return hasMoved;
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

bool Piece::isMoveGoingToCheckmate(MoveData& moveData, Board& board) {
    // before calling this function
    // it has to make sure that the fromX and fromY is this piece
    // otherwise it's going to bugged out.

    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();
    Piece* tmpPiece = board.getPieceAtSquare(toX, toY);

    if(board.getPieceAtSquare(fromX, fromY)->getPieceID() == WHITE_KING) {
        board.setWhiteKingPosition(toX, toY);
    } else if(board.getPieceAtSquare(fromX, fromY)->getPieceID() == BLACK_KING) {
        board.setBlackKingPosition(toX, toY);
    }
    

    board.getSquareAt(fromX, fromY)->setPiece(nullptr);
    
    board.getSquareAt(toX, toY)->setPiece(this);

    bool isCheckmate = false;
    if(pieceId > 0) { // the moving piece is white
        if(board.isWhiteCheckmate()) {
            isCheckmate = true;
        }
    } else { // the moving piece is black
        if(board.isBlackCheckmate()) {
            isCheckmate = true;
        }
    }
    
    if(board.getPieceAtSquare(toX, toY)->getPieceID() == WHITE_KING) {
        board.setWhiteKingPosition(fromX, fromY);
    } else if(board.getPieceAtSquare(toX, toY)->getPieceID() == BLACK_KING) {
        board.setBlackKingPosition(fromX, fromY);
    }

    board.getSquareAt(fromX, fromY)->setPiece(this);
    board.getSquareAt(toX, toY)->setPiece(tmpPiece);
    return isCheckmate;

    

}