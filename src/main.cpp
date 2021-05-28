#include "Game.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "GameSceneController.h"
#include <iostream>

using namespace std;

const unsigned int FPS_LIMIT = 60;
sf::Image icon;

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    icon.loadFromFile("imgs/KnightBlack.png");
    sf::RenderWindow window(sf::VideoMode(1100, 807), "Simple Chess Game", sf::Style::Titlebar | sf::Style::Close);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(FPS_LIMIT);
    
    GameSceneController gameSceneController(window);
    gameSceneController.init();
    gameSceneController.run();
    window.close();
    return 0;
}