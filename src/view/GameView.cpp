#include "GameView.h"

GameView::GameView(sf::RenderWindow* window, Game* game) {
    this->game = game;
    this->window = window;

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
}

GameView::~GameView() {
    delete game;
}

void GameView::update() {
    pieceEntities.clear();
    pieceEntities.push_back(sf::Sprite(BOARD));
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(game->getBoard()->getPieceAtSquare(i, j) != nullptr) {
                switch(game->getBoard()->getPieceAtSquare(i, j)->getPieceID()) {
                    case WHITE_KING:
                        pieceEntities.push_back(sf::Sprite(WHITE_KING_TEXTURE));
                        break;
                    case WHITE_BISHOP:
                        pieceEntities.push_back(sf::Sprite(WHITE_BISHOP_TEXTURE));
                        break;
                    case WHITE_KNIGHT:
                        pieceEntities.push_back(sf::Sprite(WHITE_KNIGHT_TEXTURE));
                        break;
                    case WHITE_QUEEN:
                        pieceEntities.push_back(sf::Sprite(WHITE_QUEEN_TEXTURE));
                        break;
                    case WHITE_ROOK:
                        pieceEntities.push_back(sf::Sprite(WHITE_ROOK_TEXTURE));
                        break;
                    case WHITE_PAWN:
                        pieceEntities.push_back(sf::Sprite(WHITE_PAWN_TEXTURE));
                        break;
                    case BLACK_KING:
                        pieceEntities.push_back(sf::Sprite(BLACK_KING_TEXTURE));
                        break;
                    case BLACK_BISHOP:
                        pieceEntities.push_back(sf::Sprite(BLACK_BISHOP_TEXTURE));
                        break;
                    case BLACK_KNIGHT:
                        pieceEntities.push_back(sf::Sprite(BLACK_KNIGHT_TEXTURE));
                        break;
                    case BLACK_QUEEN:
                        pieceEntities.push_back(sf::Sprite(BLACK_QUEEN_TEXTURE));
                        break;
                    case BLACK_ROOK:
                        pieceEntities.push_back(sf::Sprite(BLACK_ROOK_TEXTURE));
                        break;
                    case BLACK_PAWN:
                        pieceEntities.push_back(sf::Sprite(BLACK_PAWN_TEXTURE));
                        break;
                }
                pieceEntities.back().setPosition(30.f + (j*PIECE_VERTICAL_GAP), 15.0f + (i*PIECE_HORIZONTAL_GAP));
            }
        }
    }
}

void GameView::draw() {
    for(int i = 0; i < pieceEntities.size(); ++i) {
        window->draw(pieceEntities[i]);
    }
}

std::vector<sf::Sprite>& GameView::getEntities() {
    return pieceEntities;
}

