#include "Game.h"


Game::Game(std::string whitePlayerName, std::string blackPlayerName) {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = nullptr;
        }
    }
}

bool Game::isMoveInRange(Movement& movement) {
    int fromX = std::get<0>(movement.getData());
    int fromY = std::get<1>(movement.getData());
    int toX = std::get<2>(movement.getData());
    int toY = std::get<3>(movement.getData());

    if(fromX >= 0 && fromX < BOARD_SIZE && fromY >= 0 && fromY < BOARD_SIZE) {
        if(toX >= 0 && toX < BOARD_SIZE && toY >= 0 && toY < BOARD_SIZE) {
            return true;
        }
    }
    return false;
}

void Game::moveExecute(Movement& movement) {
    
}

bool Game::isMoveInRange(Movement& movement) {

}

void Game::resetBoard() {

}

bool Game::isGameOver() {

}