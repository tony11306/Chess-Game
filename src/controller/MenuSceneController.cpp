#include "MenuSceneController.h"

MenuSceneController::MenuSceneController(sf::RenderWindow* window) {
    this->window = window;
}

State MenuSceneController::run() {
    while(window->isOpen()) {

        sf::Event event;

        while(window->pollEvent(event)) {

            switch(event.type) {







                default:
                    break;
            }
        }

        window->clear();

        window->display();

    }

    return EXIT;

}