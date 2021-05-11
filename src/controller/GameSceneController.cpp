#include "GameSceneController.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include <iostream>

GameSceneController::GameSceneController(sf::RenderWindow& window): mainWindow(window) {

    game = nullptr;
    view = nullptr;
    gameState = UNINITIALIZED;
    isDragging = false;
    draggingPieceIndex = 1;
    draggingPiece = nullptr;
    dragFromX = 0;
    dragFromY = 0;
    dragToX = 0;
    dragToY = 0;
    draggingPiecePossibleMoves = {};

}

GameSceneController::~GameSceneController() {
    delete view;
}

void GameSceneController::init() {

    GameView* oldGameView = view;

    game = new Game();
    view = new GameView(mainWindow, game);

    view->update();
    
    delete oldGameView;
    
    gameState = READY_TO_START;

}

void GameSceneController::onClosedWindow() {
    gameState = EXITING;
}

void GameSceneController::onMouseButtonPressed(sf::Event event) {
    int mouseX = sf::Mouse::getPosition(mainWindow).x;
    int mouseY = sf::Mouse::getPosition(mainWindow).y;

    if(event.mouseButton.button == sf::Mouse::Left) {

        if(!isDragging) {

            dragFromX = (mouseX-30)/PIECE_HORIZONTAL_GAP; // the variable name needs to be refactor
            dragFromY = (mouseY-15)/PIECE_VERTICAL_GAP;
            for(sf::Sprite& pieceSprite : view->getPieceSprites()) {
                if(pieceSprite.getGlobalBounds().contains(mouseX, mouseY)) {

                    isDragging = true;
                    draggingPiece = &pieceSprite;
                    Board* board = game->getBoard();

                    draggingPiecePossibleMoves = board->getPieceAtSquare(dragFromY, dragFromX)->getPossibleMoves(dragFromY, dragFromX, *board);

                    std::cout << "-------" << std::endl;
                    std::cout << "Possible move:" << std::endl;

                    for(MoveData& moveData : draggingPiecePossibleMoves) {
                        std::cout << moveData.getFromY() << " " << moveData.getFromX() << " " << moveData.getToY() << " " << moveData.getToX() << std::endl;
                    }
                    
                    std::cout << "-------" << std::endl;
                    break;
                }
            }

        }
    }
}

void GameSceneController::onMouseButtonReleased(sf::Event event) {

    int mouseX = sf::Mouse::getPosition(mainWindow).x;
    int mouseY = sf::Mouse::getPosition(mainWindow).y;
    
    if(isDragging) {

        dragToX = (mouseX-30)/PIECE_HORIZONTAL_GAP;
        dragToY = (mouseY-15)/PIECE_VERTICAL_GAP;
        std::cout << dragFromX << " " << dragFromY << " " << dragToX << " " << dragToY << "\n";

        MoveData moveData(dragFromY, dragFromX, dragToY, dragToX);
        Piece* before = game->getBoard()->getPieceAtSquare(dragFromY, dragFromX);
        game->moveExecute(moveData);
        Piece* after = game->getBoard()->getPieceAtSquare(dragToY, dragToX);
        
        if(after == before && before != nullptr) {
            ID promotePiece = EMPTY;
            if(before->getPieceID() == WHITE_PAWN && dragToY == 0) {
                promotePiece = onPromotion();
            } else if(before->getPieceID() == BLACK_PAWN && dragToY == 7) {
                promotePiece = onPromotion();
            }

            if(promotePiece != EMPTY) {
                switch(promotePiece) {
                    case WHITE_QUEEN:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Queen('w'));
                        break;
                    case BLACK_QUEEN:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Queen('b'));
                        break;
                    case WHITE_KNIGHT:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Knight('w'));
                        break;
                    case BLACK_KNIGHT:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Knight('b'));
                        break;
                    case WHITE_BISHOP:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Bishop('w'));
                        break;
                    case BLACK_BISHOP:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Bishop('b'));
                        break;
                    case WHITE_ROOK:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Rook('w'));
                        break;
                    case BLACK_ROOK:
                        game->getBoard()->getSquareAt(dragToY, dragToX)->deletePiece();
                        game->getBoard()->getSquareAt(dragToY, dragToX)->setPiece(new Rook('b'));
                        break;
                }
            }

        }

        isDragging = false;
        draggingPiecePossibleMoves = {};
        view->setPossibleMoves(draggingPiecePossibleMoves);

        if(game->isBlackWin()) {
            gameState = GAME_OVER;
            view->setBlackWinTextVisible(true);
        } else if(game->isWhiteWin()) {
            gameState = GAME_OVER;
            view->setWhiteWinTextVisible(true);
        } else if(game->isStalemate()) {
            gameState = GAME_OVER;
            view->setStalemateTextVisible(true);
        }
        view->update();

    }
}

ID GameSceneController::onPromotion() {
    PromotionView pv(mainWindow, !game->checkIsWhiteTurn());
    view->update();
    while(true) {

        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                mainWindow.close();
            } else if(event.type == sf::Event::MouseButtonPressed) {
                if(pv.isMouseOnBiship(sf::Mouse::getPosition(mainWindow))) {
                    if(game->checkIsWhiteTurn()) {
                        return BLACK_BISHOP;
                    }
                    return WHITE_BISHOP; 
                }

                if(pv.isMouseOnKnight(sf::Mouse::getPosition(mainWindow))) {
                    if(game->checkIsWhiteTurn()) {
                        return BLACK_KNIGHT;
                    }
                    return WHITE_KNIGHT;
                }

                if(pv.isMouseOnQueen(sf::Mouse::getPosition(mainWindow))) {
                    if(game->checkIsWhiteTurn()) {
                        return BLACK_QUEEN;
                    }
                    return WHITE_QUEEN;
                }

                if(pv.isMouseOnRook(sf::Mouse::getPosition(mainWindow))) {
                    if(game->checkIsWhiteTurn()) {
                        return BLACK_ROOK;
                    }
                    return WHITE_ROOK;
                }
            }
        }

        pv.update();
        mainWindow.clear();
        view->draw();
        pv.draw();
        mainWindow.display();
    }
}



void GameSceneController::handleEvents() {

    sf::Event event;
    int mouseX = sf::Mouse::getPosition(mainWindow).x;
    int mouseY = sf::Mouse::getPosition(mainWindow).y;
    int deltaX = 45;
    int deltaY = 45;

    while(mainWindow.pollEvent(event)) {

        if(event.type == sf::Event::Closed) {
            onClosedWindow();
            return;
        } else if(event.type == sf::Event::MouseButtonPressed && gameState != GAME_OVER) {
            onMouseButtonPressed(event);
        } else if(event.type == sf::Event::MouseButtonReleased) {
            onMouseButtonReleased(event);
        }
    }

    if(view->getResetButton()->isPressed()) {
        init();
    }

    if(isDragging) {
        draggingPiece->setPosition(sf::Vector2f(mouseX-deltaX, mouseY-deltaY));
        // view->getPieceSprites()[draggingPieceIndex].setPosition(sf::Vector2f(mouseX-deltaX, mouseY-deltaY));
        view->setPossibleMoves(draggingPiecePossibleMoves);
    }

}

State GameSceneController::run() {

    if(gameState == UNINITIALIZED) {
        throw "The game is not initialized. Please call the init() function first.";
    }

    while(gameState != EXITING) {

        handleEvents();

        mainWindow.clear(sf::Color(49, 46, 43, 1));

        view->getResetButton()->update(sf::Mouse::getPosition(mainWindow));

        view->draw();


        mainWindow.display();

    } 
    std::cout << "Exiting..." << std::endl;
    return EXIT;
    
}