#include "GameSceneController.h"
#include <iostream>

GameSceneController::GameSceneController(sf::RenderWindow* window) {

    game = nullptr;
    view = nullptr;
    this->window = window;
    gameState = UNINITIALIZED;
    isDragging = false;
    draggingPieceIndex = 1;
    dragFromX = 0;
    dragFromY = 0;
    dragToX = 0;
    dragToY = 0;

}

GameSceneController::~GameSceneController() {

    delete game;
    delete view;

}

void GameSceneController::init() {

    delete game;
    delete view;

    game = new Game();
    view = new GameView(window, game);
    view->update();

    gameState = READY_TO_START;

}

void GameSceneController::handleEvents() {

    sf::Event event;
    int mouseX = sf::Mouse::getPosition(*window).x;
    int mouseY = sf::Mouse::getPosition(*window).y;
    int deltaX = 45;
    int deltaY = 45;

    while(window->pollEvent(event)) {

        if(event.type == sf::Event::Closed) {

            gameState = EXITING;
            return;

        } else if(event.type == sf::Event::MouseButtonPressed) {

            if(event.mouseButton.button == sf::Mouse::Left) {

                if(!isDragging) {

                    dragFromX = (mouseX-30)/PIECE_HORIZONTAL_GAP; // the variable name needs to be refactor
                    dragFromY = (mouseY-15)/PIECE_VERTICAL_GAP;

                    for(int i = 1; i < view->getEntities().size(); ++i) {

                        if(view->getEntities()[i].getGlobalBounds().contains(mouseX, mouseY)) {
                            
                            isDragging = true;
                            draggingPieceIndex = i;
                            Board* board = game->getBoard();
                            
                            std::vector<MoveData> possibleMoves = board->getPieceAtSquare(dragFromY, dragFromX)->getPossibleMoves(dragFromY, dragFromX, *board);
                            
                            std::cout << "-------" << std::endl;
                            std::cout << "Possible move:" << std::endl;
                            
                            for(int i = 0; i < possibleMoves.size(); ++i) {
                                std::cout << possibleMoves[i].getFromY() << " " << possibleMoves[i].getFromX() << " " << possibleMoves[i].getToY() << " " << possibleMoves[i].getToX() << std::endl;
                            }
                            std::cout << "-------" << std::endl;
                            
                            break;
                        }

                    }
                }
            }

        } else if(event.type == sf::Event::MouseButtonReleased) {

            if(isDragging) {

                dragToX = (mouseX-30)/PIECE_HORIZONTAL_GAP;
                dragToY = (mouseY-15)/PIECE_VERTICAL_GAP;
                std::cout << dragFromX << " " << dragFromY << " " << dragToX << " " << dragToY << "\n";

                MoveData moveData(dragFromY, dragFromX, dragToY, dragToX);
                game->moveExecute(moveData);
                isDragging = false;
                view->update();

            }
        }
    }

    if(isDragging) {
        view->getEntities()[draggingPieceIndex].setPosition(sf::Vector2f(mouseX-deltaX, mouseY-deltaY));
    }

}

State GameSceneController::run() {

    if(gameState == UNINITIALIZED) {
        throw "The game is not initialized. Please call the init() function first.";
    }

    while(gameState != EXITING) {

        handleEvents();

        window->clear();

        view->draw();
        
        window->display();

    } 

    return EXIT;
    
}