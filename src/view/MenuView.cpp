#include "MenuView.h"

MenuView::MenuView(sf::RenderWindow* window) {
    this->window = window;
    //BUTTON_TEXTURE.loadFromFile();
    //BACKGROUND_TEXTURE.loadFromFile();

}

MenuView::~MenuView() {

}

void MenuView::update() {
    buttonEntities.clear();
    // buttonEntities.push_back(sf::Sprite(BACKGROUND_TEXTURE)); 
    //buttonEntities.back().setPosition(30.f + (j*PIECE_VERTICAL_GAP), 15.0f + (i*PIECE_HORIZONTAL_GAP));//調整位置
}

void MenuView::draw() {
    for(int i = 0; i < buttonEntities.size(); ++i) {
        window->draw(buttonEntities[i]);
    }
}

std::vector<sf::Sprite>& MenuView::getEntities() {
    return buttonEntities;
}

