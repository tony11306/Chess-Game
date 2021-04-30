#include "Knight.h"
#include "Board.h"
#include <iostream>

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

std::vector<MoveData> Knight::getPossibleMoves(int currentX, int currentY, Board& board) {
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
    std::vector<MoveData> result;
    
    for(int i = 0; i < 8; ++i) {
        MoveData moveData = MoveData(currentX, currentY, currentX+step[i].first, currentY+step[i].second);
        if(isMoveValid(moveData, board)) {
            result.push_back(moveData);
        }
        
    }
    
    return result;
}