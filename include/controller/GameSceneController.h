#include "SceneController.h"
#include "GameView.h"
#include "Game.h"

#ifndef GAME_SCENE_CONTROLLER_H
#define GAME_SCENE_CONTROLLER_H

class GameSceneController: public SceneController {

    private:

        sf::RenderWindow& mainWindow;
        Game* game;
        GameView* view;
        GameState gameState;

        bool isDragging;
        int draggingPieceIndex;
        int dragFromX;
        int dragFromY;
        int dragToX;
        int dragToY;


        void handleEvents();
        
    public:

        GameSceneController(sf::RenderWindow&);
        ~GameSceneController();
        State run() override;
        void init();
        void onClosedWindow();
        void onMouseButtonPressed(sf::Event event);
        void onMouseButtonReleased(sf::Event event);

};

#endif