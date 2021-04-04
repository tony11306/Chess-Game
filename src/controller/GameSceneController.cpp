#include "GameSceneController.h"

GameSceneController::GameSceneController(sf::RenderWindow* window) {
    this->window = window;
}

GameSceneController::~GameSceneController() {
    delete game;
    delete view;
}

State GameSceneController::run() {
    game = new Game();
    view = new GameView(window, game);
    view->update();

    while(window->isOpen()) {
        sf::Event event;
        while(window->pollEvent(event)) {

            switch(event.type) {







                default:
                    break;
            }
        }

        window->clear();

        view->draw();

        window->display();

    }

    return EXIT;
    
}