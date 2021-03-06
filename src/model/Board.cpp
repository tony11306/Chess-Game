#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "History.h"

#include <iostream>
#include <iomanip>

Board::Board() {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j  = 0; j < BOARD_SIZE; ++j) {
            squares[i][j].setRow(i);
            squares[i][j].setCol(j);
        }
    }
}


void Board::initBoard() {

    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            squares[i][j].setPiece(nullptr);
        }
    }

    // setting for the black pieces
    squares[0][0].setPiece(new Rook('b'));
    squares[0][1].setPiece(new Knight('b'));
    squares[0][2].setPiece(new Bishop('b'));
    squares[0][3].setPiece(new Queen('b'));
    squares[0][4].setPiece(new King('b'));
    squares[0][5].setPiece(new Bishop('b'));
    squares[0][6].setPiece(new Knight('b'));
    squares[0][7].setPiece(new Rook('b'));
    for(int i = 0; i < BOARD_SIZE; ++i) {
        squares[1][i].setPiece(new Pawn('b'));
    }

    // setting for the white pieces
    squares[7][0].setPiece(new Rook('w'));
    squares[7][1].setPiece(new Knight('w'));
    squares[7][2].setPiece(new Bishop('w'));
    squares[7][3].setPiece(new Queen('w'));
    squares[7][4].setPiece(new King('w'));
    squares[7][5].setPiece(new Bishop('w'));
    squares[7][6].setPiece(new Knight('w'));
    squares[7][7].setPiece(new Rook('w'));
    for(int i = 0; i < BOARD_SIZE; ++i) {
        squares[6][i].setPiece(new Pawn('w'));
    }

    blackKingPosition = {0, 4};
    whiteKingPosition = {7, 4};
}

void Board::movePiece(MoveData& moveData) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(isOutside(moveData)) {
        return;
    }

    if(squares[fromX][fromY].getPiece() == nullptr) {
        return;
    }

    if(!squares[fromX][fromY].getPiece()->isMoveValid(moveData, *this)) {
        return;
    }

    // when the move is valid, do the move and check

    History history = History(moveData);
    historyMoves.push(history);
    if(squares[toX][toY].getPiece() != nullptr) {
        historyMoves.top().setCapturedPiece(squares[toX][toY].getPiece()->clone());
    } else {
        historyMoves.top().setCapturedPiece(nullptr);
    }
    historyMoves.top().setMovePiece(squares[fromX][fromY].getPiece()->clone());

    squares[fromX][fromY].getPiece()->setMoved(true);
    if(squares[fromX][fromY].getPiece()->getPieceID() == WHITE_KING || squares[fromX][fromY].getPiece()->getPieceID() == BLACK_KING) {

        squares[toX][toY].deletePiece();
        squares[toX][toY].setPiece(squares[fromX][fromY].getPiece());
        squares[fromX][fromY].setPiece(nullptr);

        if(abs(toY - fromY) == 2) {

            if(toY-fromY > 0) { // king side castling
                squares[fromX][5].setPiece(squares[fromX][7].getPiece());
                squares[fromX][7].setPiece(nullptr);
            } else { // queen side castling
                squares[fromX][3].setPiece(squares[fromX][0].getPiece());
                squares[fromX][0].setPiece(nullptr);
            }
            historyMoves.top().setIsCastling(true);

        }

        if(squares[toX][toY].getPiece()->getPieceID() == WHITE_KING) {
            whiteKingPosition.first = toX;
            whiteKingPosition.second = toY;
        } else {
            blackKingPosition.first = toX;
            blackKingPosition.second = toY;
        }

    } else if (squares[fromX][fromY].getPiece()->getPieceID() == WHITE_PAWN || squares[fromX][fromY].getPiece()->getPieceID() == BLACK_PAWN) {
        
        if(fromY == toY && (abs(toX-fromX) == 2 || abs(toX-fromX) == 1)) {

            if(abs(toX-fromX) == 2) {
                dynamic_cast<Pawn*>(squares[fromX][fromY].getPiece())->setCanBeEnPassant(true);
                squares[fromX][fromY].getPiece()->setMoved(true);
            }

            squares[toX][toY].setPiece(squares[fromX][fromY].getPiece());
            squares[fromX][fromY].setPiece(nullptr);
            
        } else {

            if(squares[toX][toY].getPiece() != nullptr) {
                squares[toX][toY].deletePiece();
                squares[toX][toY].setPiece(squares[fromX][fromY].getPiece());
                squares[fromX][fromY].setPiece(nullptr);
            } else { // en passant
                historyMoves.top().setCapturedPiece(squares[fromX][toY].getPiece()->clone());
                historyMoves.top().setIsEnPassant(true);
                squares[fromX][toY].deletePiece();
                squares[fromX][toY].setPiece(nullptr);

                squares[toX][toY].setPiece(squares[fromX][fromY].getPiece());
                squares[fromX][fromY].setPiece(nullptr);
            }

        }


    } else { // queen, bishop, knight, rook
        if(squares[toX][toY].getPiece() != nullptr) {
            squares[toX][toY].deletePiece();
        }
        squares[toX][toY].setPiece(squares[fromX][fromY].getPiece());
        squares[fromX][fromY].setPiece(nullptr);
    }
    
    char currentTurnColor = squares[toX][toY].getPiece()->getColor();
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {

            if(squares[i][j].getPiece() == nullptr) {
                continue;
            }

            if(squares[i][j].getPiece()->getPieceID() == WHITE_PAWN || squares[i][j].getPiece()->getPieceID() == BLACK_PAWN) {
                if(currentTurnColor != squares[i][j].getPiece()->getColor()) {
                    dynamic_cast<Pawn*>(squares[i][j].getPiece())->setCanBeEnPassant(false);
                }
            }
        }
    }


}

