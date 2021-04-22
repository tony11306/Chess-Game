#include "SceneController.h"
#ifndef MENU_SCENE_CONTROLLER_H
#define MENU_SCENE_CONTROLLER_H

class MenuSceneController: public SceneController {

    private:
        sf::RenderWindow* window;


    public:
        MenuSceneController(sf::RenderWindow*);
        State run() override;
};


#endif