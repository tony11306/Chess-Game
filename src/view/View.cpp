#include "View.h"

View::View(sf::RenderWindow* window) {
    this->window = window;
}
std::vector<sf::Sprite>& View::getEntities(){
    return itemsToDraw;
}

void View::draw() {
    for(int i = 0; i < itemsToDraw.size(); ++i) {
        window->draw(itemsToDraw[i]);
    }
}