void Board::undoMove() {

    if(historyMoves.empty()) {
        return;
    }

    History& previousMove = historyMoves.top();
    Piece* prevMovePiece = previousMove.getMovePiece();
    Piece* prevCapturedPiece = previousMove.getCapturedPiece();

    int fromX = previousMove.getMoveData().getFromX();
    int fromY = previousMove.getMoveData().getFromY();
    int toX = previousMove.getMoveData().getToX();
    int toY = previousMove.getMoveData().getToY();

    if(prevMovePiece->getPieceID() == WHITE_KING) {
        whiteKingPosition.first = fromX;
        whiteKingPosition.second = fromY;
    } else if(prevMovePiece->getPieceID() == BLACK_KING) {
        blackKingPosition.first = fromX;
        blackKingPosition.second = fromY;
    }

    squares[fromX][fromY].deletePiece();
    squares[fromX][fromY].setPiece(prevMovePiece->clone());
    
    if(previousMove.checkIsCastling()) {

        if(fromX == 0) { // black
            if(toY-fromY > 0) { // king side
                squares[0][7].deletePiece();
                squares[0][7].setPiece(squares[0][5].getPiece()->clone());
                squares[0][5].deletePiece();
                squares[0][5].setPiece(nullptr);
            } else { // queen side
                squares[0][0].deletePiece();
                squares[0][0].setPiece(squares[0][3].getPiece()->clone());
                squares[0][3].deletePiece();
                squares[0][3].setPiece(nullptr);
            }
        } else { // white
            if(toY > fromY > 0) { // king side
                squares[7][7].deletePiece();
                squares[7][7].setPiece(squares[7][5].getPiece()->clone());
                squares[7][5].deletePiece();
                squares[7][5].setPiece(nullptr);
            } else { // queen side
                squares[7][0].deletePiece();
                squares[7][0].setPiece(squares[7][3].getPiece()->clone());
                squares[7][3].deletePiece();
                squares[7][3].setPiece(nullptr);
            }
        }
        
    }

    if(previousMove.checkIsEnPassant()) {
        
        squares[fromX][toY].deletePiece();
        squares[fromX][toY].setPiece(prevCapturedPiece->clone());

        squares[toX][toY].deletePiece();
        squares[toX][toY].setPiece(nullptr);

        squares[fromX][fromY].deletePiece();
        squares[fromX][fromY].setPiece(prevMovePiece->clone());
        
    } else {
        squares[toX][toY].deletePiece();
        if(prevCapturedPiece != nullptr) {
            squares[toX][toY].setPiece(prevCapturedPiece->clone());
        } else {
            squares[toX][toY].setPiece(nullptr);
        }
    }
    
    historyMoves.pop();

}

