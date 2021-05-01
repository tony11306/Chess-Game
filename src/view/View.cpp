#include "View.h"

View::View(sf::RenderWindow& window) : mainWindow(window) {
    
}
std::vector<sf::Sprite>& View::getEntities(){
    return itemsToDraw;
}

void View::draw() {
    for(int i = 0; i < itemsToDraw.size(); ++i) {
        mainWindow.draw(itemsToDraw[i]);
    }
}

View::~View() {
    
}