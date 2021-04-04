#include <SFML/Graphics.hpp>
#ifndef SCENE_CONTROLLER_H
#define SCENE_CONTROLLER_H

enum State {
    MENU_SCENE = 0,
    GAME_SCENE = 1,
    EXIT = -1
};

class SceneController {
    protected:
        SceneController();
    public:
        virtual State run() = 0;
};


#endif