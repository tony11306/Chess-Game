#include "GameSceneController.h"
#include <iostream>

GameSceneController::GameSceneController(sf::RenderWindow* window) {
    this->window = window;
}

GameSceneController::~GameSceneController() {
    delete view;
}

State GameSceneController::run() {
    Game game = Game();
    view = new GameView(window, &game);
    std::cout << "test";
    view->update();
    bool isDragging = false;
    int draggingPieceIndex = 1;
    int fromX = 0;
    int fromY = 0;
    int toX = 0;
    int toY = 0;

    while(window->isOpen()) {
        sf::Event event;

        while(window->pollEvent(event)) {
            int mouseX = sf::Mouse::getPosition(*window).x;
            int mouseY = sf::Mouse::getPosition(*window).y;
            int deltaX = 45;
            int deltaY = 45;
            
            switch(event.type) {

                case sf::Event::Closed:
                    delete view;
                    // delete game;
                    return EXIT;
                
                case sf::Event::MouseButtonPressed:
                    // std::cout << "key pressed\n";
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        if(!isDragging) {
                            fromX = (mouseX-30)/PIECE_HORIZONTAL_GAP;
                            fromY = (mouseY-15)/PIECE_VERTICAL_GAP;
                            for(int i = 1; i < view->getEntities().size(); ++i) {
                                // std::cout << view->getEntities()[i].getGlobalBounds().top << " " << view->getEntities()[i].getGlobalBounds().left << "\n";
                                if(view->getEntities()[i].getGlobalBounds().contains(mouseX, mouseY)) {
                                    //s td::cout << view->getEntities()[i].getGlobalBounds().width << " " << view->getEntities()[i].getGlobalBounds().height << "\n";
                                    
                                    isDragging = true;
                                    draggingPieceIndex = i;
                                    
                                    break;
                                }
                            }
                        }
                        // std::cout << mouseX << " " << mouseY << "\n";
                    }
                    break;
                
                case sf::Event::MouseButtonReleased:
                    if(isDragging) {
                        toX = (mouseX-30)/PIECE_HORIZONTAL_GAP;
                        toY = (mouseY-15)/PIECE_VERTICAL_GAP;
                        view->update();
                        std::cout << fromX << " " << fromY << " " << toX << " " << toY << "\n";
                        MoveData moveData(fromY, fromX, toY, toX);
                        game.moveExecute(moveData);
                        isDragging = false;
                        view->update();
                    }
                    break;


                default:
                    break;
            }

            if(isDragging) {
                view->getEntities()[draggingPieceIndex].setPosition(sf::Vector2f(mouseX-deltaX, mouseY-deltaY));
            }
        }

        window->clear();

        view->draw();
        

        window->display();

    } 

    return EXIT;
    
}