#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

const float PIECE_HORIZONTAL_GAP = 95.5;
const float PIECE_VERTICAL_GAP = 95.5;


class GameView {
    private: 
        Game* game;
        sf::RenderWindow* window;
        std::vector<sf::Sprite> pieceEntities;

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

        sf::Texture BOARD;
        

    public:

        GameView(sf::RenderWindow*, Game*);
        ~GameView();
        void draw();
        void update();
        std::vector<sf::Sprite>& getEntities();
};

#endif