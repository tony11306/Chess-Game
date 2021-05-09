#include "Game.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

const float PIECE_HORIZONTAL_GAP = 95.5;
const float PIECE_VERTICAL_GAP = 95.5;


class GameView {
    private:
        Game* game;

        sf::RenderWindow& mainWindow;
        sf::Texture BLACK_KING_TEXTURE;
        sf::Texture BLACK_QUEEN_TEXTURE;
        sf::Texture BLACK_BISHOP_TEXTURE;
        sf::Texture BLACK_KNIGHT_TEXTURE;
        sf::Texture BLACK_ROOK_TEXTURE;
        sf::Texture BLACK_PAWN_TEXTURE;

        sf::Texture WHITE_KING_TEXTURE;
        sf::Texture WHITE_QUEEN_TEXTURE;
        sf::Texture WHITE_BISHOP_TEXTURE;
        sf::Texture WHITE_KNIGHT_TEXTURE;
        sf::Texture WHITE_ROOK_TEXTURE;
        sf::Texture WHITE_PAWN_TEXTURE;

        sf::Font font;
        sf::Text playerTurnText;
        sf::Text whiteWinText;
        sf::Text blackWinText;
        sf::Text stalemateText;

        sf::CircleShape moveHint;

        sf::Texture BOARD_TEXTURE;
        sf::Sprite boardSprite;

        std::vector<MoveData> possibleMoves;
        std::vector<sf::Sprite> pieceSprites;
        Button* resetButton;

        bool isWhiteWinTextVisible;
        bool isBlackWinTextVisible;
        bool isStalemateTextVisible;
        

    public:


        GameView(sf::RenderWindow&, Game*);
        ~GameView();
        void update();
        void draw();
        void setPossibleMoves(std::vector<MoveData>& possibleMoves);
        std::vector<sf::Sprite>& getPieceSprites();
        Button* getResetButton();
        void setWhiteWinTextVisible(bool isVisible);
        void setBlackWinTextVisible(bool isVisible);
        void setStalemateTextVisible(bool isVisible);
};

#endif