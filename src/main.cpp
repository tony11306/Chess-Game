#include "Game.h"
#include <SFML/Graphics.hpp>
#include "GameSceneController.h"
#include <iostream>

using namespace std;

const unsigned int FPS_LIMIT = 60;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(1100, 807), "Simple Chess Game");
    window.setFramerateLimit(FPS_LIMIT);
    
    GameSceneController gameSceneController(window);
    gameSceneController.init();
    gameSceneController.run();
    
   
  /*
    sf::Font font;
    font.loadFromFile("arial.ttf");
    PromotionView pv(window, true);
    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        pv.update();
        window.clear();
        pv.draw();
        window.display();
    }
    
    */
    window.close();
    return 0;
}