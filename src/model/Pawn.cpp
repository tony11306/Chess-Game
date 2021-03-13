#include "Pawn.h"

Pawn::Pawn(char color, char id) {
    this->color = color;
    this->pieceId = id;
    this->hasMoved = false;
    this->isAlive = true;
}

bool Pawn::isMoveValid(int, int, int, int) {
    // 只定義最基本移動規則 例如主教是否走斜線 城堡是否走直線
}