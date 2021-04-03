#include "Game.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>


Game::Game() {
    board = new Board();
    board->initBoard();
    int a, b, c, d;
    board->print();
    while(std::cin >> a >> b >> c >> d) {
        MoveData md = MoveData(a, b, c, d);
        board->movePiece(md);
        board->print();

    }
}

Game::~Game() {
    delete board;
}