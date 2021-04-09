#include "Game.h"
#include <SFML/Graphics.hpp>
#include "GameSceneController.h"
#include <iostream>

using namespace std;

const unsigned int FPS_LIMIT = 60;

int main() {

    sf::RenderWindow window(sf::VideoMode(900, 807), "SFML really works!");
    window.setFramerateLimit(FPS_LIMIT);

    GameSceneController gameSceneController(&window);
    gameSceneController.init();
    gameSceneController.run();

    window.close();
    system("pause");
    return 0;
}