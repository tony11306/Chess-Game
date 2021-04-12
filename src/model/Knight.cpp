#include "Knight.h"
#include "Board.h"

Knight::Knight(char color) {
    if(color == 'w') {
        pieceId = WHITE_KNIGHT;
    } else {
        pieceId = BLACK_KNIGHT;
    }
    hasMoved = false;
    this->color = color;
}

bool Knight::isMoveValid(MoveData& moveData, Board& board, bool checkmateDetectLock) {
    int fromX = moveData.getFromX();
    int fromY = moveData.getFromY();
    int toX = moveData.getToX();
    int toY = moveData.getToY();

    if(isTargetFriendly(toX, toY, board)) {
        return false;
    }

    std::pair<int, int> step[8] = {
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2},
    };

    for(int i = 0; i < 8; ++i) {
        if(fromX + step[i].first == toX && fromY + step[i].second == toY) {
            if(!checkmateDetectLock && isMoveGoingToCheckmate(moveData, board)) {
                return false;
            }
            return true;
        }
    }
    return false;
}