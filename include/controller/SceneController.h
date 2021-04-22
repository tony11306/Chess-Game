#include <SFML/Graphics.hpp>
#ifndef SCENE_CONTROLLER_H
#define SCENE_CONTROLLER_H

enum State {

    MENU_SCENE = 0,
    GAME_SCENE = 1,
    EXIT = -1

};

enum GameState {

    UNINITIALIZED = 0,
    READY_TO_START = 1,
    RUNNING = 2,
    GAME_OVER = 3,
    EXITING = -1

};

class SceneController {

    protected:

        SceneController();

    public:

        virtual State run() = 0;

};


#endif