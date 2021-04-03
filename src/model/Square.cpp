#include "Square.h"
#include "Piece.h"
#include <iostream>

Square::Square() {
    row = -1;
    col = -1;
    piece = nullptr;
    
}

Square::~Square() {
    delete piece;
    
}

void Square::setCol(int col) {
    this->col = col;
}

void Square::setRow(int row) {
    this->row = row;
}

void Square::setPiece(Piece* piece) {
    this->piece = piece;
}

int Square::getCol() {
    return col;
}

int Square::getRow() {
    return row;
}

Piece* Square::getPiece() {
    return piece;
}

void Square::deletePiece() {
    delete piece;
}



