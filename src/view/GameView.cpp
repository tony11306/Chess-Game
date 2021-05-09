#include "GameView.h"

#include <iostream>

GameView::GameView(sf::RenderWindow& window, Game* game)
: mainWindow(window) {
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
    BOARD_TEXTURE.loadFromFile("imgs/board.png");
    boardSprite = sf::Sprite(BOARD_TEXTURE);
    
    if (!font.loadFromFile("arial.ttf")) {
        throw "Unable to find the arial.ttf file";
    }
    playerTurnText.setFont(font);
    playerTurnText.setString("Current turn: White");
    playerTurnText.setPosition(850.f, 300.f);
    playerTurnText.setCharacterSize(20);
    playerTurnText.setFillColor(sf::Color::White);

    whiteWinText.setFont(font);
    whiteWinText.setString("White win!");
    whiteWinText.setCharacterSize(80);
    whiteWinText.setPosition(250.f, 300.f);
    whiteWinText.setFillColor(sf::Color::Black);
    isWhiteWinTextVisible = false;

    blackWinText.setFont(font);
    blackWinText.setString("Black win!");
    blackWinText.setCharacterSize(80);
    blackWinText.setPosition(250.f, 300.f);
    blackWinText.setFillColor(sf::Color::Black);
    isBlackWinTextVisible = false;

    stalemateText.setFont(font);
    stalemateText.setString("Stalemate!");
    stalemateText.setCharacterSize(80);
    stalemateText.setPosition(250.f, 300.f);
    stalemateText.setFillColor(sf::Color::Black);
    isStalemateTextVisible = false;

    
    resetButton = new Button(850.f, 600.f, 150, 50, font, "Reset",
    sf::Color(70, 70, 70, 200),
    sf::Color(150, 150, 150, 255),
    sf::Color(20, 20, 20, 200)
    );

    moveHint = sf::CircleShape(30);
    moveHint.setFillColor(sf::Color(100, 250, 50, 50));
    
}

GameView::~GameView() {
    delete resetButton;
    delete game;
}

void GameView::update() {
    pieceSprites.clear();
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(game->getBoard()->getPieceAtSquare(i, j) != nullptr) {
                switch(game->getBoard()->getPieceAtSquare(i, j)->getPieceID()) {
                    case WHITE_KING:
                        pieceSprites.push_back(sf::Sprite(WHITE_KING_TEXTURE));
                        break;
                    case WHITE_BISHOP:
                        pieceSprites.push_back(sf::Sprite(WHITE_BISHOP_TEXTURE));
                        break;
                    case WHITE_KNIGHT:
                        pieceSprites.push_back(sf::Sprite(WHITE_KNIGHT_TEXTURE));
                        break;
                    case WHITE_QUEEN:
                        pieceSprites.push_back(sf::Sprite(WHITE_QUEEN_TEXTURE));
                        break;
                    case WHITE_ROOK:
                        pieceSprites.push_back(sf::Sprite(WHITE_ROOK_TEXTURE));
                        break;
                    case WHITE_PAWN:
                        pieceSprites.push_back(sf::Sprite(WHITE_PAWN_TEXTURE));
                        break;
                    case BLACK_KING:
                        pieceSprites.push_back(sf::Sprite(BLACK_KING_TEXTURE));
                        break;
                    case BLACK_BISHOP:
                        pieceSprites.push_back(sf::Sprite(BLACK_BISHOP_TEXTURE));
                        break;
                    case BLACK_KNIGHT:
                        pieceSprites.push_back(sf::Sprite(BLACK_KNIGHT_TEXTURE));
                        break;
                    case BLACK_QUEEN:
                        pieceSprites.push_back(sf::Sprite(BLACK_QUEEN_TEXTURE));
                        break;
                    case BLACK_ROOK:
                        pieceSprites.push_back(sf::Sprite(BLACK_ROOK_TEXTURE));
                        break;
                    case BLACK_PAWN:
                        pieceSprites.push_back(sf::Sprite(BLACK_PAWN_TEXTURE));
                        break;
                }
                pieceSprites.back().setPosition(30.f + (j*PIECE_VERTICAL_GAP), 15.0f + (i*PIECE_HORIZONTAL_GAP));
            }
        }
    }
    
    if(game->checkIsWhiteTurn()) {
        playerTurnText.setString("Current turn: White");
    } else {
        playerTurnText.setString("Current turn: Black");
    }
}

void GameView::setPossibleMoves(std::vector<MoveData>& possibleMoves) {
    this->possibleMoves = possibleMoves;
}

std::vector<sf::Sprite>& GameView::getPieceSprites() {
    return pieceSprites;
}

Button* GameView::getResetButton() {
    return resetButton;
}

void GameView::draw() {


    mainWindow.draw(boardSprite);
    mainWindow.draw(playerTurnText);

    for(int i = 0; i < pieceSprites.size(); ++i) {
        mainWindow.draw(pieceSprites[i]);
    }

    for(int i = 0; i < possibleMoves.size(); ++i) {
        moveHint.setPosition(45.f + (possibleMoves[i].getToY()*PIECE_VERTICAL_GAP), 30.0f + (possibleMoves[i].getToX()*PIECE_HORIZONTAL_GAP));
        mainWindow.draw(moveHint);
    }
    resetButton->draw(mainWindow);

    if(isBlackWinTextVisible) {
        mainWindow.draw(blackWinText);
    }
    if(isWhiteWinTextVisible) {
        mainWindow.draw(whiteWinText);
    }
    if(isStalemateTextVisible) {
        mainWindow.draw(stalemateText);
    }
}

void GameView::setWhiteWinTextVisible(bool isVisible) {
    isWhiteWinTextVisible = isVisible;
}

void GameView::setBlackWinTextVisible(bool isVisible) {
    isBlackWinTextVisible = isVisible;
}

void GameView::setStalemateTextVisible(bool isVisible) {
    isStalemateTextVisible = isVisible;
}
