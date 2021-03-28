#include "Game.h"


Game::Game(std::string whitePlayerName, std::string blackPlayerName) {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = nullptr;
        }
    }
}


void Game::moveExecute(Movement movement) {
    
}

bool Game::isMoveValid(Movement movement) {

}

void Game::resetBoard() {

}

bool Game::isGameOver() {

}