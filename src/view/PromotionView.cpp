#include "PromotionView.h"

PromotionView::PromotionView(sf::RenderWindow& window, bool isWhiteTurn) : mainWindow(window) {

    if(isWhiteTurn) {
        ROOK_TEXTURE.loadFromFile("imgs/RookWhite.png");
        BISHOP_TEXTURE.loadFromFile("imgs/BishopWhite.png");
        QUEEN_TEXTURE.loadFromFile("imgs/QueenWhite.png");
        KNIGHT_TEXTURE.loadFromFile("imgs/KnightWhite.png");
    } else {
        ROOK_TEXTURE.loadFromFile("imgs/RookBlack.png");
        BISHOP_TEXTURE.loadFromFile("imgs/BishopBlack.png");
        QUEEN_TEXTURE.loadFromFile("imgs/QueenBlack.png");
        KNIGHT_TEXTURE.loadFromFile("imgs/KnightBlack.png");
    }

    rook = sf::Sprite(ROOK_TEXTURE);
    bishop = sf::Sprite(BISHOP_TEXTURE);
    queen = sf::Sprite(QUEEN_TEXTURE);
    knight = sf::Sprite(KNIGHT_TEXTURE);

    queen.setPosition(190, 380);
    bishop.setPosition(280, 380);
    rook.setPosition(370, 380);
    knight.setPosition(460, 380);
    
    this->font.loadFromFile("arial.ttf");

    title.setFont(font);
    title.setString("Promotion");
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(30);
    title.setPosition(300.f, 330.f);

    background.setPosition(150.f, 350.f);
    background.setSize(sf::Vector2(450.f, 150.f));
    background.setFillColor(sf::Color(155, 155, 155, 200));
}

void PromotionView::draw() {
    mainWindow.draw(background);
    mainWindow.draw(queen);
    mainWindow.draw(knight);
    mainWindow.draw(rook);
    mainWindow.draw(bishop);
    mainWindow.draw(title);
}

void PromotionView::update() {

    if(isMouseOnBiship(sf::Mouse::getPosition(mainWindow))) {
        bishop.setColor(sf::Color(150, 150, 150));
    } else {
        bishop.setColor(sf::Color::White);
    }
    
    if(isMouseOnQueen(sf::Mouse::getPosition(mainWindow))) {
        queen.setColor(sf::Color(150, 150, 150));
    } else {
        queen.setColor(sf::Color::White);
    }

    if(isMouseOnKnight(sf::Mouse::getPosition(mainWindow))) {
        knight.setColor(sf::Color(150, 150, 150));
    } else {
        knight.setColor(sf::Color::White);
    }

    if(isMouseOnRook(sf::Mouse::getPosition(mainWindow))) {
        rook.setColor(sf::Color(150, 150, 150));
    } else {
        rook.setColor(sf::Color::White);
    }

}

bool PromotionView::isMouseOnBiship(sf::Vector2i mousePosition) {
    return bishop.getGlobalBounds().contains(mousePosition.x, mousePosition.y);
}

bool PromotionView::isMouseOnKnight(sf::Vector2i mousePosition) {
    return knight.getGlobalBounds().contains(mousePosition.x, mousePosition.y);
}

bool PromotionView::isMouseOnQueen(sf::Vector2i mousePosition) {
    return queen.getGlobalBounds().contains(mousePosition.x, mousePosition.y);
}

bool PromotionView::isMouseOnRook(sf::Vector2i mousePosition) {
    return rook.getGlobalBounds().contains(mousePosition.x, mousePosition.y);
}

