#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font& font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {

    this->buttonState = BUTTON_IDLE;

    this->shape.setPosition(sf::Vector2(x, y));
    this->shape.setSize(sf::Vector2(width, height));

    this->font = font;
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(20);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

Button::~Button() {

}

void Button::update(sf::Vector2i mousePosition) {

    this->buttonState = BUTTON_IDLE;
    if(this->shape.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        this->buttonState = BUTTON_HOVER;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = BUTTON_PRESSED;
        }
    }

    switch (this->buttonState)
    {
        case BUTTON_IDLE:
            this->shape.setFillColor(this->idleColor);
            break;
        case BUTTON_HOVER:
            this->shape.setFillColor(this->hoverColor);
            break;
        case BUTTON_PRESSED:
            this->shape.setFillColor(this->activeColor);
            break;
        
        default:
            this->shape.setFillColor(this->idleColor);
            break;
    }

}

bool Button::isPressed() {
    return buttonState == BUTTON_PRESSED;
}

void Button::draw(sf::RenderTarget& window) {
    window.draw(shape);
    window.draw(text);
}

