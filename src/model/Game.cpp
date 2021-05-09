#include "Game.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>


Game::Game() {
    board = new Board();
    board->initBoard();
    isWhiteTurn = true;
}

Game::~Game() {
    delete board;
}

Board* Game::getBoard() {
    return board;
}

void Game::moveExecute(MoveData& moveData) {
    if(board->getPieceAtSquare(moveData.getFromX(), moveData.getFromY()) == nullptr) {
        return;
    }

    if(board->getPieceAtSquare(moveData.getFromX(), moveData.getFromY())->getColor() == 'b' && isWhiteTurn) {
        return;
    }

    if(board->getPieceAtSquare(moveData.getFromX(), moveData.getFromY())->getColor() == 'w' && !isWhiteTurn) {
        return;
    }

    Piece* previousPiece = board->getPieceAtSquare(moveData.getFromX(), moveData.getFromY());

    board->movePiece(moveData);

    if(previousPiece != board->getPieceAtSquare(moveData.getFromX(), moveData.getFromY())) {
        switchTurn();
    }
    
}

void Game::switchTurn() {
    isWhiteTurn = !isWhiteTurn;
}

bool Game::checkIsWhiteTurn() {
    return isWhiteTurn;
}


bool Game::isWhiteWin() {
    if(!isWhiteTurn && board->isBlackCheckmate()) {
        if(board->getBlackPossibleMoves().size() == 0) {
            return true;
        }
    }
    return false;
}

bool Game::isBlackWin() {
    if(isWhiteTurn && board->isWhiteCheckmate()) {
        if(board->getWhitePossibleMoves().size() == 0) {
            return true;
        }
    }
    return false;
}

bool Game::isStalemate() {

    if(isWhiteTurn && board->getWhitePossibleMoves().size() == 0) {
        if(!board->isWhiteCheckmate()) {
            return true;
        }
    }

    if(!isWhiteTurn && board->getBlackPossibleMoves().size() == 0) {
        if(!board->isBlackCheckmate()) {
            return true;
        }
    }

    return false;
}
