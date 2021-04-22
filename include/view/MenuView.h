#include <SFML/Graphics.hpp>
#include <vector>

#ifndef MENU_VIEW_H
#define MENU_VIEW_H



class MenuView {
    private: 
        sf::RenderWindow* window;
        std::vector<sf::Sprite> buttonEntities;
        sf::Texture button;
        sf::Texture background;
        

    public:

        MenuView(sf::RenderWindow*);
        ~MenuView();
        void draw();
        void update();
        std::vector<sf::Sprite>& getEntities();
};

#endif