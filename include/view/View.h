#include <SFML/Graphics.hpp>
#include <vector>

#ifndef VIEW_H
#define VIEW_H



class View {
    protected: 
        sf::RenderWindow* window;
        std::vector<sf::Sprite> itemsToDraw;
        
    public:
        View(sf::RenderWindow*);
        virtual void draw();
        virtual void update();
        std::vector<sf::Sprite>& getEntities();
};

#endif