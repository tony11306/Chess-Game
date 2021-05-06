#include "GameSceneController.h"
#include <iostream>

GameSceneController::GameSceneController(sf::RenderWindow& window): mainWindow(window) {

    game = nullptr;
    view = nullptr;
    gameState = UNINITIALIZED;
    isDragging = false;
    draggingPieceIndex = 1;
    dragFromX = 0;
    dragFromY = 0;
    dragToX = 0;
    dragToY = 0;
    draggingPiecePossibleMoves = {};

}

GameSceneController::~GameSceneController() {

    delete game;
    delete view;

}

void GameSceneController::init() {

    delete game;
    delete view;

    game = new Game();
    view = new GameView(mainWindow, game);
    view->update();

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

            for(int i = 1; i < view->getEntities().size(); ++i) {

                if(view->getEntities()[i].getGlobalBounds().contains(mouseX, mouseY)) {
                    
                    isDragging = true;
                    draggingPieceIndex = i;
                    Board* board = game->getBoard();
                    
                    draggingPiecePossibleMoves = board->getPieceAtSquare(dragFromY, dragFromX)->getPossibleMoves(dragFromY, dragFromX, *board);
                    
                    std::cout << "-------" << std::endl;
                    std::cout << "Possible move:" << std::endl;
                    
                    for(int i = 0; i < draggingPiecePossibleMoves.size(); ++i) {
                        std::cout << draggingPiecePossibleMoves[i].getFromY() << " " << draggingPiecePossibleMoves[i].getFromX() << " " << draggingPiecePossibleMoves[i].getToY() << " " << draggingPiecePossibleMoves[i].getToX() << std::endl;
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
        game->moveExecute(moveData);
        isDragging = false;
        draggingPiecePossibleMoves = {};
        view->setPossibleMoves(draggingPiecePossibleMoves);
        view->update();

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
        } else if(event.type == sf::Event::MouseButtonPressed) {
            onMouseButtonPressed(event);
        } else if(event.type == sf::Event::MouseButtonReleased) {
            onMouseButtonReleased(event);
        }
    }

    if(isDragging) {
        view->getEntities()[draggingPieceIndex].setPosition(sf::Vector2f(mouseX-deltaX, mouseY-deltaY));
        view->setPossibleMoves(draggingPiecePossibleMoves);
    }

}

State GameSceneController::run() {

    if(gameState == UNINITIALIZED) {
        throw "The game is not initialized. Please call the init() function first.";
    }

    while(gameState != EXITING) {

        handleEvents();

        mainWindow.clear();

        view->draw();


        mainWindow.display();

    } 
    std::cout << "Exiting..." << std::endl;
    return EXIT;
    
}