#include "SceneController.h"
#include "GameView.h"
#include "Game.h"

#ifndef GAME_SCENE_CONTROLLER_H
#define GAME_SCENE_CONTROLLER_H

class GameSceneController: public SceneController {
    private:
        sf::RenderWindow* window;
        Game* game;
        GameView* view;

    public:
        GameSceneController(sf::RenderWindow*);
        ~GameSceneController();
        State run() override;
};

#endif