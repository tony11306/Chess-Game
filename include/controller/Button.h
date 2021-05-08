#include <SFML\Graphics.hpp>


enum ButtonState {
    BUTTON_PRESSED = 0,
    BUTTON_HOVER = 1,
    BUTTON_IDLE = 2
};

class Button {

    private:

        ButtonState buttonState;

        bool isHover;

        sf::RectangleShape shape;
        sf::Font font;
        sf::Text text;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

    public:

        Button(float x, float y, float width, float height, sf::Font& font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
        ~Button();
        void update(sf::Vector2i mousePosition);
        void draw(sf::RenderTarget& window);
        bool isPressed();

};