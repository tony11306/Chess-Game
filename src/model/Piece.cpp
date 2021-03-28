#include "Piece.h"


Piece::Piece() {
    
}

char Piece::getColor() {
    return color;
}

bool Piece::isTargetCapturable(Piece* board[][BOARD_SIZE], Movement& movement) {

    int fromX = std::get<0>(movement.getData());
    int fromY = std::get<1>(movement.getData());
    int toX = std::get<2>(movement.getData());
    int toY = std::get<3>(movement.getData());

    if(pieceId == EMPTY) {
        return false;
    }

    if(color == 'w') { // is white
        if(board[toX][toY]->getColor() == 'b') {
            return true;
        }
    } else { // is black
        if(board[toX][toY]->getColor() == 'w') {
            return true;
        }
    }
    return false;
}

ID Piece::getPieceID() {
    return pieceId;
}

bool Piece::checkAlive() {
    return isAlive;
}

bool Piece::checkMoved() {
    return hasMoved;
}

void Piece::setAlive(bool alive) {
    isAlive = alive;
}

void Piece::setMoved(bool moved) {
    hasMoved = moved;
}

Pawn::Pawn(char color) {
    this->color = color;
    if(color == 'w') {
        this->pieceId = WHITE_PAWN; 
    } else {
        this->pieceId = BLACK_PAWN;
    }
    
    this->hasMoved = false;
    this->isAlive = true;
}

bool Pawn::isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement& movement) {
    // 判斷所有邏輯
    int fromX = std::get<0>(movement.getData());
    int fromY = std::get<1>(movement.getData());
    int toX = std::get<2>(movement.getData());
    int toY = std::get<3>(movement.getData());
    // white up, black down
    if(hasMoved) {
        if(pieceId == WHITE_PAWN) {
            if(fromX == toX && toY-fromY == 1 && board[toX][toY]->getPieceID() == EMPTY) { // normal move up
                return true;
            } else if() { // if white capture move
                
            }
        } else { // if it's black pawn

            if(fromX == toX && fromY-toY == 1 && board[toX][toY]->getPieceID() == EMPTY) {
                return true;
            } else if() { // if black capture move

            }

        }
    } else {
        if(pieceId == WHITE_PAWN) {

        } else {

        }
    }
}


Knight::Knight(char color) {
    this->color = color;
    if(color == 'w') {
        this->pieceId = WHITE_KNIGHT; 
    } else {
        this->pieceId = BLACK_KNIGHT;
    }
    this->hasMoved = false;
    this->isAlive = true;
}

bool Knight::isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement& movement) {
    // 判斷所有邏輯
}


Queen::Queen(char color) {
    this->color = color;
    if(color == 'w') {
        this->pieceId = WHITE_QUEEN; 
    } else {
        this->pieceId = BLACK_QUEEN;
    }
    this->hasMoved = false;
    this->isAlive = true;
}

bool Queen::isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement& movement) {
    // 判斷所有邏輯
}

Rook::Rook(char color) {
    this->color = color;
    if(color == 'w') {
        this->pieceId = WHITE_ROOK; 
    } else {
        this->pieceId = BLACK_ROOK;
    }
    this->hasMoved = false;
    this->isAlive = true;
}

bool Rook::isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement& movement) {
    // 判斷所有邏輯
}


Bishop::Bishop(char color) {
    this->color = color;
    if(color == 'w') {
        this->pieceId = WHITE_BISHOP; 
    } else {
        this->pieceId = BLACK_BISHOP;
    }
    this->hasMoved = false;
    this->isAlive = true;
}

bool Bishop::isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement& movement) {
    // 判斷所有邏輯
}

King::King(char color) {
    this->color = color;
    if(color == 'w') {
        this->pieceId = WHITE_KING; 
    } else {
        this->pieceId = BLACK_KING;
    }
    this->hasMoved = false;
    this->isAlive = true;
}

bool King::isMoveValid(Piece* board[BOARD_SIZE][BOARD_SIZE], Movement& movement) {
    // 判斷所有邏輯
}