#include <SFML/Graphics.hpp>
#include <vector>

#ifndef VIEW_H
#define VIEW_H



class View {
    protected: 
        sf::RenderWindow& mainWindow;
        std::vector<sf::Sprite> itemsToDraw;
        
    public:
        View(sf::RenderWindow&);
        virtual ~View();
        virtual void draw();
        virtual void update() = 0;
        std::vector<sf::Sprite>& getEntities();
};

#endif