bool Board::isOutside(MoveData& moveData) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(fromX >= BOARD_SIZE || fromX < 0) {
        return true;
    }

    if(fromY >= BOARD_SIZE || fromY < 0) {
        return true;
    }

    if(toX >= BOARD_SIZE || toX < 0) {
        return true;
    }

    if(toY >= BOARD_SIZE || toY < 0) {
        return true;
    }

    return false;
}

Piece* Board::getPieceAtSquare(int row, int col) {
    if(row < 0 || row >= BOARD_SIZE) {
        return nullptr;
    }
    if(col < 0 || col >= BOARD_SIZE) {
        return nullptr;
    }
    return squares[row][col].getPiece();
}

bool Board::isBlackCheckmate() {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(getPieceAtSquare(i, j) != nullptr) {
                if(getPieceAtSquare(i, j)->getColor() == 'b') {
                    continue;
                }
                MoveData moveData = MoveData(i, j, blackKingPosition.first, blackKingPosition.second);
                if(getPieceAtSquare(i, j)->isMoveValid(moveData, *this, true)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Board::isWhiteCheckmate() {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(getPieceAtSquare(i, j) != nullptr) {
                if(getPieceAtSquare(i, j)->getColor() == 'w') {
                    continue;
                }
                MoveData moveData = MoveData(i, j, whiteKingPosition.first, whiteKingPosition.second);
                if(getPieceAtSquare(i, j)->isMoveValid(moveData, *this, true)) {
                    return true;
                }
            }
        }
    }
    return false;
}

Square* Board::getSquareAt(int row, int col) {
    if(row < 0 || row >= BOARD_SIZE) {
        return nullptr;
    }

    if(col < 0 || col >= BOARD_SIZE) {
        return nullptr;
    }

    return &(squares[row][col]);
}

std::pair<int, int> Board::getWhiteKingPosition() {
    return whiteKingPosition;
}

std::pair<int, int> Board::getBlackKingPosition() {
    return blackKingPosition;
}

void Board::setBlackKingPosition(int row, int col) {
    if(row < 0 || row >= BOARD_SIZE) {
        return;
    }

    if(col < 0 || col >= BOARD_SIZE) {
        return;
    }

    blackKingPosition = std::make_pair(row, col);
}

void Board::setWhiteKingPosition(int row, int col) {
    if(row < 0 || row >= BOARD_SIZE) {
        return;
    }

    if(col < 0 || col >= BOARD_SIZE) {
        return;
    }

    whiteKingPosition = std::make_pair(row, col);
}

std::vector<MoveData> Board::getWhitePossibleMoves() {

    std::vector<MoveData> result;
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(getPieceAtSquare(i, j) == nullptr) {
                continue;
            }
            if(getPieceAtSquare(i, j)->getColor() == 'w') {

                for(MoveData& md : getPieceAtSquare(i, j)->getPossibleMoves(i, j, *this)) {
                    result.push_back(md);
                }
            }

        }
    }
    return result;

}

std::vector<MoveData> Board::getBlackPossibleMoves() {
    std::vector<MoveData> result;
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(getPieceAtSquare(i, j) == nullptr) {
                continue;
            }
            if(getPieceAtSquare(i, j)->getColor() == 'b') {
                for(MoveData& md : getPieceAtSquare(i, j)->getPossibleMoves(i, j, *this)) {
                    result.push_back(md);
                }
            }

        }
    }

    return result;
}

bool Board::isHistoryEmpty() {
    return historyMoves.empty();
}