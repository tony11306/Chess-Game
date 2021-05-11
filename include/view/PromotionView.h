#ifndef PROMITION_VIEW
#define PROMOTION_VIEW

#include "SFML/Graphics.hpp"

class PromotionView {

    private:

        sf::RenderWindow& mainWindow;
        bool isWhiteTurn;

        sf::Sprite rook;
        sf::Sprite bishop;
        sf::Sprite queen;
        sf::Sprite knight;

        sf::Texture ROOK_TEXTURE;
        sf::Texture BISHOP_TEXTURE;
        sf::Texture QUEEN_TEXTURE;
        sf::Texture KNIGHT_TEXTURE;
        sf::Text title;
        sf::RectangleShape background;

        sf::Font font;
        

    public:

        PromotionView(sf::RenderWindow& window, bool isWhiteTurn);
        void draw();
        bool isMouseOnRook(sf::Vector2i mousePosition);
        bool isMouseOnBiship(sf::Vector2i mousePosition);
        bool isMouseOnQueen(sf::Vector2i mousePosition);
        bool isMouseOnKnight(sf::Vector2i mousePosition);
        void update();

};


#endif


