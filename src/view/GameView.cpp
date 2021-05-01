#include "GameView.h"
#include <iostream>

GameView::GameView(sf::RenderWindow& window, Game* game) : View(window) {
    this->game = game;

    BLACK_KING_TEXTURE.loadFromFile("imgs/KingBlack.png");
    BLACK_QUEEN_TEXTURE.loadFromFile("imgs/QueenBlack.png");
    BLACK_BISHOP_TEXTURE.loadFromFile("imgs/BishopBlack.png");
    BLACK_KNIGHT_TEXTURE.loadFromFile("imgs/KnightBlack.png");
    BLACK_ROOK_TEXTURE.loadFromFile("imgs/RookBlack.png");
    BLACK_PAWN_TEXTURE.loadFromFile("imgs/PawnBlack.png");

    WHITE_KING_TEXTURE.loadFromFile("imgs/KingWhite.png");
    WHITE_QUEEN_TEXTURE.loadFromFile("imgs/QueenWhite.png");
    WHITE_BISHOP_TEXTURE.loadFromFile("imgs/BishopWhite.png");
    WHITE_KNIGHT_TEXTURE.loadFromFile("imgs/KnightWhite.png");
    WHITE_ROOK_TEXTURE.loadFromFile("imgs/RookWhite.png");
    WHITE_PAWN_TEXTURE.loadFromFile("imgs/PawnWhite.png");
    BOARD.loadFromFile("imgs/board.png");
    
    if (!font.loadFromFile("arial.ttf")) {
        throw "Unable to find the arial.ttf file";
    }
    playerTurnText.setFont(font);
    playerTurnText.setString("Current turn: White");
    playerTurnText.setPosition(850.f, 300.f);
    playerTurnText.setCharacterSize(20);
    playerTurnText.setFillColor(sf::Color::White);
    
}

GameView::~GameView() {
    delete game;
}

void GameView::update() {
    itemsToDraw.clear();
    itemsToDraw.push_back(sf::Sprite(BOARD));
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(game->getBoard()->getPieceAtSquare(i, j) != nullptr) {
                switch(game->getBoard()->getPieceAtSquare(i, j)->getPieceID()) {
                    case WHITE_KING:
                        itemsToDraw.push_back(sf::Sprite(WHITE_KING_TEXTURE));
                        break;
                    case WHITE_BISHOP:
                        itemsToDraw.push_back(sf::Sprite(WHITE_BISHOP_TEXTURE));
                        break;
                    case WHITE_KNIGHT:
                        itemsToDraw.push_back(sf::Sprite(WHITE_KNIGHT_TEXTURE));
                        break;
                    case WHITE_QUEEN:
                        itemsToDraw.push_back(sf::Sprite(WHITE_QUEEN_TEXTURE));
                        break;
                    case WHITE_ROOK:
                        itemsToDraw.push_back(sf::Sprite(WHITE_ROOK_TEXTURE));
                        break;
                    case WHITE_PAWN:
                        itemsToDraw.push_back(sf::Sprite(WHITE_PAWN_TEXTURE));
                        break;
                    case BLACK_KING:
                        itemsToDraw.push_back(sf::Sprite(BLACK_KING_TEXTURE));
                        break;
                    case BLACK_BISHOP:
                        itemsToDraw.push_back(sf::Sprite(BLACK_BISHOP_TEXTURE));
                        break;
                    case BLACK_KNIGHT:
                        itemsToDraw.push_back(sf::Sprite(BLACK_KNIGHT_TEXTURE));
                        break;
                    case BLACK_QUEEN:
                        itemsToDraw.push_back(sf::Sprite(BLACK_QUEEN_TEXTURE));
                        break;
                    case BLACK_ROOK:
                        itemsToDraw.push_back(sf::Sprite(BLACK_ROOK_TEXTURE));
                        break;
                    case BLACK_PAWN:
                        itemsToDraw.push_back(sf::Sprite(BLACK_PAWN_TEXTURE));
                        break;
                }
                itemsToDraw.back().setPosition(30.f + (j*PIECE_VERTICAL_GAP), 15.0f + (i*PIECE_HORIZONTAL_GAP));
            }
        }
    }
    
    if(game->checkIsWhiteTurn()) {
        playerTurnText.setString("Current turn: White");
    } else {
        playerTurnText.setString("Current turn: Black");
    }
}

void GameView::draw() {
    mainWindow.draw(playerTurnText);
    View::draw();
}

