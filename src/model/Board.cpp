#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"

#include <iostream>
#include <iomanip>

Board::Board() {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j  = 0; j < BOARD_SIZE; ++j) {
            squares[i][j].setRow(i);
            squares[i][j].setCol(j);
            // std::cout << squares[i][j].getRow() << "/" << squares[i][j].getCol() << " ";
        }
        // std::cout << "\n";
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

    blackKingPosition = {0, 3};
    whiteKingPosition = {7, 3};
}


void Board::print() {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << std::setw(4) << i;
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(squares[i][j].getPiece() != nullptr) {
                std::cout << std::setw(3) << squares[i][j].getPiece()->getPieceID();
            } else {
                std::cout << std::setw(3) << "-";
            }
            
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << std::setw(3) << " ";
    for(int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << std::setw(3) << i;
    }
    std::cout << "\n";
}

void Board::movePiece(MoveData& moveData) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(isOutside(moveData)) {
        std::cout << "Out of board!\n";
        return;
    }

    if(squares[fromX][fromY].getPiece() == nullptr) {
        std::cout << "Can't move the empty piece!\n";
        return;
    }

    if(!squares[fromX][fromY].getPiece()->isMoveValid(moveData, *this)) {
        std::cout << "invalid move!\n";
        return;
    }


    // when the move is valid, do the move and check 
    std::cout << "valid move!\n";
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
                std::cout << "test\n";
                squares[fromX][3].setPiece(squares[fromX][0].getPiece());
                squares[fromX][0].setPiece(nullptr);
            } 

        }

        if(squares[toX][toY].getPiece()->getPieceID() == WHITE_KING) {
            whiteKingPosition.first = toX;
            whiteKingPosition.second = toY;
        } else {
            blackKingPosition.first = toX;
            blackKingPosition.second = toY;
        }
        return;

    } else if (squares[fromX][fromY].getPiece()->getPieceID() == WHITE_PAWN || squares[fromX][fromY].getPiece()->getPieceID() == BLACK_PAWN) {

        if(fromY == toY && (abs(toX-fromX) == 2 || abs(toX-fromX) == 1)) {

            if(abs(toX-fromX) == 2) {
                dynamic_cast<Pawn*>(squares[fromX][fromY].getPiece())->setCanBeEnPassant(true);
                squares[fromX][fromY].getPiece()->setMoved(true);
            }

            squares[toX][toY].setPiece(squares[fromX][fromY].getPiece());
            squares[fromX][fromY].setPiece(nullptr);
            
        } else {

            if(squares[fromX][toY].getPiece() == nullptr) {
                squares[toX][toY].setPiece(squares[fromX][fromY].getPiece());
                squares[fromX][fromY].setPiece(nullptr);
            } else { // en passant
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
                if(getPieceAtSquare(i, j)->isMoveValid(moveData, *this)) {
                    // std::cout << "black checkmate!\n";
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
                if(getPieceAtSquare(i, j)->isMoveValid(moveData, *this)) {
                    // std::cout << i << " " << j << "\n";
                    // std::cout << "white checkmate!\n";
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